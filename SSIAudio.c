#include "SSIAudio.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ssi.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/ssi.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"


#if (SSIAUDIO_CHANNELS == 2)
/* DEBUG pin position USBADDA*/
#define SSI_DEBUG_PIN	GPIO_PIN_2
#define SSI_DEBUG_PORT GPIO_PORTB_BASE
#define SSI_DEBUG_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOB

/* XOR control pin position USBADDA*/
#define SSI_XOR_PIN	GPIO_PIN_7
#define SSI_XOR_PORT GPIO_PORTD_BASE
#define SSI_XOR_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOD
#endif

#if (SSIAUDIO_CHANNELS == 4)
/* DEBUG pin position ADAU1772/1372*/
#define SSI_DEBUG_PIN	GPIO_PIN_3
#define SSI_DEBUG_PORT GPIO_PORTA_BASE
#define SSI_DEBUG_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOA

/* XOR control pin position ADAU1772/1372 */
#define SSI_XOR_PIN	GPIO_PIN_2
#define SSI_XOR_PORT GPIO_PORTA_BASE
#define SSI_XOR_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOA
#endif

#if (SSIAUDIO_CHANNELS == 8)
/* XOR control pin position Aardvark */
#define SSI_XOR_PIN	GPIO_PIN_4
#define SSI_XOR_PORT GPIO_PORTF_BASE
#define SSI_XOR_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOF
#endif


/* sample buffer for playback */
union SSISample SSIPlaySamples [SSIAUDIO_CHANNELS];

/* sample buffer for record */
union SSISample SSIRecSamples [SSIAUDIO_CHANNELS];


/*  LR_CLK low to HIGH transition means left channel (AD1871, AKM4524 too),
 * 	SSI starts operation on   */

// private data
volatile uint8_t SSI_fss_invert = SSI_XOR_PIN;

// Feedback
/*! public variable representing */
volatile uint32_t SSISamplesWritten;

// rec
int8_t SSItemp[SSIAUDIO_CHANNELS*2];


void SSIAudioInit( void)
{
	//temporary var
	uint32_t temp;

    uint32_t clock = SysCtlClockGet();
    uint32_t SSIclk = 20000000;// pozor, víc nefunguje

    // debug pin init
	SysCtlPeripheralEnable(SSI_DEBUG_PORT_SYSCTRL);
	GPIOPinTypeGPIOOutput(SSI_DEBUG_PORT, SSI_DEBUG_PIN);

    // LRCLK->FSS control GPIO out pin
    SysCtlPeripheralEnable(SSI_XOR_PORT_SYSCTRL);
    GPIOPinTypeGPIOOutput(SSI_XOR_PORT, SSI_XOR_PIN);

    // LRclk: 0 - right ch, 1 - left ch
    // pokud bude zapnute, xor bude invertovat -> left bude použit pro SPI transfer
    // zapneme invert, první vzorek pøijde levý kanál
    GPIOPinWrite(SSI_XOR_PORT, SSI_XOR_PIN, SSI_XOR_PIN); //
    SSI_fss_invert = 0; // next state after first interrupt

    /* SSI2 */
	#if (SSIAUDIO_CHANNELS==2)
		// The SSI peripheral must be enabled for use.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
		// GPIO peripheral clock enable
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		// GPIO connection
		GPIOPinConfigure(GPIO_PB4_SSI2CLK);
		GPIOPinConfigure(GPIO_PB5_SSI2FSS);
		GPIOPinConfigure(GPIO_PB6_SSI2RX);
		GPIOPinConfigure(GPIO_PB7_SSI2TX);
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_4 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_5 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_6 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_7 );

		// Clock configuration
		SSIConfigSetExpClk(SSI2_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		// Enable the each SSI module.
		SSIEnable(SSI2_BASE);
		// flushing receive FIFO
		while(SSIDataGetNonBlocking(SSI2_BASE, &temp)){};

	    // interrupt from the first SSI
	    SSIIntEnable(SSI2_BASE, SSI_RXFF);

	    //int32_t prio;
	    //prio = IntPriorityGet(INT_SSI2_TM4C123);

	    IntEnable(INT_SSI2_TM4C123);
	#endif

    /* SSI1 and SSI3 initialization */
	#if (SSIAUDIO_CHANNELS == 4)

	    // The SSI peripheral must be enabled for use.
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
	    // GPIO peripheral clock enable
	    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

		GPIOPinConfigure(GPIO_PF2_SSI1CLK);
		GPIOPinConfigure(GPIO_PF3_SSI1FSS);
		GPIOPinConfigure(GPIO_PF0_SSI1RX);
		GPIOPinConfigure(GPIO_PF1_SSI1TX);
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_2 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_3 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_0 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_1 );

		GPIOPinConfigure(GPIO_PD0_SSI3CLK);
		GPIOPinConfigure(GPIO_PD1_SSI3FSS);
		GPIOPinConfigure(GPIO_PD2_SSI3RX);
		GPIOPinConfigure(GPIO_PD3_SSI3TX);
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_1 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_2 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_3 );

		SSIConfigSetExpClk(SSI1_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI1_BASE);
		while(SSIDataGetNonBlocking(SSI1_BASE, &temp)){};

		SSIConfigSetExpClk(SSI3_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI3_BASE);
		while(SSIDataGetNonBlocking(SSI3_BASE, &temp)){};

		// interrupt from the first SSI
		SSIIntEnable(SSI1_BASE, SSI_RXFF);

		//int32_t prio;
		//prio = IntPriorityGet(INT_SSI2_TM4C123);

		IntEnable(INT_SSI1_TM4C123);
	#endif

	/* SSI0 & SSI1 & SSI2 & SSI3 */
	#if (SSIAUDIO_CHANNELS == 8)
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);

		// GPIO peripheral clock enable
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

		GPIOPinConfigure(GPIO_PA2_SSI0CLK);
		GPIOPinConfigure(GPIO_PA3_SSI0FSS);
		GPIOPinConfigure(GPIO_PA4_SSI0RX);
		GPIOPinConfigure(GPIO_PA5_SSI0TX);
		GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2 );
		GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_3 );
		GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_4 );
		GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 );

		GPIOPinConfigure(GPIO_PF2_SSI1CLK);
		GPIOPinConfigure(GPIO_PF3_SSI1FSS);
		GPIOPinConfigure(GPIO_PF0_SSI1RX);
		GPIOPinConfigure(GPIO_PF1_SSI1TX);
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_2 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_3 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_0 );
		GPIOPinTypeSSI(GPIO_PORTF_BASE, GPIO_PIN_1 );

		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB4_SSI2CLK);
		GPIOPinConfigure(GPIO_PB5_SSI2FSS);
		GPIOPinConfigure(GPIO_PB6_SSI2RX);
		GPIOPinConfigure(GPIO_PB7_SSI2TX);
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_4 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_5 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_6 );
		GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_7 );

		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
		GPIOPinConfigure(GPIO_PD0_SSI3CLK);
		GPIOPinConfigure(GPIO_PD1_SSI3FSS);
		GPIOPinConfigure(GPIO_PD2_SSI3RX);
		GPIOPinConfigure(GPIO_PD3_SSI3TX);
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_1 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_2 );
		GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_3 );


		SSIConfigSetExpClk(SSI0_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI0_BASE);
		while(SSIDataGetNonBlocking(SSI0_BASE, &temp)){};
		SSIConfigSetExpClk(SSI1_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI1_BASE);
		while(SSIDataGetNonBlocking(SSI1_BASE, &temp)){};
		SSIConfigSetExpClk(SSI2_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI2_BASE);
		while(SSIDataGetNonBlocking(SSI2_BASE, &temp)){};
		SSIConfigSetExpClk(SSI3_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI3_BASE);
		while(SSIDataGetNonBlocking(SSI3_BASE, &temp)){};

	    // interrupt from the first SSI
	    SSIIntEnable(SSI2_BASE, SSI_RXFF);

	    //int32_t prio;
	    //prio = IntPriorityGet(INT_SSI2_TM4C123);

	    IntEnable(INT_SSI2_TM4C123);
	#endif
}

void SSIAudioIntEnable( void)
{
}

void SSIAudioIntDisable ( void)
{

}

#if (SSIAUDIO_CHANNELS == 2 || SSIAUDIO_CHANNELS == 8)
void SSI2_IRQHandler( void)
{

	HWREG(SSI_DEBUG_PORT + (GPIO_O_DATA + (SSI_DEBUG_PIN << 2))) = SSI_DEBUG_PIN;
	HWREG(SSI_XOR_PORT + (GPIO_O_DATA + (SSI_XOR_PIN << 2))) = SSI_fss_invert;

	//TODO: kde je problém s pøehozením kanálù? strana ardvark nebo SSI?

	// SSI transmit buffers
	if (SSI_fss_invert)
	{
		// pøíští transfer bude pro levý kanál
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.msb;//SSIdataP[2];
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.csb;//SSIdataP[1];
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.lsb;//SSIdataP[0];

		#if SSIAUDIO_CHANNELS == 8
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.msb;//SSIdataP[2];
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.csb;//SSIdataP[1];
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.lsb;//SSIdataP[0];
			HWREG(SSI0_BASE + SSI_O_DR) = SSIPlaySamples[4].bytes.msb;//SSIdataP[2];
			HWREG(SSI0_BASE + SSI_O_DR) = SSIPlaySamples[4].bytes.csb;//SSIdataP[1];
			HWREG(SSI0_BASE + SSI_O_DR) = SSIPlaySamples[4].bytes.lsb;//SSIdataP[0];
			HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[6].bytes.msb;//SSIdataP[2];
			HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[6].bytes.csb;//SSIdataP[1];
			HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[6].bytes.lsb;//SSIdataP[0];
		#endif

	}
	else
	{
		// pøíští transfer bude pro  kanál
		HWREG(SSI2_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.msb;//SSIdataP[5];
		HWREG(SSI2_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.csb;//SSIdataP[4];
		HWREG(SSI2_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.lsb;//SSIdataP[3];

		#if SSIAUDIO_CHANNELS == 8
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.msb;//SSIdataP[5];
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.csb;//SSIdataP[4];
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.lsb;//SSIdataP[3];
			HWREG(SSI0_BASE + SSI_O_DR) =  SSIPlaySamples[5].bytes.msb;//SSIdataP[5];
			HWREG(SSI0_BASE + SSI_O_DR) =  SSIPlaySamples[5].bytes.csb;//SSIdataP[4];
			HWREG(SSI0_BASE + SSI_O_DR) =  SSIPlaySamples[5].bytes.lsb;//SSIdataP[3];
			HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[7].bytes.msb;//SSIdataP[5];
			HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[7].bytes.csb;//SSIdataP[4];
			HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[7].bytes.lsb;//SSIdataP[3];
		#endif
	}

	// SSI receive buffers
	if (SSI_fss_invert)
	{
		// I.
		// pøíští transfer bude pro levý kanál
		// máme výsledek ètení když byl zvolen pravý kanál
		// teï budeme èíst: neprve L minulé-LSB, R-MSB, R
		// zpracujeme levý, protože komplet, dáme ho do zpoždìní
		SSIRecSamples[0].bytes.lsb = HWREG(SSI2_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
		SSIRecSamples[0].bytes.csb = SSItemp[1]; //SSIdataR[1]
		SSIRecSamples[0].bytes.msb = SSItemp[0]; //SSIdataR[2]
		SSItemp[2] = HWREG(SSI2_BASE + SSI_O_DR); // R-MSB
		SSItemp[3] = HWREG(SSI2_BASE + SSI_O_DR); // R

		#if SSIAUDIO_CHANNELS == 8
			SSIRecSamples[2].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
			SSIRecSamples[2].bytes.csb = SSItemp[5]; //SSIdataR[1]
			SSIRecSamples[2].bytes.msb = SSItemp[4]; //SSIdataR[2]
			SSItemp[6] = HWREG(SSI3_BASE + SSI_O_DR); // R-MSB
			SSItemp[7] = HWREG(SSI3_BASE + SSI_O_DR); // R

			SSIRecSamples[2].bytes.lsb = HWREG(SSI0_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
			SSIRecSamples[2].bytes.csb = SSItemp[9]; //SSIdataR[1]
			SSIRecSamples[2].bytes.msb = SSItemp[8]; //SSIdataR[2]
			SSItemp[10] = HWREG(SSI0_BASE + SSI_O_DR); // R-MSB
			SSItemp[11] = HWREG(SSI0_BASE + SSI_O_DR); // R

			SSIRecSamples[2].bytes.lsb = HWREG(SSI1_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
			SSIRecSamples[2].bytes.csb = SSItemp[13]; //SSIdataR[1]
			SSIRecSamples[2].bytes.msb = SSItemp[12]; //SSIdataR[2]
			SSItemp[14] = HWREG(SSI1_BASE + SSI_O_DR); // R-MSB
			SSItemp[15] = HWREG(SSI1_BASE + SSI_O_DR); // R
		#endif
	}
	else
	{
		// II.
		// pøíští transfer bude pro pravý kanál
		// máme výsledek ètení když byl zvolen levý kanál
		SSIRecSamples[1].bytes.lsb = HWREG(SSI2_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
		SSIRecSamples[1].bytes.csb = SSItemp[3];
		SSIRecSamples[1].bytes.msb = SSItemp[2];
		SSItemp[0] = HWREG(SSI2_BASE + SSI_O_DR); // L-MSB
		SSItemp[1] = HWREG(SSI2_BASE + SSI_O_DR); // L

		#if SSIAUDIO_CHANNELS == 8
			SSIRecSamples[3].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
			SSIRecSamples[3].bytes.csb = SSItemp[7];
			SSIRecSamples[3].bytes.msb = SSItemp[6];
			SSItemp[4] = HWREG(SSI3_BASE + SSI_O_DR); // L-MSB
			SSItemp[5] = HWREG(SSI3_BASE + SSI_O_DR); // L

			SSIRecSamples[3].bytes.lsb = HWREG(SSI0_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
			SSIRecSamples[3].bytes.csb = SSItemp[11];
			SSIRecSamples[3].bytes.msb = SSItemp[10];
			SSItemp[8] = HWREG(SSI0_BASE + SSI_O_DR); // L-MSB
			SSItemp[9] = HWREG(SSI0_BASE + SSI_O_DR); // L

			SSIRecSamples[3].bytes.lsb = HWREG(SSI1_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
			SSIRecSamples[3].bytes.csb = SSItemp[15];
			SSIRecSamples[3].bytes.msb = SSItemp[14];
			SSItemp[12] = HWREG(SSI1_BASE + SSI_O_DR); // L-MSB
			SSItemp[13] = HWREG(SSI1_BASE + SSI_O_DR); // L
		#endif
	}

	if (SSI_fss_invert)
	{
		// pøíští transfer bude pro levý kanál
		SSI_fss_invert = 0; // v levém kanálu budeme pøepínat na pravý kanál
		SSISamplesWritten++;
	}
	else
	{
		// pøíští transfer bude pro pravý kanál
		SSI_fss_invert = SSI_XOR_PIN;

#ifdef SSIAUDIO_NEWSAMPLE_CALLBACK
		SSIAudioNewSampleCallback( SSIRecSamples, SSIPlaySamples);
#endif
	}
	HWREG(SSI_DEBUG_PORT + (GPIO_O_DATA + (SSI_DEBUG_PIN << 2))) = 0;
}
#endif

#if SSIAUDIO_CHANNELS == 4
void SSI1_IRQHandler( void)
{

	HWREG(SSI_DEBUG_PORT + (GPIO_O_DATA + (SSI_DEBUG_PIN << 2))) = SSI_DEBUG_PIN;
	HWREG(SSI_XOR_PORT + (GPIO_O_DATA + (SSI_XOR_PIN << 2))) = SSI_fss_invert;

	//TODO: kde je problém s pøehozením kanálù? strana ardvark nebo SSI?

	// SSI transmit buffers
	if (SSI_fss_invert)
	{
		// pøíští transfer bude pro levý kanál
		HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.msb;//SSIdataP[2];
		HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.csb;//SSIdataP[1];
		HWREG(SSI1_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.lsb;//SSIdataP[0];

		HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.msb;//SSIdataP[2];
		HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.csb;//SSIdataP[1];
		HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.lsb;//SSIdataP[0];
	}
	else
	{
		// pøíští transfer bude pro  kanál
		HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.msb;//SSIdataP[5];
		HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.csb;//SSIdataP[4];
		HWREG(SSI1_BASE + SSI_O_DR) =  SSIPlaySamples[1].bytes.lsb;//SSIdataP[3];

		HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.msb;//SSIdataP[5];
		HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.csb;//SSIdataP[4];
		HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.lsb;//SSIdataP[3];
	}

	// SSI receive buffers
	if (SSI_fss_invert)
	{
		// I.
		// pøíští transfer bude pro levý kanál
		// máme výsledek ètení když byl zvolen pravý kanál
		// teï budeme èíst: neprve L minulé-LSB, R-MSB, R
		// zpracujeme levý, protože komplet, dáme ho do zpoždìní
		SSIRecSamples[0].bytes.lsb = HWREG(SSI1_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
		SSIRecSamples[0].bytes.csb = SSItemp[1]; //SSIdataR[1]
		SSIRecSamples[0].bytes.msb = SSItemp[0]; //SSIdataR[2]
		SSItemp[2] = HWREG(SSI1_BASE + SSI_O_DR); // R-MSB
		SSItemp[3] = HWREG(SSI1_BASE + SSI_O_DR); // R


		SSIRecSamples[2].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
		SSIRecSamples[2].bytes.csb = SSItemp[5]; //SSIdataR[1]
		SSIRecSamples[2].bytes.msb = SSItemp[4]; //SSIdataR[2]
		SSItemp[6] = HWREG(SSI3_BASE + SSI_O_DR); // R-MSB
		SSItemp[7] = HWREG(SSI3_BASE + SSI_O_DR); // R
	}
	else
	{
		// II.
		// pøíští transfer bude pro pravý kanál
		// máme výsledek ètení když byl zvolen levý kanál
		SSIRecSamples[1].bytes.lsb = HWREG(SSI1_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
		SSIRecSamples[1].bytes.csb = SSItemp[3];
		SSIRecSamples[1].bytes.msb = SSItemp[2];
		SSItemp[0] = HWREG(SSI1_BASE + SSI_O_DR); // L-MSB
		SSItemp[1] = HWREG(SSI1_BASE + SSI_O_DR); // L

		SSIRecSamples[3].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
		SSIRecSamples[3].bytes.csb = SSItemp[7];
		SSIRecSamples[3].bytes.msb = SSItemp[6];
		SSItemp[4] = HWREG(SSI3_BASE + SSI_O_DR); // L-MSB
		SSItemp[5] = HWREG(SSI3_BASE + SSI_O_DR); // L
	}

	if (SSI_fss_invert)
	{
		// pøíští transfer bude pro levý kanál
		SSI_fss_invert = 0; // v levém kanálu budeme pøepínat na pravý kanál
		SSISamplesWritten++;
	}
	else
	{
		// pøíští transfer bude pro pravý kanál
		SSI_fss_invert = SSI_XOR_PIN;

#ifdef SSIAUDIO_NEWSAMPLE_CALLBACK
		SSIAudioNewSampleCallback( SSIRecSamples, SSIPlaySamples);
#endif
	}
	HWREG(SSI_DEBUG_PORT + (GPIO_O_DATA + (SSI_DEBUG_PIN << 2))) = 0;
}
#endif
