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

#ifndef BOARD_STELLARIS_H
#define BOARD_STELLARIS_H

/***    Dependencies    ***/

#include <stdint.h>

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

/* Files needed in initialize_pwm */
#include "driverlib/timer.h"
#include "inc/hw_timer.h"

/* These files might be of interest  */
/*

	#include "driverlib/debug.h"
	#include "driverlib/fpu.h"

*/

/***    Macros    ***/

#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3
#define PWM_PRESCALE	0xFFFF

#define MODE_TEMPERATURE 0
#define MODE_ANALOG0	 1

/***    Function Prototypes    ***/

/* Set clocking and basic configuration  */
uint8_t initialize_board ();

/* Enable corresponding GPIO and set Pins for led */
uint8_t initialize_led ();

/* Enable corresponding GPIO and init UART (debug connection) */
uint8_t initialize_uart ();

/* adc */
uint8_t initialize_adc (uint8_t mode);

/* pwm */
uint8_t initialize_pwm ();

/* Toggle corresponding LED */
uint8_t led_toggle (uint8_t led);

/* Prints string on UART */
void (*uart_printf) (const char *s, ...);

/* Get temperature (Celsius) based on ADC reading */
uint32_t adc_get_temp ();

/* Get one reading from the adc */
uint32_t adc_get_reading ();

/* Set pwm duty cicle */
uint8_t pwm_set_duty (uint32_t duty);

#endif /* BOARD_STELLARIS_H */
