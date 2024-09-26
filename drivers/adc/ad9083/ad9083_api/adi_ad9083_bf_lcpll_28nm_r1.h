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
#ifndef __ADI_AD9083_BF_LCPLL_28NM_R1_H__
#define __ADI_AD9083_BF_LCPLL_28NM_R1_H__

/*============= I N C L U D E S ============*/
#include "adi_ad9083_config.h"

/*============= D E F I N E S ==============*/
#define REG_LCPLL_RST_ADDR 0x00000500
#define BF_RSTB_LCPLL_RC_INFO 0x00000500, 0x00000100

#define REG_PLL_ENABLE_CTRL_ADDR 0x00000501
#define BF_PWRUP_LCPLL_INFO 0x00000501, 0x00000100
#define BF_LDSYNTH_FORCE_LCPLL_ADC_INFO 0x00000501, 0x00000101
#define BF_LOLSTICKYCLEAR_FORCE_LCPLL_RC_INFO 0x00000501, 0x00000103
#define BF_LCPLL_JTX_PLL_BYPASS_LOCK_INFO 0x00000501, 0x00000105
#define BF_PLL_LOCKED_BYPASS_INFO 0x00000501, 0x00000106
#define BF_PLL_LOCKED_BYPASS_VAL_INFO 0x00000501, 0x00000107

#define REG_PLL_STATUS_LCPLL_ADDR 0x00000502
#define BF_LCPLLLOCK_LCPLL_RS_INFO 0x00000502, 0x00000100
#define BF_REGULATORRDY_LCPLL_RS_INFO 0x00000502, 0x00000101
#define BF_VCOCALINPROG_LCPLL_RS_INFO 0x00000502, 0x00000102
#define BF_RFPLLLOCK_LCPLL_RS_INFO 0x00000502, 0x00000103
#define BF_LOSSLOCK_LCPLL_RS_INFO 0x00000502, 0x00000104

#define REG_PLL_PWR_UP1_ADDR 0x00000503
#define BF_PWRUP_ADC_LCPLL_RC_INFO 0x00000503, 0x00000101
#define BF_PWRUP_CP_LCPLL_RC_INFO 0x00000503, 0x00000102
#define BF_PWRUP_DIV_LCPLL_RC_INFO 0x00000503, 0x00000103
#define BF_PWRUP_PEAKDET_LCPLL_RC_INFO 0x00000503, 0x00000104
#define BF_PWRUP_PLLBIAS_LCPLL_RC_INFO 0x00000503, 0x00000105
#define BF_PWRUP_VCO_LCPLL_RC_INFO 0x00000503, 0x00000106
#define BF_PWRUP_REG_LCPLL_RC_INFO 0x00000503, 0x00000107

#define REG_PLL_PWR_UP2_ADDR 0x00000504
#define BF_PWRUP_REFCLK_LCPLL_RC_INFO 0x00000504, 0x00000100
#define BF_PWRUP_VCOVAR_LCPLL_RC_INFO 0x00000504, 0x00000101
#define BF_PWRUP_VCOBUF_LCPLL_RC_INFO 0x00000504, 0x00000102
#define BF_PWRUP_VCOVARBIAS_LCPLL_RC_INFO 0x00000504, 0x00000103
#define BF_PWRUP_ADCAUX_LCPLL_RC_INFO 0x00000504, 0x00000106

#define REG_PLL_PWR_UP3_ADDR 0x00000505
#define BF_PWRUP_VCOBIAS_LCPLL_RC_INFO 0x00000505, 0x00000400

#define REG_PLL_ENCAL_ADDR 0x00000506
#define BF_EN_OCTAVECAL_LCPLL_RC_INFO 0x00000506, 0x00000100
#define BF_EN_TX_ONLY_LCPLL_RC_INFO 0x00000506, 0x00000101
#define BF_PD_RXCLK_DIST_RC_INFO 0x00000506, 0x00000103
#define BF_PD_TXCLK_DIST_RC_INFO 0x00000506, 0x00000104

#define REG_LCPLL_REF_CLK_DIV1_REG_ADDR 0x00000507
#define BF_REFINDIV_LCPLL_RC_INFO 0x00000507, 0x00000300
#define BF_DIVM_LCPLL_RC_INFO 0x00000507, 0x00000204
#define BF_DIVP_LCPLL_RC_INFO 0x00000507, 0x00000106
#define BF_REFCK_DIV40BDIV120_LCPLL_INFO 0x00000507, 0x00000107

#define REG_PLL_DIV2_ADDR 0x00000508
#define BF_B_LCPLL_RC_INFO 0x00000508, 0x00000800

#define REG_PLL_RXDIVRATE_STATUS_ADDR 0x00000509
#define BF_RXDIVRATE_LCPLL_RS_INFO 0x00000509, 0x00000400
#define BF_DIVM_LCPLL_RS_INFO 0x00000509, 0x00000204

#define REG_PLL_DIVOVD_ADDR 0x0000050A
#define BF_BOVD_LCPLL_RC_INFO 0x0000050A, 0x00000100
#define BF_DIVMOVD_LCPLL_RC_INFO 0x0000050A, 0x00000101
#define BF_REFINDIVOVD_LCPLL_RC_INFO 0x0000050A, 0x00000102
#define BF_RXDIVRATEOVD_LCPLL_RC_INFO 0x0000050A, 0x00000103

#define REG_PLL_RXDIVRATE_ADDR 0x0000050B
#define BF_RXDIVRATE_LCPLL_RC_INFO 0x0000050B, 0x00000400

#define REG_PLL_VCO_TRIM_ADDR 0x0000050C
#define BF_VCORTRIM_LCPLL_RC_INFO 0x0000050C, 0x00000600

#define REG_PLL_REFCLK_CPL_ADDR 0x0000050D
#define BF_SEL_REFCKDCACB_LCPLL_RC_INFO 0x0000050D, 0x00000100
#define BF_SEL_REFINDIV3_LCPLL_RC_INFO 0x0000050D, 0x00000101
#define BF_DIGCLK_REFIN_DIV_RC_INFO 0x0000050D, 0x00000304

#define REG_CBUS_REN_LCPLL_ADDR 0x0000050E
#define BF_LCPLL_CBUS_REN_LCPLL_RC_INFO 0x0000050E, 0x00000100

#define REG_CBUS_WSTROBE_LCPLL_ADDR 0x0000050F
#define BF_LCPLL_CBUS_WSTROBE_LCPLL_RC_INFO 0x0000050F, 0x00000100

#define REG_CKDIST_PD_ADDR 0x00000510
#define BF_PD_PPF_DES_RC_INFO 0x00000510, 0x00000100
#define BF_IDIST_PD_RC_INFO 0x00000510, 0x00000101

#define REG_POLYPHASE_CTRL_ADDR 0x00000511
#define BF_TRIM_POLYPHASE_DES_RC_INFO 0x00000511, 0x00000800

#define REG_PLL_READ_FREQ4_ADDR 0x00000512
#define BF_VCOFREQBAND_LCPLL_RS_INFO 0x00000512, 0x00000B00

#define REG_PLL_PTAT_STARTUP_ADDR 0x00000514
#define BF_PTAT_STARTUP_LCPLL_RC_INFO 0x00000514, 0x00000800

#define REG_PLL_PTAT_STARTUP_STATUS1_ADDR 0x00000515
#define BF_PTAT_STARTUP_STATUS_RS1_INFO 0x00000515, 0x00000100

#define REG_PLL_PTAT_STARTUP_STATUS2_ADDR 0x00000516
#define BF_PTAT_STARTUP_STATUS_RS2_INFO 0x00000516, 0x00000100

#define REG_PLL_TEMP_ADDR 0x00000517
#define BF_TDEGCINIT_LCPLL_RC_INFO 0x00000517, 0x00000100

#define REG_PLL_READ_TEMP1_ADDR 0x0000051A
#define BF_TDEGC_LCPLL_RS_INFO 0x0000051A, 0x00000C00

#define REG_PLL_LDSYNTH_DELAY_ADDR 0x0000051D
#define BF_LDSYNTH_LCPLL_HIGH_INFO 0x0000051D, 0x00000400
#define BF_LDSYNTH_LCPLL_WARMUP_INFO 0x0000051D, 0x00000404

#define REG_PLL_LOCK_CTL1_ADDR 0x0000051E
#define BF_LCPLL_LOCK_SEL_INFO 0x0000051E, 0x00000100
#define BF_LCPLL_LOCK_DIVIDER_INFO 0x0000051E, 0x00000A04

#define REG_CBUS_ADDR_LCPLL_ADDR 0x00000520
#define BF_LCPLL_CBUS_ADDR_LCPLL_RC_INFO 0x00000520, 0x00000800

#define REG_CBUS_WDATA_LCPLL_ADDR 0x00000521
#define BF_LCPLL_CBUS_WDATA_LCPLL_RC_INFO 0x00000521, 0x00000800

#define REG_CBUS_RDATA_LCPLL_ADDR 0x00000522
#define BF_LCPLL_CBUS_RDATA_LCPLL_RS_INFO 0x00000522, 0x00000800

#define REG_REFCLK_CTRL_ADDR 0x00000523
#define BF_EN_REFCLK_RCVR_RC_INFO 0x00000523, 0x00000100
#define BF_SEL_SYNCA_FOR_REFCLK_RC_INFO 0x00000523, 0x00000101
#define BF_SEL_REFCLK_RCVR_LP_MODE_RC_INFO 0x00000523, 0x00000102
#define BF_SEL_REFCLK_RCVR_CM_CTRL_INFO 0x00000523, 0x00000403

#define REG_SERDES_REV_ID_RS_LCPLL_ADDR 0x00000524
#define BF_LCPLL_SERDES_REV_ID_RS_INFO 0x00000524, 0x00000800

#define REG_SPARE0_ADDR 0x00000525
#define BF_LCPLL_SPARE0_INFO 0x00000525, 0x00000800

#define REG_SPARE1_ADDR 0x00000526
#define BF_LCPLL_SPARE1_INFO 0x00000526, 0x00000800

#define REG_SPARE2_ADDR 0x00000527
#define BF_LCPLL_SPARE2_INFO 0x00000527, 0x00000800

#define REG_SPARE3_ADDR 0x00000528
#define BF_LCPLL_SPARE3_INFO 0x00000528, 0x00000800

#define REG_SPARE4_ADDR 0x00000529
#define BF_LCPLL_SPARE4_INFO 0x00000529, 0x00000800

#define REG_SPARE5_ADDR 0x0000052A
#define BF_LCPLL_SPARE5_INFO 0x0000052A, 0x00000800

#define REG_SPARE6_ADDR 0x0000052B
#define BF_LCPLL_SPARE6_INFO 0x0000052B, 0x00000800

#define REG_SPARE7_ADDR 0x0000052C
#define BF_LCPLL_SPARE7_INFO 0x0000052C, 0x00000800

#endif /* __ADI_AD9083_BF_LCPLL_28NM_R1_H__ */
       /*! @} */