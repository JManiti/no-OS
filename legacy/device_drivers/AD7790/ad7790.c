/***************************************************************************//**
*   @file   ad7790.c
*   @brief  Implementation of AD7790 Driver for Microblaze processor.
*   @author Lucian Sin (Lucian.Sin@analog.com)
*
*******************************************************************************
* Copyright 2014(c) Analog Devices, Inc.
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
******************************************************************************/

/******************************************************************************/
/******************************* Include Files ********************************/
/******************************************************************************/
#include "ad7790.h"
#include "Communication.h"
#include "TIME.h"

/***************************************************************************//**
 * @brief Initializes SPI and initial values for AD7790 device.
 *
 * @param None.
 *
 * @return status - Result of the initialization procedure.
 *                  Example:  0 - if initialization was successful;
 *                           -1 - if initialization was unsuccessful.
*******************************************************************************/
char AD7790_Init(void)
{
    char status = -1;

    status = SPI_Init(0, 1000000, 1, 0);
    AD7790_Reset();

    return status;
}

/***************************************************************************//**
 * @brief Reads data from AD7790.
 *
 * @param regAddress  - Address of the register.
 * @param bytesNumber - Number of bytes.
 *
 * @return readData   - Received data.
*******************************************************************************/
unsigned long AD7790_Read(unsigned char regAddress,
                          unsigned char bytesNumber)
{
    unsigned long receivedData = 0x0;
    unsigned char command      = 0x0;
    unsigned char dataBuf[3]   = {0x00, 0x00, 0x00};

    command    = AD7790_COMM_READ + AD7790_COMM_ADDR(regAddress);
    dataBuf[0] = command;
    SPI_Read(AD7790_SLAVE_ID, (unsigned char*)dataBuf, bytesNumber + 1);
    receivedData = (dataBuf[1] << 8) + (dataBuf[2] << 0);

    return(receivedData);
}

/***************************************************************************//**
 * @brief Writes data to AD7790.
 *
 * @param regAddress  - Address of the register.
 * @param bytesNumber - Number of bytes.
 * @param regData     - Data that will be loaded.
 *
 * @return None.
*******************************************************************************/
void AD7790_Write(unsigned char regAddress,
                  unsigned char regData)
{
    unsigned char command     = 0x0;
    unsigned char txBuf[2]    = {0x00, 0x00};
    unsigned char bytesNumber = 2; // command(=8bits) + data(=8bits)

    command  = AD7790_COMM_WRITE + AD7790_COMM_ADDR(regAddress);
    txBuf[0] = command;
    txBuf[1] = regData;
    SPI_Write(AD7790_SLAVE_ID, (unsigned char*)txBuf, bytesNumber);

}

/***************************************************************************//**
 * @brief Converts 16-bit raw data to millivolts.
 *
 * @param rawData  - 16-bit data sample.
 * @param vRef     - The value of the voltage reference used by the device in volts.
 * @param gain     - The analog input signal gain.(1, 2, 4 or 8)
 *
 * @return voltage - The result of the conversion expressed in millivolts.
*******************************************************************************/
float AD7790_ConvertToVoltage(unsigned long rawData,
                              float         vRef,
                              unsigned char gain)
{
    float voltage = 0;

    voltage = 1000 * (((float)rawData / (1ul << 15)) - 1) * vRef / gain;

    return voltage;
}

/***************************************************************************//**
 * @brief Resets the serial interface with the AD7790.
 *
 * @param None.
 *
 * @return None.
*******************************************************************************/
void AD7790_Reset(void)
{
    unsigned char bytesNumber = 5;
    unsigned char txBuf[5]    = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    SPI_Write(AD7790_SLAVE_ID, (unsigned char*)txBuf, bytesNumber);
}
