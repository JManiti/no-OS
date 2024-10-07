/***************************************************************************//**
*   @file   AD7303.h
*   @brief  Header File for AD7303 Driver.
*   @author ATofan (alexandru.tofan@analog.com)
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

/*****************************************************************************/
/***************************** Include Files *********************************/
/*****************************************************************************/
#include "xil_types.h"
#include "xparameters.h"

/*****************************************************************************/
/************************** Macros Definitions *******************************/
/*****************************************************************************/
#define PMODDA1 XPAR_PMODDA1_0_BASEADDR

/*****************************************************************************/
/******************* AD7303 Registers Definitions ****************************/
/*****************************************************************************/
// Pmod-DA1 Core Register Address
#define Data0Reg PMODDA1
#define Data1Reg (PMODDA1 + 0x04)
#define Ctrl0Reg (PMODDA1 + 0x08)
#define Ctrl1Reg (PMODDA1 + 0x0C)
#define StartReg (PMODDA1 + 0x10)
/*****************************************************************************/
/******************* AD7303 Registers Bits ***********************************/
/*****************************************************************************/
// Configuration Register
#define INT     7
#define LDAC    5
#define PDB     4
#define PDA     3
#define notAB   2
#define CR1     1
#define CR0     0
// Waveform tables
static unsigned char const sinetable[256] = {
		 0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
		 0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
		 0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
		 0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
		 0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
		 0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
		 0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
		 0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
		 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
		 0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
		 0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
		 0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
		 0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
		 0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
		 0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
		 0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
		 0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
		 0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
		 0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
		 0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
		 0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
		 0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
		 0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
		 0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
		 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
		 0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
		 0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
		 0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
		 0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
		 0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
		 0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
		 0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
		 };
static unsigned char const sawtable[256] = {
		 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
		 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
		 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
		 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
		 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
		 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
		 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
		 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
		 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
		 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
		 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
		 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
		 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
		 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
		 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
		 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
		 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
		 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
		 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
		 0xa8, 0xa9, 0xaA, 0xaB, 0xaC, 0xaD, 0xaE, 0xaF,
		 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
		 0xb8, 0xb9, 0xbA, 0xbB, 0xbC, 0xbD, 0xbE, 0xbF,
		 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
		 0xc8, 0xc9, 0xcA, 0xcB, 0xcC, 0xcD, 0xcE, 0xcF,
		 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
		 0xd8, 0xd9, 0xdA, 0xdB, 0xdC, 0xdD, 0xdE, 0xdF,
		 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
		 0xe8, 0xe9, 0xeA, 0xeB, 0xeC, 0xeD, 0xeE, 0xeF,
		 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
		 0xf8, 0xf9, 0xfA, 0xfB, 0xfC, 0xfD, 0xfE, 0xfF
		 };
static unsigned char const triangletable[256] = {
		 0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,
		 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
		 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e,
		 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
		 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e,
		 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
		 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e,
		 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
		 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e,
		 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
		 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae,
		 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
		 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce,
		 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
		 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee,
		 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
		 0xfe, 0xfc, 0xfa, 0xf8, 0xf6, 0xf4, 0xf2, 0xf0,
		 0xee, 0xec, 0xea, 0xe8, 0xe6, 0xe4, 0xe2, 0xe0,
		 0xde, 0xdc, 0xda, 0xd8, 0xd6, 0xd4, 0xd2, 0xd0,
		 0xce, 0xcc, 0xca, 0xc8, 0xc6, 0xc4, 0xc2, 0xc0,
		 0xbe, 0xbc, 0xba, 0xb8, 0xb6, 0xb4, 0xb2, 0xb0,
		 0xae, 0xac, 0xaa, 0xa8, 0xa6, 0xa4, 0xa2, 0xa0,
		 0x9e, 0x9c, 0x9a, 0x98, 0x96, 0x94, 0x92, 0x90,
		 0x8e, 0x8c, 0x8a, 0x88, 0x86, 0x84, 0x82, 0x80,
		 0x7e, 0x7c, 0x7a, 0x78, 0x76, 0x74, 0x72, 0x70,
		 0x6e, 0x6c, 0x6a, 0x68, 0x66, 0x64, 0x62, 0x60,
		 0x5e, 0x5c, 0x5a, 0x58, 0x56, 0x54, 0x52, 0x50,
		 0x4e, 0x4c, 0x4a, 0x48, 0x46, 0x44, 0x42, 0x40,
		 0x3e, 0x3c, 0x3a, 0x38, 0x36, 0x34, 0x32, 0x30,
		 0x2e, 0x2c, 0x2a, 0x28, 0x26, 0x24, 0x22, 0x20,
		 0x1e, 0x1c, 0x1a, 0x18, 0x16, 0x14, 0x12, 0x10,
		 0x0e, 0x0c, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x00
		 };

static unsigned char const squaretable[256] = {
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		 };

/*****************************************************************************/
/************************ Functions Declarations *****************************/
/*****************************************************************************/

void AD7303Start(void);
void AD7303Stop(void);
void AD7303Convert(void);
void AD7303_FixedValue(void);
void AD7303_WaveGen(void);
void AD7303_DisplayMenu(void);
void AD7303_DisplayMainMenu(void);
void AD7303_InitData(void);
