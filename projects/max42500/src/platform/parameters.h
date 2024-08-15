/***************************************************************************//**
 *   @file   parameters.h
 *   @brief  Definitions specific to Hockey Puck platform.
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
#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

/* MAX42500 parameters */
#define MAX42500_I2C_DEVICE_ID  (0)/////////////////////////////////////////////////////////////1
#define MAX42500_I2C_CLK_SPEED  (400000)
#define MAX42500_I2C_ADDR       MAX42500_ADDR(0)
#define MAX42500_EN0_PORT       (2)////////////////////////////////////////////////////////////2
#define MAX42500_EN0_PIN        (26)///////////////////////////////////////////////////////////7
#define MAX42500_EN1_PORT       (2)//////////////////////////////////////////////////////////2
#define MAX42500_EN1_PIN        (29)///////////////////////////////////////////////////////////8
#define MAX42500_ADDR_PORT      (2)
#define MAX42500_ADDR_PIN       (9)
#define MAX42500_ADDR_SEL       (0)
#define MAX42500_PECE           (true)
#define MAX42500_VMON_EN        (0x00)
#define MAX42500_VMON_VMPD      (true)
#define MAX42500_RESET_MAP      (MAX42500_RSTMAP_IN_MASK(MAX42500_VM1) | \
				 MAX42500_RSTMAP_IN_MASK(MAX42500_VM2) | \
                                 MAX42500_RSTMAP_IN_MASK(MAX42500_VM3) | \
                                 MAX42500_RSTMAP_IN_MASK(MAX42500_VM4) | \
				 MAX42500_RSTMAP_IN_MASK(MAX42500_VM5) | \
				 MAX42500_RSTMAP_IN_MASK(MAX42500_VM6) | \
				 MAX42500_RSTMAP_IN_MASK(MAX42500_VM7) | \
                                 MAX42500_RSTMAP_PARM_MASK)
#define MAX42500_WD_MODE        MAX42500_WD_MODE_SIMPLE
#define MAX42500_WD_CDIV        (0x00)
#define MAX42500_WD_CLOSE       (0x00)
#define MAX42500_WD_OPEN        (0x00)
#define MAX42500_WD_1UD         (0x00)
#define MAX42500_WD_EN          (false)//////////////////////////////////////////////////// true
#define MAX42500_TIMER_ID       (0)
#define MAX42500_TIMER_FREQ     (32000)
#define MAX42500_TIMER_COUNT    (52)
#define MAX42500_IRQ_ID         (0)

#endif /* __PARAMETERS_H__ */
