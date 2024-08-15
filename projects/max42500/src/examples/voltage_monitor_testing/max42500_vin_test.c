/***************************************************************************//**
 *   @file   max42500_vin_test.c
 *   @brief  Implementation of basic MAX42500 example
 *   @author 
********************************************************************************
 * Copyright 2024(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include <stdio.h>
#include "common_data.h"


/*******************************************************************************
 * @brief MAX42500 example main execution.
 *
 * @return ret - Result of the example execution.
*******************************************************************************/

int max42500_vin_test_main(void)
{
	int ret;
	struct no_os_uart_desc *uart_desc;
	struct max42500_dev *device;
	enum max42500_vm_input vm_input;

	ret = no_os_uart_init(&uart_desc, &uart_ip);
	if (ret)
		return ret;

	no_os_uart_stdio(uart_desc);

	printf("********** MAX42500 Voltage Monitor Tests **********\n\r");

	/* Initializing the device MAX42500 */
	ret = max42500_init(&device, &max42500_ip);
	if (ret)
		return ret;

	// Configuring VIN1 - VIN5 Nominal Voltage (2V)
	max42500_reg_write2(device, MAX42500_VIN1, 0x78);
	max42500_reg_write2(device, MAX42500_VIN2, 0x78);
	max42500_reg_write2(device, MAX42500_VIN3, 0x78);
	max42500_reg_write2(device, MAX42500_VIN4, 0x78);
	max42500_reg_write2(device, MAX42500_VIN5, 0x4B);

	// Configuring VIN1 - VIN5 Undervoltage and Overvoltage thresholds (10%)
	max42500_reg_write2(device, MAX42500_OVUV1, 0xFF);
	max42500_reg_write2(device, MAX42500_OVUV2, 0xFF);
	max42500_reg_write2(device, MAX42500_OVUV3, 0xFF);
	max42500_reg_write2(device, MAX42500_OVUV4, 0xFF);
	max42500_reg_write2(device, MAX42500_OVUV5, 0xFF);
	
	// Configuring VIN6 Undervoltage and Overvoltage thresholds (0.9V, 1.1V)
	max42500_reg_write2(device, MAX42500_VINO6, 0x78);
	max42500_reg_write2(device, MAX42500_VINU6, 0x50 );
	
	// Configuring VIN7 Undervoltage and Overvoltage thresholds (0.9V, 1.1V)
	max42500_reg_write2(device, MAX42500_VINO7, 0x78);
	max42500_reg_write2(device, MAX42500_VINU7, 0x50 );	
	
	// Enabling VMON 1 - VMON 7
	max42500_set_vmon_enable(device, max42500_regs[MAX42500_VMON].value |
			    	 MAX42500_VMON_IN_MASK(MAX42500_VM1) |
			   	 MAX42500_VMON_IN_MASK(MAX42500_VM2) |
			    	 MAX42500_VMON_IN_MASK(MAX42500_VM3) |
			    	 MAX42500_VMON_IN_MASK(MAX42500_VM4) |
			    	 MAX42500_VMON_IN_MASK(MAX42500_VM5) |
				 MAX42500_VMON_IN_MASK(MAX42500_VM6) |
				 MAX42500_VMON_IN_MASK(MAX42500_VM7));
    
	while (1)
	{
		max42500_reg_read(device, &max42500_regs[MAX42500_STATUV]);
		max42500_reg_read(device, &max42500_regs[MAX42500_STATOV]);
		max42500_reg_read(device, &max42500_regs[MAX42500_STATOFF]);


		for (vm_input = MAX42500_VM1; vm_input < MAX42500_VM_MAX; vm_input++) {      
			if ((max42500_regs[MAX42500_STATOFF].value >> vm_input) & 1) {
				printf("     IN%d status: Voltage is below OFF threshold\n\r", 
				       vm_input + 1);
			} else if ((max42500_regs[MAX42500_STATUV].value >> vm_input) & 1) {
				printf("     IN%d status: Undervoltage detected\n\r", 
				       vm_input + 1);
			} else if ((max42500_regs[MAX42500_STATOV].value >> vm_input) & 1) {
				printf("     IN%d status: Overvoltage detected\n\r", 
				       vm_input + 1);
			} else {
				printf("     IN%d status: Voltage is within acceptable range\n\r", 
				       vm_input + 1 );
			}

			no_os_mdelay(500);

		}

		printf("******************************************************\n\r");
	}
	
	return 0;
}
