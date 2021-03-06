/*******************************************************************************
* File Name: GND.c  
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
#include "GND.h"


/*******************************************************************************
* Function Name: GND_Write
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
void GND_Write(uint8 value) 
{
    uint8 staticBits = (GND_DR & (uint8)(~GND_MASK));
    GND_DR = staticBits | ((uint8)(value << GND_SHIFT) & GND_MASK);
}


/*******************************************************************************
* Function Name: GND_SetDriveMode
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
void GND_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(GND_0, mode);
}


/*******************************************************************************
* Function Name: GND_Read
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
*  Macro GND_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GND_Read(void) 
{
    return (GND_PS & GND_MASK) >> GND_SHIFT;
}


/*******************************************************************************
* Function Name: GND_ReadDataReg
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
uint8 GND_ReadDataReg(void) 
{
    return (GND_DR & GND_MASK) >> GND_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GND_INTSTAT) 

    /*******************************************************************************
    * Function Name: GND_ClearInterrupt
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
    uint8 GND_ClearInterrupt(void) 
    {
        return (GND_INTSTAT & GND_MASK) >> GND_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
