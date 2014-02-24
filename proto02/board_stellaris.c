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

#include "board_stellaris.h"

/* Set clocking and basic configuration  */
int 
initialize_board (void)
{

	ROM_FPULazyStackingEnable (); // float on interrupts

	ROM_SysCtlClockSet (SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL 
			    | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	return 0; // Success

}

/* Enable corresponding GPIO and set Pins for led */
int
initialize_led (void)
{

	ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF); // LED is on F port

	ROM_GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, 
				   RED_LED|BLUE_LED|GREEN_LED);

	return 0; // Success

}

/* Enable corresponding GPIO and init UART (debug connection) */
int
initialize_uart (void)
{
	ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA); // UART is on A
	ROM_GPIOPinConfigure (GPIO_PA0_U0RX); // PA0 = RX
	ROM_GPIOPinConfigure (GPIO_PA1_U0TX); // PA1 = TX
	ROM_GPIOPinTypeUART (GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTStdioInit (0);

	return 0; // Success
}

/* adc */
int 
initialize_adc (int mode)
{

	SysCtlPeripheralEnable (SYSCTL_PERIPH_ADC0); // Enable ADC0

	if (mode == MODE_ANALOG0) {
		SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE);
		GPIOPinTypeADC (GPIO_PORTE_BASE, GPIO_PIN_3);
		// AIn0 = PE3
	}

	ADCSequenceConfigure (ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

	if (mode == MODE_ANALOG0) {

		ADCSequenceStepConfigure (ADC0_BASE, 3, 0, 
					ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);

	} else if (mode == MODE_TEMPERATURE) {

		ADCSequenceStepConfigure (ADC0_BASE, 3, 0, 
					 ADC_CTL_TS | ADC_CTL_IE | ADC_CTL_END);

	}

	ADCSequenceEnable (ADC0_BASE, 3);

	ADCIntClear (ADC0_BASE, 3);

	return 0; // Success
}

/* Toggle corresponding LED */
int 
led_toggle (int led)
{
	int curr_status = 0;

	switch (led) {
	case RED_LED:
	case GREEN_LED:
	case BLUE_LED:
		curr_status = GPIOPinRead(GPIO_PORTF_BASE, led);
		GPIOPinWrite(GPIO_PORTF_BASE, led, ~curr_status);
		break;
	default:
		
		break;
	}
	return 0; // Success
}


/* Prints string on UART */
int 
uart_printf (char *s)
{

	UARTprintf(s);
	return 0;
}

/* Get temperature (Celsius) based on ADC reading */
unsigned long 
adc_get_temp (void)
{
	unsigned long ulADC0_Value[1]; // 1 is sequence length

	// TODO: if initialized in temperature mode

        ADCProcessorTrigger (ADC0_BASE, 3);

        while (!ADCIntStatus(ADC0_BASE, 3, false)) {
	}

        ADCIntClear (ADC0_BASE, 3);

        ADCSequenceDataGet (ADC0_BASE, 3, ulADC0_Value);

        return 147.5 - ((75*(3.3)*ulADC0_Value[0])/4096);
}

/* Get one reading from the adc */
unsigned long 
adc_get_reading (void)
{
    unsigned long ulADC0_Value[1]; // 1 is Sequence length

	// TODO: if initialized in temperature mode

        ADCProcessorTrigger(ADC0_BASE, 3);

        while(!ADCIntStatus(ADC0_BASE, 3, false)) {
	}

        ADCIntClear(ADC0_BASE, 3);

        ADCSequenceDataGet(ADC0_BASE, 3, ulADC0_Value);

        return ulADC0_Value[0];
}

/* EOF */
