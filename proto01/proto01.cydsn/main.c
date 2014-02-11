/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

CY_ISR_PROTO(ADC_DAC_Transfer);

int main()
{
    
    uint8 initCounter = 5;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PGA_1_Start();
    VDAC8_1_Start();
    VDAC8_2_Start();
    ADC_DelSig_1_Start();
    
    isr_1_StartEx(ADC_DAC_Transfer);
    
    
    while(initCounter>0)
    {
        VDAC8_1_SetValue(200);
        CyDelay(1000);
        VDAC8_1_SetValue(0);
        CyDelay(1000);
        initCounter--;
    }
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    ADC_DelSig_1_StartConvert();
    
    for(;;)
    {
        /* Place your application code here. */
        
    }
}

CY_ISR(ADC_DAC_Transfer)
{
    VDAC8_1_SetValue(ADC_DelSig_1_GetResult8());
    
}

/* [] END OF FILE */
