#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include <driverlib/gpio.h>
#include <driverlib/sysctl.h>
//#define TARGET_IS_TM4C123_RB1
//#include <driverlib/rom.h>

#include "tm4c_cmsis.h"


#include "SSIAudio.h"



//BiquadInstance peak, peak2;

void SSIAudioNewSampleCallback( union SSISample record[], union SSISample playback[])
{

	// normalization of inputs
	//(left justified -> right justified 24 bit in 32 bit number -> better for signal processing)
	record[0].sample >>= 8;
	record[1].sample >>= 8;



	// go through
	playback[0].sample =  record[0].sample;
	playback[1].sample =  record[1].sample;

	playback[2].sample =  record[2].sample;
	playback[3].sample =  record[3].sample;

	playback[4].sample =  record[4].sample;
	playback[5].sample =  record[5].sample;

	playback[6].sample =  record[6].sample;
	playback[7].sample =  record[7].sample;


	//EQ filtering
	/*BiquadFiler(record[0].sample,&record[0].sample,&peak);
	BiquadFiler(record[1].sample,&record[1].sample,&peak2);*/

	// stereo width matrix
	/*
	 *
	 * */

	//Prologic decoder
	/*
	 *
	 * */

	//down-mix
	/*
	playback[0].sample = (record[0].sample) + (record[1].sample);
	playback[0].sample = __SSAT(playback[0].sample, 24);
	playback[1].sample = playback[0].sample;*/


	// saturation and normalization of output
	// (right justified -> left justified 24 bit in 32 bit number)
	playback[0].sample = __SSAT(record[0].sample, 24)<<8;
	playback[1].sample = __SSAT(record[1].sample, 24)<<8;



}

void SystemInit( void);
void SysTick_Handler(void);

int main( void)
{

	SystemInit();


	SSIAudioInit();

	while(1);
	return (0);
}


void SystemInit( void)
{
	uint32_t returnCode;

	SysCtlClockSet(SYSCTL_SYSDIV_3 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ );
	//returnCode = SysCtlClockFreqSet(SYSCTL_OSC_MAIN | SYSCTL_CFG_VCO_480 ,80000000);
	uint32_t clock = SysCtlClockGet();

	//clock = clock;

	// todo: po nastavení zase zamknout?
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;

	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;

	returnCode = SysTick_Config(60000000/1000);      /* Configure SysTick to generate an interrupt every millisecond */

	if (returnCode != 0)
	{                                   /* Check return code for errors */
		// Error Handling
	}
}

uint32_t msTicks = 0;                                       /* Variable to store millisecond ticks */

/*void SysTick_Handler(void)
{
SysTick interrupt Handler. See startup file startup_LPC17xx.s for SysTick vector
	msTicks++;
}*/
