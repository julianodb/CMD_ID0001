/*******************************************************************************
* File Name: SENSOROUTPUT.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SENSOROUTPUT_H) /* Pins SENSOROUTPUT_H */
#define CY_PINS_SENSOROUTPUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SENSOROUTPUT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SENSOROUTPUT_Write(uint8 value) ;
void    SENSOROUTPUT_SetDriveMode(uint8 mode) ;
uint8   SENSOROUTPUT_ReadDataReg(void) ;
uint8   SENSOROUTPUT_Read(void) ;
uint8   SENSOROUTPUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SENSOROUTPUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SENSOROUTPUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SENSOROUTPUT_DM_RES_UP          PIN_DM_RES_UP
#define SENSOROUTPUT_DM_RES_DWN         PIN_DM_RES_DWN
#define SENSOROUTPUT_DM_OD_LO           PIN_DM_OD_LO
#define SENSOROUTPUT_DM_OD_HI           PIN_DM_OD_HI
#define SENSOROUTPUT_DM_STRONG          PIN_DM_STRONG
#define SENSOROUTPUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SENSOROUTPUT_MASK               SENSOROUTPUT__MASK
#define SENSOROUTPUT_SHIFT              SENSOROUTPUT__SHIFT
#define SENSOROUTPUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SENSOROUTPUT_PS                     (* (reg8 *) SENSOROUTPUT__PS)
/* Data Register */
#define SENSOROUTPUT_DR                     (* (reg8 *) SENSOROUTPUT__DR)
/* Port Number */
#define SENSOROUTPUT_PRT_NUM                (* (reg8 *) SENSOROUTPUT__PRT) 
/* Connect to Analog Globals */                                                  
#define SENSOROUTPUT_AG                     (* (reg8 *) SENSOROUTPUT__AG)                       
/* Analog MUX bux enable */
#define SENSOROUTPUT_AMUX                   (* (reg8 *) SENSOROUTPUT__AMUX) 
/* Bidirectional Enable */                                                        
#define SENSOROUTPUT_BIE                    (* (reg8 *) SENSOROUTPUT__BIE)
/* Bit-mask for Aliased Register Access */
#define SENSOROUTPUT_BIT_MASK               (* (reg8 *) SENSOROUTPUT__BIT_MASK)
/* Bypass Enable */
#define SENSOROUTPUT_BYP                    (* (reg8 *) SENSOROUTPUT__BYP)
/* Port wide control signals */                                                   
#define SENSOROUTPUT_CTL                    (* (reg8 *) SENSOROUTPUT__CTL)
/* Drive Modes */
#define SENSOROUTPUT_DM0                    (* (reg8 *) SENSOROUTPUT__DM0) 
#define SENSOROUTPUT_DM1                    (* (reg8 *) SENSOROUTPUT__DM1)
#define SENSOROUTPUT_DM2                    (* (reg8 *) SENSOROUTPUT__DM2) 
/* Input Buffer Disable Override */
#define SENSOROUTPUT_INP_DIS                (* (reg8 *) SENSOROUTPUT__INP_DIS)
/* LCD Common or Segment Drive */
#define SENSOROUTPUT_LCD_COM_SEG            (* (reg8 *) SENSOROUTPUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define SENSOROUTPUT_LCD_EN                 (* (reg8 *) SENSOROUTPUT__LCD_EN)
/* Slew Rate Control */
#define SENSOROUTPUT_SLW                    (* (reg8 *) SENSOROUTPUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SENSOROUTPUT_PRTDSI__CAPS_SEL       (* (reg8 *) SENSOROUTPUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SENSOROUTPUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SENSOROUTPUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SENSOROUTPUT_PRTDSI__OE_SEL0        (* (reg8 *) SENSOROUTPUT__PRTDSI__OE_SEL0) 
#define SENSOROUTPUT_PRTDSI__OE_SEL1        (* (reg8 *) SENSOROUTPUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SENSOROUTPUT_PRTDSI__OUT_SEL0       (* (reg8 *) SENSOROUTPUT__PRTDSI__OUT_SEL0) 
#define SENSOROUTPUT_PRTDSI__OUT_SEL1       (* (reg8 *) SENSOROUTPUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SENSOROUTPUT_PRTDSI__SYNC_OUT       (* (reg8 *) SENSOROUTPUT__PRTDSI__SYNC_OUT) 


#if defined(SENSOROUTPUT__INTSTAT)  /* Interrupt Registers */

    #define SENSOROUTPUT_INTSTAT                (* (reg8 *) SENSOROUTPUT__INTSTAT)
    #define SENSOROUTPUT_SNAP                   (* (reg8 *) SENSOROUTPUT__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SENSOROUTPUT_H */


/* [] END OF FILE */
