/*!
 * @brief     SPI Register Definition Header File, automatically generated by
 *            yoda2h v1.1.2 at 1/2/2020 9:13:37 AM.
 *
 * @copyright copyright(c) 2018 - Analog Devices Inc.All Rights Reserved.
 *            This software is proprietary to Analog Devices, Inc. and its
 *            licensor. By using this software you agree to the terms of the
 *            associated analog devices software license agreement.
 */

/*!
 * @addtogroup AD9083_BF
 * @{
 */
#ifndef __ADI_AD9083_BF_TOP_CLK_REG_H__
#define __ADI_AD9083_BF_TOP_CLK_REG_H__

/*============= I N C L U D E S ============*/
#include "adi_ad9083_config.h"

/*============= D E F I N E S ==============*/

#define REG_RESET_REG_ADDR 0x00000D02
#define BF_D_CAL_RESET_INFO 0x00000D02, 0x00000101

#define REG_INPUT_MISC_REG_ADDR 0x00000D03
#define BF_D_REFIN_DIV_INFO 0x00000D03, 0x00000200

#define REG_CHARGEPUMP_REG_0_ADDR 0x00000D04
#define BF_D_CP_CURRENT_INFO 0x00000D04, 0x00000600

#define REG_DIVIDER_REG_ADDR 0x00000D09
#define BF_D_DIVIDE_CONTROL_INFO 0x00000D09, 0x00000600

#define REG_VCO_CAL_LOCK_REG_ADDR 0x00000D0C
#define BF_D_CONTROL_HS_FB_DIV_INFO 0x00000D0C, 0x00000204

#define REG_IMPALA_FILT_MAIN_0_ADDR 0x00000D21
#define BF_D_FILT_CBIG_INFO 0x00000D21, 0x00000600

#define REG_IMPALA_FILT_MAIN_1_ADDR 0x00000D22
#define BF_D_FILT_R_INFO 0x00000D22, 0x00000800

#define REG_IMPALA_FILT_MAIN_2_ADDR 0x00000D23
#define BF_D_FILT_CSMALL_INFO 0x00000D23, 0x00000600

#define REG_CLOCK_PD_ADDR 0x00000D40
#define BF_SPI_PLL_BYP_INFO 0x00000D40, 0x00000103

#define REG_CLOCK_DIVIDER_CNTRL_ADDR 0x00000D41
#define BF_SPI_CNTRL_HS_DIV_INFO 0x00000D41, 0x00000203

#define REG_IMPALA_READY_CNTRL_ADDR 0x00000D44
#define BF_PLL_LOCK_VALID_INFO 0x00000D44, 0x00000101
#define BF_PLL_OUTOFLOCK_INFO 0x00000D44, 0x00000102
#define BF_SPI_LOCK_VALID_RST_INFO 0x00000D44, 0x00000103
#define BF_SPI_OUTOFLOCK_RST_INFO 0x00000D44, 0x00000104

#define REG_SERDES_REFCLK_DIV_ADDR 0x00000D4A
#define BF_SPI_DIV_SERDES_INFO 0x00000D4A, 0x00000600

#define REG_SYSREF_IGNORE_ADDR 0x00000D4D
#define BF_SPI_SYSREF_DISABLE_INFO 0x00000D4D, 0x00000100
#define BF_SPI_SYSREF_IGNORE_COUNT_INFO 0x00000D4D, 0x00000401
#define BF_SPI_SYSREF_IGNORE_ENABLE_INFO 0x00000D4D, 0x00000105
#define BF_SPI_SYSREF_IGNORE_START_INFO 0x00000D4D, 0x00000106

#endif /* __ADI_AD9083_BF_TOP_CLK_REG_H__ */
       /*! @} */