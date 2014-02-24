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
initialize_board(void)
{

    //
    // Enable lazy stacking for interrupt handlers.  This allows floating-po    int
    // instructions to be used within interrupt handlers, but at the expense     of
    // extra stack usage.
    //
    ROM_FPULazyStackingEnable();

    //
    // Set the clocking to run directly from the crystal.
    //
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ     |
                       SYSCTL_OSC_MAIN);

	return 0;

}

/* Enable corresponding GPIO and set Pins for led */
int
initialize_led(void)
{

	//
	// Enable the GPIO port that is used for the on-board LED.
	//
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	//
	// Enable the GPIO pins for the LED (0, 1 and 2).  
	//
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED);

	return 0;

}

/* Enable corresponding GPIO and init UART (debug connection) */
int
initialize_uart(void)
{
    //
    // Initialize the UART.
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioInit(0);

	return 0;
}

/* adc */
int 
initialize_adc (int mode)
{

    //
    // The ADC0 peripheral must be enabled for use.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	if (mode == MODE_ANALOG0) {
    //
    // For this example ADC0 is used with AIN0 on port E7.
    // The actual port and pins used may be different on your part, consult
    // the data sheet for more information.  GPIO port E needs to be enabled
    // so these pins can be used.
    // TODO: change this to whichever GPIO port you are using.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    //
    // Select the analog ADC function for these pins.
    // Consult the data sheet to see which functions are allocated per pin.
    // TODO: change this to select the port/pin you are using.
    //
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);

	}
    //
    // Enable sample sequence 3 with a processor signal trigger.  Sequence 3
    // will do a single sample when the processor sends a singal to start the
    // conversion.  Each ADC module has 4 programmable sequences, sequence 0
    // to sequence 3.  This example is arbitrarily using sequence 3.
    //
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

    //
    // Configure step 0 on sequence 3.  Sample the temperature sensor
    // or analog 0 (ADC_CTL_TS or ADC_CTL_CH0) and configure 
    // the interrupt flag (ADC_CTL_IE) to be set
    // when the sample is done.  Tell the ADC logic that this is the last
    // conversion on sequence 3 (ADC_CTL_END).  Sequence 3 has only one
    // programmable step.  Sequence 1 and 2 have 4 steps, and sequence 0 has
    // 8 programmable steps.  Since we are only doing a single conversion using
    // sequence 3 we will only configure step 0.  For more information on the
    // ADC sequences and steps, reference the datasheet.
    //
	if (mode == MODE_ANALOG0) {

		ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);

	} else if (mode == MODE_TEMPERATURE) {

		ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_TS | ADC_CTL_IE | ADC_CTL_END);

	}
    //
    // Since sample sequence 3 is now configured, it must be enabled.
    //
    ADCSequenceEnable(ADC0_BASE, 3);

    //
    // Clear the interrupt status flag.  This is done to make sure the
    // interrupt flag is cleared before we sample.
    //
    ADCIntClear(ADC0_BASE, 3);


	return 0;
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
adc_get_temp(void)
{
    //
    // This array is used for storing the data read from the ADC FIFO. It
    // must be as large as the FIFO for the sequencer in use.  This example
    // uses sequence 3 which has a FIFO depth of 1.  If another sequence
    // was used with a deeper FIFO, then the array size must be changed.
    //
    unsigned long ulADC0_Value[1];

	// TODO: if initialized in temperature mode

	//
        // Trigger the ADC conversion.
        //
        ADCProcessorTrigger(ADC0_BASE, 3);

        //
        // Wait for conversion to be completed.
        //
        while(!ADCIntStatus(ADC0_BASE, 3, false))
        {
        }

        //
        // Clear the ADC interrupt flag.
        //
        ADCIntClear(ADC0_BASE, 3);

        //
        // Read ADC Value.
        //
        ADCSequenceDataGet(ADC0_BASE, 3, ulADC0_Value);

        //
        // Use non-calibrated conversion provided in the data sheet.  Make
        // sure you divide last to avoid dropout.
        //
        return 147.5 - ((75*(3.3)*ulADC0_Value[0])/4096);

}

/* Get one reading from the adc */
unsigned long 
adc_get_reading (void)
{
    //
    // This array is used for storing the data read from the ADC FIFO. It
    // must be as large as the FIFO for the sequencer in use.  This example
    // uses sequence 3 which has a FIFO depth of 1.  If another sequence
    // was used with a deeper FIFO, then the array size must be changed.
    //
    unsigned long ulADC0_Value[1];

	// TODO: if initialized in temperature mode

	//
        // Trigger the ADC conversion.
        //
        ADCProcessorTrigger(ADC0_BASE, 3);

        //
        // Wait for conversion to be completed.
        //
        while(!ADCIntStatus(ADC0_BASE, 3, false))
        {
        }

        //
        // Clear the ADC interrupt flag.
        //
        ADCIntClear(ADC0_BASE, 3);

        //
        // Read ADC Value.
        //
        ADCSequenceDataGet(ADC0_BASE, 3, ulADC0_Value);

        return ulADC0_Value[0];

}


/* EOF */
