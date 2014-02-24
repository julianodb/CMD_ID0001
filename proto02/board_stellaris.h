#ifndef BOARD_STELLARIS_H
#define BOARD_STELLARIS_H

/*                                                                         */
/*    Board Stellaris                                                      */
/*                                                                         */
/*    Provides Initialization and Configuration functions for the          */
/*    Stellaris launchpad board                                            */
/*                                                                         */
/*    Author: Juliano Dawid Barboza (julianodawid@gmail.com)               */
/*                                                                         */
/*    This file is part of Proto02.                                        */
/*                                                                         */
/*    Proto02 is free software: you can redistribute it and/or modify      */
/*    it under the terms of the GNU General Public License as published by */
/*    the Free Software Foundation, either version 3 of the License, or    */
/*    (at your option) any later version.                                  */
/*                                                                         */
/*    Proto02 is distributed in the hope that it will be useful,           */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/*    GNU General Public License for more details.                         */
/*                                                                         */
/*    You should have received a copy of the GNU General Public License    */
/*    along with Proto02.  If not, see <http://www.gnu.org/licenses/>.     */
/*                                                                         */

/***    Dependencies    ***/

/* files needed in initialize_board */
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"

/* files needed in initialize_led */
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"

/* Files needed in initialize_uart */
#include "utils/uartstdio.h"

/* Files needed in initialize_adc */
#include "driverlib/adc.h"

/* These files might be of interest  */
/*
	#include "inc/hw_memmap.h"
	#include "driverlib/debug.h"
	#include "driverlib/fpu.h"
	#include "driverlib/pin_map.h"
*/

/***    Macros    ***/

#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

#define MODE_TEMPERATURE 0
#define MODE_ANALOG0	 1

/***    Function Prototypes    ***/

/* Set clocking and basic configuration  */
int initialize_board ();

/* Enable corresponding GPIO and set Pins for led */
int initialize_led ();

/* Enable corresponding GPIO and init UART (debug connection) */
int initialize_uart ();

/* adc */
int initialize_adc (int mode);

/* Toggle corresponding LED */
int led_toggle (int led);

/* Prints string on UART */
void (*uart_printf) (const char *s, ...);

/* Get temperature (Celsius) based on ADC reading */
unsigned long adc_get_temp ();

/* Get one reading from the adc */
unsigned long adc_get_reading ();

#endif /* BOARD_STELLARIS_H */
