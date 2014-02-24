/*                                                                         */
/*    Proto02                                                              */
/*                                                                         */
/*    Pulse Oximeter Prototype number 02: uses Stellaris Launchpad         */
/*    board to read sensor and send values to pc.                          */
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

#include "board_stellaris.h"

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

int
main(void)
{

	initialize_board();
	initialize_led();
	initialize_uart();
	initialize_adc(MODE_ANALOG0);

	uart_printf("Hello, world!\n");

    while(1)
    {

	//UARTprintf ("Temperature = %3d*C \r", adc_get_temp ());
	uart_printf ("AIN0 (PE3) = %3d \r", adc_get_reading ());
	led_toggle (GREEN_LED);
        //
        // This function provides a means of generating a constant length
        // delay.  The function delay (in cycles) = 3 * parameter.  Delay
        // 250ms arbitrarily.
        //
        SysCtlDelay(SysCtlClockGet() / 12);


    }
}
