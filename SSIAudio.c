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


/* XOR control pin position USBADDA*/
#define SSI_XOR_PIN	GPIO_PIN_7
#define SSI_XOR_PORT GPIO_PORTD_BASE
#define SSI_XOR_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOD

/* XOR control pin position Aardvark */
/*#define SSI_XOR_PIN	GPIO_PIN_4
#define SSI_XOR_PORT GPIO_PORTF_BASE
#define SSI_XOR_PORT_SYSCTRL	SYSCTL_PERIPH_GPIOF*/


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
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2);

    // LRCLK->FSS control GPIO out pin
    SysCtlPeripheralEnable(SSI_XOR_PORT_SYSCTRL);
    GPIOPinTypeGPIOOutput(SSI_XOR_PORT, SSI_XOR_PIN);

    // LRclk: 0 - right ch, 1 - left ch
    // pokud bude zapnute, xor bude invertovat -> left bude použit pro SPI transfer
    // zapneme invert, první vzorek pøijde levý kanál
    GPIOPinWrite(SSI_XOR_PORT, SSI_XOR_PIN, SSI_XOR_PIN); //
    SSI_fss_invert = 0; // next state after first interrupt


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

    /* SSI3 initialization */
	#if SSIAUDIO_CHANNELS > 2
		// another channels
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

		SSIConfigSetExpClk(SSI3_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI3_BASE);
		while(SSIDataGetNonBlocking(SSI3_BASE, &temp)){};
	#endif

	/* SSI0 & SSI1 */
	#if SSIAUDIO_CHANNELS == 8
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);

		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

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

		SSIConfigSetExpClk(SSI0_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI0_BASE);
		while(SSIDataGetNonBlocking(SSI0_BASE, &temp)){};
		SSIConfigSetExpClk(SSI1_BASE, clock, SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, SSIclk, 8);
		SSIEnable(SSI1_BASE);
		while(SSIDataGetNonBlocking(SSI1_BASE, &temp)){};
	#endif

    // interrupt from the first SSI
    SSIIntEnable(SSI2_BASE, SSI_RXFF);

    //int32_t prio;
    //prio = IntPriorityGet(INT_SSI2_TM4C123);

    IntEnable(INT_SSI2_TM4C123);
}

void SSIAudioIntEnable( void)
{
}

void SSIAudioIntDisable ( void)
{

}

void SSI2_IRQHandler( void)
{

	HWREG(GPIO_PORTB_BASE + (GPIO_O_DATA + (GPIO_PIN_2 << 2))) = GPIO_PIN_2;
	HWREG(SSI_XOR_PORT + (GPIO_O_DATA + (SSI_XOR_PIN << 2))) = SSI_fss_invert;

	//TODO: kde je problém s pøehozením kanálù? strana ardvark nebo SSI?

	// SSI transmit buffers
	if (SSI_fss_invert)
	{
		// pøíští transfer bude pro levý kanál
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.msb;//SSIdataP[2];
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.csb;//SSIdataP[1];
		HWREG(SSI2_BASE + SSI_O_DR) = SSIPlaySamples[0].bytes.lsb;//SSIdataP[0];

		#if SSIAUDIO_CHANNELS > 2
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.msb;//SSIdataP[2];
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.csb;//SSIdataP[1];
			HWREG(SSI3_BASE + SSI_O_DR) = SSIPlaySamples[2].bytes.lsb;//SSIdataP[0];
		#endif

		#if SSIAUDIO_CHANNELS == 8
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

		#if SSIAUDIO_CHANNELS > 2
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.msb;//SSIdataP[5];
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.csb;//SSIdataP[4];
			HWREG(SSI3_BASE + SSI_O_DR) =  SSIPlaySamples[3].bytes.lsb;//SSIdataP[3];
		#endif
		#if SSIAUDIO_CHANNELS == 8
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

		#if SSIAUDIO_CHANNELS > 2
			SSIRecSamples[2].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // L-LSB SSIdataR[0] =
			SSIRecSamples[2].bytes.csb = SSItemp[5]; //SSIdataR[1]
			SSIRecSamples[2].bytes.msb = SSItemp[4]; //SSIdataR[2]
			SSItemp[6] = HWREG(SSI3_BASE + SSI_O_DR); // R-MSB
			SSItemp[7] = HWREG(SSI3_BASE + SSI_O_DR); // R
		#endif
		#if SSIAUDIO_CHANNELS == 8
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

		#if SSIAUDIO_CHANNELS > 2
			SSIRecSamples[3].bytes.lsb = HWREG(SSI3_BASE + SSI_O_DR); // R-LSB SSIdataR[3] =
			SSIRecSamples[3].bytes.csb = SSItemp[7];
			SSIRecSamples[3].bytes.msb = SSItemp[6];
			SSItemp[4] = HWREG(SSI3_BASE + SSI_O_DR); // L-MSB
			SSItemp[5] = HWREG(SSI3_BASE + SSI_O_DR); // L
		#endif
		#if SSIAUDIO_CHANNELS == 8
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
		// playing
		/*if (SSIPlayDataValid && ( dacAltMode != 0 ) ) // zbyteèné?
		{
			if (dacAltMode == 1)
			{
				// 16 bit stereo
				SSIdataP[0] = 0;
				SSIdataP[1] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[2] = SSIPlayBuff[SSIPlayReadIndex++];



				SSIdataP[3] = 0;
				SSIdataP[4] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[5] = SSIPlayBuff[SSIPlayReadIndex++];



			}

			if (dacAltMode == 2)
			{
				// 24 bit stereo
				SSIdataP[0] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[1] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[2] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[3] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[4] = SSIPlayBuff[SSIPlayReadIndex++];
				SSIdataP[5] = SSIPlayBuff[SSIPlayReadIndex++];

			}

			if (SSIPlayReadIndex >= SSI_PLAY_BUFFER_SIZE)
			{
				SSIBuffErrorFlag = 1;
				SSIPlayReadIndex = 0;
			}
		}
		else
		{
			uint8_t i;
			for (i = 0; i< 6; i++ )
			{
				SSIdataP[i] = 0;
			}
		}*/

		// todo: co dìlá toto, když se netrefíme do poètu bytù??
		/*if (SSIRecordIndex >= (BUFFER_SIZE_R-(3*2)))
		{
			SSIRecordIndex = 0;
			buffer_id = 1;
		}*/


		/* recording */
		//if (adcAltMode>0)
		/*{
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[0];
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[1];
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[2];
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[3];
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[4];
			SSIRecordBuff[SSIRecordIndex++] = SSIdataR[5];
		}*/
	}
	HWREG(GPIO_PORTB_BASE + (GPIO_O_DATA + (GPIO_PIN_2 << 2))) = 0;
}

