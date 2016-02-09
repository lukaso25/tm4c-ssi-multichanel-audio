/*
 * main.h
 *
 *  Created on: 7.7.2015
 *      Author: Lukas
 */

#ifndef MAIN_H_
#define MAIN_H_

//! Project definition related to HW version
#define AD1871_HPF

/*
 *  * problems and todo's
 * -------------------
 *  (czech language only)
 * - p�i 24/96 se sek� zvuk p�i nastavov�n� hlasitosti
 * - implementace ESD, zjistit co se stane, kdy� se v okol� zapne trafo
 * - zkusit nap�jet +5V z extern�ho zdroje
 * - hlasitost jde nastavovat, ale sek� se.... a taky bude si pamatovat PC? zat�m to moc nefunguje :-( ale pro�?
 * - implementace hibernate situace USB, re�imy sn�en� spot�eby
 * - podpora sn�en� spot�eby u kodek�
 * - podpora sn�en� spot�eby u procesoru
 * - indik�tor vstupn� �rovn� -> p�es seriovku t�eba
 * - probl�m s vypadnut�m ze synchronizace - prohozen� byt� pro I2S - ob�as p�ijdou data, kter� nespl�uj� d�lka%po�etbyt�=0
 * - probl�m s p�ep�n�n�m frekvence, pro� a� p�i druh� zm�n� zm�n�
 * - zkontrolovat f�zi v�stup� - osciloskop
 * - Prov�st kontrolu loopbacku p�es I2S ... propojit sdi se sdo ! (kontrola bit accurate)
 * - inteligentn� indikace frekcence, limitace ADC, v�padky
 * - vylep�it feedback, aby byl line�rn�, limity nastavovat podle aktu�ln� frekvence, volba latence, odstran�n� z�vislosti na �asova�i
 * - vstup je pravd�podobn� invertov�n
 * - NMI piny, zase zamknout
 * - p�idat HID rozhrann�
 * - uart MIDI, nebo uart console
 * - opravy k�du, modularizace
 *
 * fixed errors
 * ------------
 * (czech language only)
 * - dal�� alt setting pro z�znam
 * - left and right shifted about 1 sample (left is one sample delayed) - buffery se synchronizuj� mezi lev�m a prav�m kan�lem
 * - pro� se sek�, kdy� h�bu my�� p�i nastaven� nahr�v�n�? - pomal� pos�l�n� po seriovce
 * - I2S recording corrected
 * - v�choz� vzorkova�ku z prom�nn� v AnalogADDA modulu
 * - probl�m nastavov�n� AD1871 a d�li�e - musej� se nastavit oba registry, aby bylo 6.144 do modul�toru, SPI interface vy�aduje MCK b��c�
 * - probl�m pozapnut� - pro� �um - �patn� form�t hodin
 * - chyba zm�ny frekvence nahr�vac�ho endpoitu - endpoint definovan� bez 0x80
 * - chyba nahr�v�n� - �patn� definovan� spatial position
 * - nahodil� v�padky - nep�esn� feedback
 * - 16 bit nejde, pro�? - jenom mal� velikost endpointu
 * - 96 kHz v�stup p�eskakuje - jenom 90*2*3 bytu
 *
 * 	pinout and pin mapping
 * 	---------------------
 *
 * UART ... PA0 PA1 ...
 *
 * Crystals ... PC6 pro 44.1,  PC7
 *
 * ADDA Reset ... PF3
 *
 * SSI Control ... PA2 PA4 PA5 ... SSI0
 *
 *	PA3 AD1871 latch
 *
 *	PA6 AD185x latch
 *
 * Timer LRCLK ... PF0 TIMER0 A
 *
 * LRCLK XOR ... PD7
 *
 * SSI Audio ... PB4 PB5 PB6 PB7 .. SSI2
 *
 * LED1 ... PB3 PD6
 *
 * LED2 ... PB2
 *
 * IO konektor ...
 * - 1	PD2
 * - 2	VDD
 * - 3	PD0
 * - 4	PD3
 * - 5	PD1
 * - 6	GND
 * - 7	PE4
 * - 8	PE5
 * */

//!
//#define AD1871_ADCBUFFER_POPULATED

//#define ADDA_ONLY_ONE_XTAL // this is incomplete HW workaound

/*! LED macro  */
#define LED_RED 	{HWREG(GPIO_PORTB_BASE + (GPIO_O_DATA + (GPIO_PIN_3 << 2))) = GPIO_PIN_3;\
					HWREG(GPIO_PORTD_BASE + (GPIO_O_DATA + (GPIO_PIN_6 << 2))) = 0;}
/*! LED macro  */
#define LED_GREEN 	{HWREG(GPIO_PORTB_BASE + (GPIO_O_DATA + (GPIO_PIN_3 << 2))) = 0;\
					HWREG(GPIO_PORTD_BASE + (GPIO_O_DATA + (GPIO_PIN_6 << 2))) = GPIO_PIN_6;}
/*! LED macro  */
#define LED_OFF	{HWREG(GPIO_PORTB_BASE + (GPIO_O_DATA + (GPIO_PIN_3 << 2))) = 0;\
					HWREG(GPIO_PORTD_BASE + (GPIO_O_DATA + (GPIO_PIN_6 << 2))) = 0;}



//! todo: dal�� definice
#define LRCLK_TIMER_BASE TIMER0_BASE

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

// d�liteln� 3, 4, 6, 18, 24
#define SSI_PLAY_BUFFER_SIZE (16800)
volatile uint8_t SSIPlayDataValid;
volatile uint32_t SSIPlayReadIndex;
volatile uint32_t SSIPlayWriteIndex;
uint8_t SSIPlayBuff[SSI_PLAY_BUFFER_SIZE];

uint8_t vzorky24;



#endif /* MAIN_H_ */
