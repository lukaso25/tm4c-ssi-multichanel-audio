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
 * - pøi 24/96 se seká zvuk pøi nastavování hlasitosti
 * - implementace ESD, zjistit co se stane, když se v okolí zapne trafo
 * - zkusit napájet +5V z externího zdroje
 * - hlasitost jde nastavovat, ale seká se.... a taky bude si pamatovat PC? zatím to moc nefunguje :-( ale proè?
 * - implementace hibernate situace USB, režimy snížené spotøeby
 * - podpora snížené spotøeby u kodekù
 * - podpora snížené spotøeby u procesoru
 * - indikátor vstupní úrovnì -> pøes seriovku tøeba
 * - problém s vypadnutím ze synchronizace - prohození bytù pro I2S - obèas pøijdou data, která nesplòují délka%poèetbytù=0
 * - problém s pøepínáním frekvence, proè až pøi druhé zmìnì zmìnì
 * - zkontrolovat fázi výstupù - osciloskop
 * - Provést kontrolu loopbacku pøes I2S ... propojit sdi se sdo ! (kontrola bit accurate)
 * - inteligentní indikace frekcence, limitace ADC, výpadky
 * - vylepšit feedback, aby byl lineární, limity nastavovat podle aktuální frekvence, volba latence, odstranìní závislosti na èasovaèi
 * - vstup je pravdìpodobnì invertován
 * - NMI piny, zase zamknout
 * - pøidat HID rozhranní
 * - uart MIDI, nebo uart console
 * - opravy kódu, modularizace
 *
 * fixed errors
 * ------------
 * (czech language only)
 * - další alt setting pro záznam
 * - left and right shifted about 1 sample (left is one sample delayed) - buffery se synchronizují mezi levým a pravým kanálem
 * - proè se seká, když hýbu myší pøi nastavení nahrávání? - pomalé posílání po seriovce
 * - I2S recording corrected
 * - výchozí vzorkovaèku z promìnné v AnalogADDA modulu
 * - problém nastavování AD1871 a dìlièe - musejí se nastavit oba registry, aby bylo 6.144 do modulátoru, SPI interface vyžaduje MCK bìžící
 * - problém pozapnutí - proè šum - špatný formát hodin
 * - chyba zmìny frekvence nahrávacího endpoitu - endpoint definovaný bez 0x80
 * - chyba nahrávání - špatnì definovaná spatial position
 * - nahodilé výpadky - nepøesný feedback
 * - 16 bit nejde, proè? - jenom malá velikost endpointu
 * - 96 kHz výstup pøeskakuje - jenom 90*2*3 bytu
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



//! todo: další definice
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

// dìlitelné 3, 4, 6, 18, 24
#define SSI_PLAY_BUFFER_SIZE (16800)
volatile uint8_t SSIPlayDataValid;
volatile uint32_t SSIPlayReadIndex;
volatile uint32_t SSIPlayWriteIndex;
uint8_t SSIPlayBuff[SSI_PLAY_BUFFER_SIZE];

uint8_t vzorky24;



#endif /* MAIN_H_ */
