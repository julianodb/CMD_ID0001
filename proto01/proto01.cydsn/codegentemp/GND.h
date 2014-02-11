/*******************************************************************************
* File Name: GND.h  
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

#if !defined(CY_PINS_GND_H) /* Pins GND_H */
#define CY_PINS_GND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GND_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GND_Write(uint8 value) ;
void    GND_SetDriveMode(uint8 mode) ;
uint8   GND_ReadDataReg(void) ;
uint8   GND_Read(void) ;
uint8   GND_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GND_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define GND_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define GND_DM_RES_UP          PIN_DM_RES_UP
#define GND_DM_RES_DWN         PIN_DM_RES_DWN
#define GND_DM_OD_LO           PIN_DM_OD_LO
#define GND_DM_OD_HI           PIN_DM_OD_HI
#define GND_DM_STRONG          PIN_DM_STRONG
#define GND_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define GND_MASK               GND__MASK
#define GND_SHIFT              GND__SHIFT
#define GND_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GND_PS                     (* (reg8 *) GND__PS)
/* Data Register */
#define GND_DR                     (* (reg8 *) GND__DR)
/* Port Number */
#define GND_PRT_NUM                (* (reg8 *) GND__PRT) 
/* Connect to Analog Globals */                                                  
#define GND_AG                     (* (reg8 *) GND__AG)                       
/* Analog MUX bux enable */
#define GND_AMUX                   (* (reg8 *) GND__AMUX) 
/* Bidirectional Enable */                                                        
#define GND_BIE                    (* (reg8 *) GND__BIE)
/* Bit-mask for Aliased Register Access */
#define GND_BIT_MASK               (* (reg8 *) GND__BIT_MASK)
/* Bypass Enable */
#define GND_BYP                    (* (reg8 *) GND__BYP)
/* Port wide control signals */                                                   
#define GND_CTL                    (* (reg8 *) GND__CTL)
/* Drive Modes */
#define GND_DM0                    (* (reg8 *) GND__DM0) 
#define GND_DM1                    (* (reg8 *) GND__DM1)
#define GND_DM2                    (* (reg8 *) GND__DM2) 
/* Input Buffer Disable Override */
#define GND_INP_DIS                (* (reg8 *) GND__INP_DIS)
/* LCD Common or Segment Drive */
#define GND_LCD_COM_SEG            (* (reg8 *) GND__LCD_COM_SEG)
/* Enable Segment LCD */
#define GND_LCD_EN                 (* (reg8 *) GND__LCD_EN)
/* Slew Rate Control */
#define GND_SLW                    (* (reg8 *) GND__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GND_PRTDSI__CAPS_SEL       (* (reg8 *) GND__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GND_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GND__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GND_PRTDSI__OE_SEL0        (* (reg8 *) GND__PRTDSI__OE_SEL0) 
#define GND_PRTDSI__OE_SEL1        (* (reg8 *) GND__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GND_PRTDSI__OUT_SEL0       (* (reg8 *) GND__PRTDSI__OUT_SEL0) 
#define GND_PRTDSI__OUT_SEL1       (* (reg8 *) GND__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GND_PRTDSI__SYNC_OUT       (* (reg8 *) GND__PRTDSI__SYNC_OUT) 


#if defined(GND__INTSTAT)  /* Interrupt Registers */

    #define GND_INTSTAT                (* (reg8 *) GND__INTSTAT)
    #define GND_SNAP                   (* (reg8 *) GND__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins GND_H */


/* [] END OF FILE */
