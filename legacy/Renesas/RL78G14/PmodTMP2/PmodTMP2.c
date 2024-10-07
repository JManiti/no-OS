/***************************************************************************//**
 *   @file   Main.c
 *   @brief  Implementation of the program's main function.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2012(c) Analog Devices, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. “AS IS” AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ANALOG DEVICES, INC. BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
********************************************************************************
 *   SVN Revision: $WCREV$
*******************************************************************************/

/******************************************************************************/
/***************************** Option Bytes ***********************************/
/******************************************************************************/
#pragma location = "OPTBYTE"
__root const unsigned char opbyte0 = 0x6E; // Watchdog timer settings.
#pragma location = "OPTBYTE"
__root const unsigned char opbyte1 = 0xFF; // Low voltage detector settings.
#pragma location = "OPTBYTE"
__root const unsigned char opbyte2 = 0xE8; // Flash op. mode and osc. settings.
#pragma location = "OPTBYTE"
__root const unsigned char opbyte3 = 0x85; // On-chip Debug Option Byte.

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include "RDKRL78G14.h"     // RDKRL78G14 definitions.
#include "ST7579.h"         // ST7579 definitions.
#include "TIME.h"           // TIME definitions.
#include "ADT7420.h"        // ADT7420 definitions.

/******************************************************************************/
/************************ Variables Definitions *******************************/
/******************************************************************************/
float temperature = 0;
long  index       = 0;

/***************************************************************************//**
 * @brief Draws the ADI logo and displays the name of ADI component.
 *
 * @param componentName - The name of the ADI component.
 *
 * @return None.
*******************************************************************************/
void ADI_Component(unsigned char* string)
{
    const unsigned char adiComponent[7] =
    {
        0xFE, 0xFE, 0x82, 0xC6, 0xEE, 0xFE, 0xFE 
    };
    ST7579_Image(0, 0, adiComponent, 7, 8);
    ST7579_String(0, 9, string, 0);
}

/***************************************************************************//**
 * @brief Main function.
 *
 * @return None.
*******************************************************************************/
void main(void)
{
    
    /* Initialize RDKRL78G14. */
    RDKRL78G14_Init();
    
    /* Enable interrupts. */
    __enable_interrupt();
        
    /* Initialize timer. */
    TIME_Init();
    
    /* Initialize the ST7579 Display. */
    ST7579_Init();
    
    /* Init device. */
    if(ADT7420_Init() == 0)
    {
        ADI_Component("ADT7420 OK");
    }
    else
    {
        ADI_Component("ADT7420 Error");
    }
    
    /* Reset the device. */
    ADT7420_Reset();
    
    /* Put the device in continuous conversion mode. */
    ADT7420_SetOperationMode(ADT7420_OP_MODE_CONT_CONV);
    
    /* Sets the resolution for ADT7420 to 13-bit resolution. */
    ADT7420_SetResolution(0);
    
    ST7579_String(2, 6, " Temperature:", 0);
    ST7579_String(3, 6, " [deg Celsius]", 0);
    
    while(1)
    {
         /* Read temperature and display it. */
        temperature = ADT7420_GetTemperature();
        ST7579_FloatNumber(5, 0, temperature, 1, 1);
        TIME_DelayMs(200);
    }   
}
