#ifndef __SSIAUDIO_H__
#define __SSIAUDIO_H__

/*!
 * \defgroup SSIAudio SSIAudio
 * @{
 * \brief	This Module contain procedures for utilizing SSI peripherals as I2S (left-justified) slave audio device only with one external XOR gate.
 * \author 	Lukas Otava
 * \date 	2015
 * \version 0.1
 *
 * \warning This module is time critical, optimization should be used
 *
 * \warning Some pins with default NMI should be unlocked for alternative pin function
 *
 *
 * */

#include <stdbool.h>
#include <stdint.h>

/* this could be 2/4/8 with fixed mapping */
#define SSIAUDIO_CHANNELS (2)


/* structure definition for byte oriented SSI data transfers of samples */
struct SSIAudioSampleStruct
{
	uint8_t empty;
	uint8_t lsb, csb, msb;
};

/* this union provide effective way to manipulate witch samples */
union SSISample
{
	struct SSIAudioSampleStruct bytes;
	int32_t sample;
};

/* sample buffer for playback */
union SSISample SSIPlaySamples [SSIAUDIO_CHANNELS];

/* sample buffer for record */
union SSISample SSIRecSamples [SSIAUDIO_CHANNELS];

// public functions

/*! SSIAudio module initialization function
 *
 *	example usage:
 *	\code
 *	...
 *	// now initialize SSI audio module
 *	SSIAudioInit( );
 *	...
 *	\endcode
 *
 * */
void SSIAudioInit( void);

/*!
 *
 *
 *  */
/*uint8_t SSIAudioIsNewSample( void);*/

/*!
 *
 *  \ref SSIAudioNewSampleCallback
 *
 * */
#define SSIAUDIO_NEWSAMPLE_CALLBACK

/*! new sample callback */
extern void SSIAudioNewSampleCallback( union SSISample record[], union SSISample playback[]);

/*! @}*/
#endif//__SSIAUDIO_H__
