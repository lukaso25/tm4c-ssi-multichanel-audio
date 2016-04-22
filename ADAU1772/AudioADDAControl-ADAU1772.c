#include "AudioADDAControl.h"

uint16_t AnalogADDAControlInit( void)
{
	
	

	return (0);

}

uint32_t AudioADDAModePCM( uint32_t mode)
{
	return (-1);
}


uint32_t AnalogADDASetSampleRate( uint32_t rate )
{
	if (rate == AudioADDACsamplerate)
	{
		return (rate);
	}
	else
	{
		AudioADDACsamplerate = rate;
	}
	
	
	switch (rate)
	{
	case 44100:
		break;
	case 88200:
		break;
	case 48000:
		break;
	case 96000:
		break;
	default:
		AudioADDACsamplerate = 0;
		break;
	}
	
	return (AudioADDACsamplerate);
}

void AudioADDASetInputGain( uint8_t channel, int16_t gain)
{
	return;
}

void AudioADDASetOutputAttenuation( uint8_t channel, int16_t atten)
{
	return;
}
