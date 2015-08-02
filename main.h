/*
 * main.h
 *
 *  Created on: 7.7.2015
 *      Author: Lukas
 */

#ifndef MAIN_H_
#define MAIN_H_

/*
 *
 * DK-TM4C123G USB :
 * - PL6,7 D+/-
 * - PB0 identifikator
 * - PB1 Vbus voltage
 * - PG4 USBPGEN
 * - PG5 overcurrent
 *
 * USBADDA:
 * PD4,5 D+/-
 * PB0
 * PB1
 *
 * */


/*
 * Aardvark Q10 notes
 * - FSS pin working properly
 * - SSI2 interrupt is not occurring
 *
 *
 * */

#include "third_party/fatfs/src/ff.h"
#include "third_party/fatfs/src/diskio.h"

#include "wavfile.h"
#include "SSIAudio.h"
#include "AnalogADDA.h"

tWavFile myWav;
//unsigned char audiobuffer[400];
volatile uint8_t playback;
volatile uint8_t underflow;

/* playback buffer */

// dìlitelné 3, 4, 6, 18, 24
#define SSI_PLAY_BUFFER_SIZE (16800)
volatile uint8_t SSIPlayDataValid;
volatile uint32_t SSIPlayReadIndex;
volatile uint32_t SSIPlayWriteIndex;
uint8_t SSIPlayBuff[SSI_PLAY_BUFFER_SIZE];

uint8_t vzorky24;



#endif /* MAIN_H_ */
