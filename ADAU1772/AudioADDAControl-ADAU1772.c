/*
 *
 * PINOUT:
 *

LRCLK XOR control PA2
FSS PF3 PD1
BCLK PF2 PD0
DAC PF1
ADC0 PD2
ADC1 PF0

#PD PB2
I2C1 SCL PA6
I2C1 SDA PA7

 *
 *
 * */

// generic audio interface
#include "AudioADDAControl.h"


// Stellaris
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#include <driverlib/rom.h>


void I2C_1772_burst( uint8_t I2Cadr, uint16_t adr, uint16_t length, uint8_t * data);

#define ADAU1772_I2S_SAMPLERATE		(44100)
#define ADAU1772_I2C_SLAVE_ADDRESS  (0x3C)
#define ADAU1772_I2C_BASE I2C1_BASE


// header from sigma studio
#include "sigmaDSP1772_IC_1.h"


void I2C_1772_burst( uint8_t I2Cadr, uint16_t adr, uint16_t length, uint8_t * data)
{
	uint16_t i = 0;
	//uint16_t timeout;

	if (length < 1)
	{
		return;
	}

	// Sigma Studio code workaround
	//I2CMasterSlaveAddrSet(ADAU1772_I2C_BASE, I2Cadr, false);
	I2CMasterSlaveAddrSet(ADAU1772_I2C_BASE, ADAU1772_I2C_SLAVE_ADDRESS, false);

	//I2C start
	//byte adress
	I2CMasterDataPut(ADAU1772_I2C_BASE, (adr>>8));
	I2CMasterControl(ADAU1772_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
	while(I2CMasterBusy(ADAU1772_I2C_BASE));

	I2CMasterDataPut(ADAU1772_I2C_BASE, (adr&0xFF));
	I2CMasterControl(ADAU1772_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
	while(I2CMasterBusy(ADAU1772_I2C_BASE));

	// data bytes
	for (i = 0; i < (length-1); i++)
	{
		// Place the data to be sent in the data register
		I2CMasterDataPut(ADAU1772_I2C_BASE, data[i]);
		I2CMasterControl(ADAU1772_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
		while(I2CMasterBusy(ADAU1772_I2C_BASE));
	}

	I2CMasterDataPut(ADAU1772_I2C_BASE, data[i]);
	I2CMasterControl(ADAU1772_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
	while(I2CMasterBusy(ADAU1772_I2C_BASE));
}


uint16_t AudioADDAControlInit( void)
{
	
	// I2C1 peripheral init for ADAU1772
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	GPIOPinConfigure(GPIO_PA6_I2C1SCL);
	GPIOPinConfigure(GPIO_PA7_I2C1SDA);

	GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
	GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);
	
	I2CMasterInitExpClk(ADAU1772_I2C_BASE, SysCtlClockGet(), false);

	// PD pin configuration
	// PD ~ powerdown - output - low
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
	return (0);
}

uint32_t AudioADDAModePCM( uint32_t mode)
{

	if (mode == 1)
	{
		// PD = 1
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);

		SysCtlDelay(100000);

		// sigmastudio init
		default_download_IC_1();


	}
	else
	{
		// just  PD = 0
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
	}

	return (mode);
}


uint32_t AudioADDASetSampleRate( uint32_t rate )
{
	
	return (ADAU1772_I2S_SAMPLERATE);
}

void AudioADDASetInputGain( uint8_t channel, int16_t gain)
{
	/*

	uint8_t data;

	data = 0;
	I2C_1772_burst(ADAU1772_I2C_SLAVE_ADDRESS, 0,1, &data);

	*/
	return;
}

void AudioADDASetOutputAttenuation( uint8_t channel, int16_t atten)
{
	/*uint8_t data;

			data = 0;
			I2C_1772_burst(ADAU1772_I2C_SLAVE_ADDRESS, 0,1, &data);

			data = 0;
			I2C_1772_burst(ADAU1772_I2C_SLAVE_ADDRESS, 0,1, &data);
			 */
	return;
}
