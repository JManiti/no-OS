/***************************************************************************//**
 *   @file   max6613_app.c
 *   @brief  Implementation of basic MAX6613 example
 *   @author Mark Sapungan (Mark.Sapungan@analog.com)
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

int max42500_app_main(void)
{
	int ret;
	enum max42500_registers reg_nr;
	struct no_os_uart_desc *uart_desc;
	struct max42500_dev *device;

	ret = no_os_uart_init(&uart_desc, &uart_ip);
	if (ret)
		return ret;

	no_os_uart_stdio(uart_desc);

	printf("********** MAX42500 App **********\n\r");

	/* Initializing the device MAX42500 */
	ret = max42500_init(&device, &max42500_ip);
	if (ret) {
	  	printf("Error during initialization of the device\n");
		return ret;
	}
    
	/* Read all registers */
	for (reg_nr = MAX42500_ID; 
	    (reg_nr < MAX42500_REG_NO) && !(ret < 0); reg_nr++) {
		ret = max42500_reg_read(device, &max42500_regs[reg_nr]);
		if (ret) {
		  	printf("Error reading the MAX42500's register\n");
			goto free_max42500;
		}
	}

	printf("    MAX42500_ID: 0x%08x\n\r", max42500_regs[MAX42500_ID].value);
	printf("    MAX42500_CONFIG1: 0x%08x\n\r", max42500_regs[MAX42500_CONFIG1].value);
	printf("    MAX42500_CONFIG2: 0x%08x\n\r", max42500_regs[MAX42500_CONFIG2].value);
	printf("    MAX42500_VMON: 0x%08x\n\r", max42500_regs[MAX42500_VMON].value);
	printf("    MAX42500_RSTMAP: 0x%08x\n\r", max42500_regs[MAX42500_RSTMAP].value);
	printf("    MAX42500_STATOV: 0x%08x\n\r", max42500_regs[MAX42500_STATOV].value);
	printf("    MAX42500_STATUV: 0x%08x\n\r", max42500_regs[MAX42500_STATUV].value);
	printf("    MAX42500_STATOFF: 0x%08x\n\r", max42500_regs[MAX42500_STATOFF].value);
	printf("    MAX42500_VIN1: 0x%08x\n\r", max42500_regs[MAX42500_VIN1].value);
	printf("    MAX42500_VIN2: 0x%08x\n\r", max42500_regs[MAX42500_VIN2].value);
	printf("    MAX42500_VIN3: 0x%08x\n\r", max42500_regs[MAX42500_VIN3].value);
	printf("    MAX42500_VIN4: 0x%08x\n\r", max42500_regs[MAX42500_VIN4].value);
	printf("    MAX42500_VIN5: 0x%08x\n\r", max42500_regs[MAX42500_VIN5].value);
	printf("    MAX42500_VINO6: 0x%08x\n\r", max42500_regs[MAX42500_VINO6].value);
	printf("    MAX42500_VINU6: 0x%08x\n\r", max42500_regs[MAX42500_VINU6].value);
	printf("    MAX42500_VINO7: 0x%08x\n\r", max42500_regs[MAX42500_VINO7].value);
	printf("    MAX42500_VINU7: 0x%08x\n\r", max42500_regs[MAX42500_VINU7].value);
	printf("    MAX42500_OVUV1: 0x%08x\n\r", max42500_regs[MAX42500_OVUV1].value);
	printf("    MAX42500_OVUV2: 0x%08x\n\r", max42500_regs[MAX42500_OVUV2].value);
	printf("    MAX42500_OVUV3: 0x%08x\n\r", max42500_regs[MAX42500_OVUV3].value);
	printf("    MAX42500_OVUV4: 0x%08x\n\r", max42500_regs[MAX42500_OVUV4].value);
	printf("    MAX42500_OVUV5: 0x%08x\n\r", max42500_regs[MAX42500_OVUV5].value);
	printf("    MAX42500_FPSSTAT1: 0x%08x\n\r", max42500_regs[MAX42500_FPSSTAT1].value);
	printf("    MAX42500_FPSCFG1: 0x%08x\n\r", max42500_regs[MAX42500_FPSCFG1].value);
	printf("    MAX42500_UTIME1: 0x%08x\n\r", max42500_regs[MAX42500_UTIME1].value);
	printf("    MAX42500_UTIME2: 0x%08x\n\r", max42500_regs[MAX42500_UTIME2].value);
	printf("    MAX42500_UTIME3: 0x%08x\n\r", max42500_regs[MAX42500_UTIME3].value);
	printf("    MAX42500_UTIME4: 0x%08x\n\r", max42500_regs[MAX42500_UTIME4].value);
	printf("    MAX42500_UTIME5: 0x%08x\n\r", max42500_regs[MAX42500_UTIME5].value);
	printf("    MAX42500_UTIME6: 0x%08x\n\r", max42500_regs[MAX42500_UTIME6].value);
	printf("    MAX42500_UTIME7: 0x%08x\n\r", max42500_regs[MAX42500_UTIME7].value);
	printf("    MAX42500_DTIME1: 0x%08x\n\r", max42500_regs[MAX42500_DTIME1].value);
	printf("    MAX42500_DTIME2: 0x%08x\n\r", max42500_regs[MAX42500_DTIME2].value);
	printf("    MAX42500_DTIME3: 0x%08x\n\r", max42500_regs[MAX42500_DTIME3].value);
	printf("    MAX42500_DTIME4: 0x%08x\n\r", max42500_regs[MAX42500_DTIME4].value);
	printf("    MAX42500_DTIME5: 0x%08x\n\r", max42500_regs[MAX42500_DTIME5].value);
	printf("    MAX42500_DTIME6: 0x%08x\n\r", max42500_regs[MAX42500_DTIME6].value);
	printf("    MAX42500_DTIME7: 0x%08x\n\r", max42500_regs[MAX42500_DTIME7].value);
	printf("    MAX42500_WDSTAT: 0x%08x\n\r", max42500_regs[MAX42500_WDSTAT].value);
	printf("    MAX42500_WDCDIV: 0x%08x\n\r", max42500_regs[MAX42500_WDCDIV].value);
	printf("    MAX42500_WDCFG1: 0x%08x\n\r", max42500_regs[MAX42500_WDCFG1].value);
	printf("    MAX42500_WDCFG2: 0x%08x\n\r", max42500_regs[MAX42500_WDCFG2].value);
	printf("    MAX42500_WDKEY: 0x%08x\n\r", max42500_regs[MAX42500_WDKEY].value);
	printf("    MAX42500_WDLOCK: 0x%08x\n\r", max42500_regs[MAX42500_WDLOCK].value);
	printf("    MAX42500_RSTCTRL: 0x%08x\n\r", max42500_regs[MAX42500_RSTCTRL].value);
	printf("    MAX42500_CID: 0x%08x\n\r", max42500_regs[MAX42500_CID].value);
	
	/* Enable voltage monitor 3*/
	max42500_reg_write2(device, MAX42500_VMON, 
			    max42500_regs[MAX42500_VMON].value | MAX42500_VMON_IN_MASK(MAX42500_VM3));

	printf("\n    Updated register value:\n\r");
	printf("    MAX42500_VMON: 0x%08x\n\r", max42500_regs[MAX42500_VMON].value);

free_max42500:
	max42500_remove(device);
	
	return 0;
}