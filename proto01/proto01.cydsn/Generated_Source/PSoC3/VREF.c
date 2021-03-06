/*******************************************************************************
* File Name: VREF.c  
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
#include "VREF.h"


/*******************************************************************************
* Function Name: VREF_Write
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
void VREF_Write(uint8 value) 
{
    uint8 staticBits = (VREF_DR & (uint8)(~VREF_MASK));
    VREF_DR = staticBits | ((uint8)(value << VREF_SHIFT) & VREF_MASK);
}


/*******************************************************************************
* Function Name: VREF_SetDriveMode
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
void VREF_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VREF_0, mode);
}


/*******************************************************************************
* Function Name: VREF_Read
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
*  Macro VREF_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VREF_Read(void) 
{
    return (VREF_PS & VREF_MASK) >> VREF_SHIFT;
}


/*******************************************************************************
* Function Name: VREF_ReadDataReg
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
uint8 VREF_ReadDataReg(void) 
{
    return (VREF_DR & VREF_MASK) >> VREF_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VREF_INTSTAT) 

    /*******************************************************************************
    * Function Name: VREF_ClearInterrupt
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
    uint8 VREF_ClearInterrupt(void) 
    {
        return (VREF_INTSTAT & VREF_MASK) >> VREF_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
