/*******************************************************************************
* File Name: SENSOROUTPUT.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SENSOROUTPUT.h"


/*******************************************************************************
* Function Name: SENSOROUTPUT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SENSOROUTPUT_Write(uint8 value) 
{
    uint8 staticBits = (SENSOROUTPUT_DR & (uint8)(~SENSOROUTPUT_MASK));
    SENSOROUTPUT_DR = staticBits | ((uint8)(value << SENSOROUTPUT_SHIFT) & SENSOROUTPUT_MASK);
}


/*******************************************************************************
* Function Name: SENSOROUTPUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void SENSOROUTPUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SENSOROUTPUT_0, mode);
}


/*******************************************************************************
* Function Name: SENSOROUTPUT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SENSOROUTPUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SENSOROUTPUT_Read(void) 
{
    return (SENSOROUTPUT_PS & SENSOROUTPUT_MASK) >> SENSOROUTPUT_SHIFT;
}


/*******************************************************************************
* Function Name: SENSOROUTPUT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SENSOROUTPUT_ReadDataReg(void) 
{
    return (SENSOROUTPUT_DR & SENSOROUTPUT_MASK) >> SENSOROUTPUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SENSOROUTPUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: SENSOROUTPUT_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SENSOROUTPUT_ClearInterrupt(void) 
    {
        return (SENSOROUTPUT_INTSTAT & SENSOROUTPUT_MASK) >> SENSOROUTPUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
