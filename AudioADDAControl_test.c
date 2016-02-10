#include "AudioADDAControl.h"

//TODO: test comments!

int8_t AudioADDAControl_test( void)
{
	AudioADDAControlInit();

	AudioADDAModePCM(0);

	AudioADDASetSampleRate(44100);

	AudioADDASetInputGain(0,0);
	AudioADDASetInputGain(1,0);

	AudioADDASetOutputAttenuation(0,0);
	AudioADDASetOutputAttenuation(1,0);


	return (0);
}
