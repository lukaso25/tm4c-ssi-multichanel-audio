#ifndef __AudioADDAControl_H__
#define __AudioADDAControl_H__

#include <stdbool.h>
#include <stdint.h>

/*!
 * \defgroup AudioADDAControl  AudioADDAControl Module
 * @{
 * \brief This is generic module for control of audio ADC and DAC on different platform
 * \author Lukas Otava
 * \date 01.2016
 * \version 0.5
 *
 * This module contains functions for controlling master clocks, gains, output attenuation etc.
 *
 */


/*! Public variable holding actual sample rate in Hz. */
extern uint32_t actual_samplerate;

/*!
 * This function provide communication interface initialization, GPIO init, hard reset - possibly chips are put into reset state
 * After this function, AudioADDAMode...() function must be called.
 * */
uint16_t AudioADDAControlInit( void);


/*! This function initialize mode of PCM signal path  */
uint32_t AudioADDAModePCM( uint32_t mode);

/*! This function initialize mode of DSD signal path */
uint32_t AudioADDAModeDSD( uint32_t mode);


/*!
 * This function changes sample rate.
 * \return Returns sample rate in Hz or 0 if unsupported.
 * */
uint32_t AudioADDASetSampleRate( uint32_t rate );

/*! This function sets AD1871 PGA gain.
 * \param channel channel index
 * \param gain Gain in 8.8 fractional format, according usb standard
 *  */
void AudioADDASetInputGain( uint8_t channel, int16_t gain);

/*! This function sets output attenuation
 * \param channel channel index
 * \param atten output attenuation in 8.8 fractional format, according usb standard
 *  */
void AudioADDASetOutputAttenuation( uint8_t channel, int16_t atten);


/*! @} */
#endif//__AudioADDAControl_H__
