/*
 * File:           C:\Google Disk\USBAudioADAU1772\sigmaDSP1772\sigmaDSP1772_IC_1.h
 *
 * Created:        Thursday, April 21, 2016 9:23:29 PM
 * Description:    sigmaDSP1772:IC 1 program data.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright ©2016 Analog Devices, Inc. All rights reserved.
 */
#ifndef __SIGMADSP1772_IC_1_H__
#define __SIGMADSP1772_IC_1_H__

#include "SigmaStudioFW.h"
#include "sigmaDSP1772_IC_1_REG.h"

#define DEVICE_ARCHITECTURE_IC_1                  "ADAU1772"
#define DEVICE_ADDR_IC_1                          0x0

/* DSP Program Data */
#define PROGRAM_SIZE_IC_1 64
#define PROGRAM_ADDR_IC_1 128
ADI_REG_TYPE Program_Data_IC_1[PROGRAM_SIZE_IC_1] = {
0x00, 0x80, 
0x01, 0x80, 
0x00, 0x81, 
0x01, 0x81, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
0x00, 0x00, 
};


/* Register Default - IC 1.DAC0_VOLUME */
ADI_REG_TYPE R0_DAC0_VOLUME_IC_1_Default[REG_DAC0_VOLUME_IC_1_BYTE] = {
0xFF
};

/* Register Default - IC 1.DAC1_VOLUME */
ADI_REG_TYPE R1_DAC1_VOLUME_IC_1_Default[REG_DAC1_VOLUME_IC_1_BYTE] = {
0xFF
};

/* Register Default - IC 1.OP_STAGE_MUTES */
ADI_REG_TYPE R2_OP_STAGE_MUTES_IC_1_Default[REG_OP_STAGE_MUTES_IC_1_BYTE] = {
0x0F
};

/* Register Default - IC 1.PLL_CTRL0 Register */
ADI_REG_TYPE R3_PLL_CTRL0_IC_1_Default[REG_PLL_CTRL0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PLL_CTRL1 Register */
ADI_REG_TYPE R4_PLL_CTRL1_IC_1_Default[REG_PLL_CTRL1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PLL_CTRL2 Register */
ADI_REG_TYPE R5_PLL_CTRL2_IC_1_Default[REG_PLL_CTRL2_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PLL_CTRL3 Register */
ADI_REG_TYPE R6_PLL_CTRL3_IC_1_Default[REG_PLL_CTRL3_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PLL_CTRL4 Register */
ADI_REG_TYPE R7_PLL_CTRL4_IC_1_Default[REG_PLL_CTRL4_IC_1_BYTE] = {
0x20
};

/* Register Default - IC 1.PLL_CTRL5 Register */
ADI_REG_TYPE R8_PLL_CTRL5_IC_1_Default[REG_PLL_CTRL5_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.CORE_CONTROL */
ADI_REG_TYPE R9_CORE_CONTROL_IC_1_Default[REG_CORE_CONTROL_IC_1_BYTE] = {
0x02
};

/* Register Default - IC 1.CORE_CONTROL */
ADI_REG_TYPE R10_CORE_CONTROL_IC_1_Default[REG_CORE_CONTROL_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.CLK_CONTROL Register */
ADI_REG_TYPE R11_CLK_CONTROL_IC_1_Default[REG_CLK_CONTROL_IC_1_BYTE] = {
0x07
};

/* Register Default - IC 1.Delay */
#define R12_DELAY_IC_1_ADDR 0x0
#define R12_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R12_DELAY_IC_1_Default[R12_DELAY_IC_1_SIZE] = {
0x00, 0x05
};

/* Register Default - IC 1.CLKOUT_SEL Register */
ADI_REG_TYPE R13_CLKOUT_SEL_IC_1_Default[REG_CLKOUT_SEL_IC_1_BYTE] = {
0x07
};

/* Register Default - IC 1.REGULATOR Register */
ADI_REG_TYPE R14_REGULATOR_IC_1_Default[REG_REGULATOR_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.CORE_CONTROL Register */
ADI_REG_TYPE R15_CORE_CONTROL_IC_1_Default[REG_CORE_CONTROL_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.SLEEP_INST Register */
ADI_REG_TYPE R16_SLEEP_INST_IC_1_Default[REG_SLEEP_INST_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.CORE_ENABLE Register */
ADI_REG_TYPE R17_CORE_ENABLE_IC_1_Default[REG_CORE_ENABLE_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.ABSREG0 Register */
ADI_REG_TYPE R18_DBREG0_IC_1_Default[REG_DBREG0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ABSREG1 Register */
ADI_REG_TYPE R19_DBREG1_IC_1_Default[REG_DBREG1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ABSREG2 Register */
ADI_REG_TYPE R20_DBREG2_IC_1_Default[REG_DBREG2_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.CORE_IN_MUX_0_1 Register */
ADI_REG_TYPE R21_CORE_IN_MUX_0_1_IC_1_Default[REG_CORE_IN_MUX_0_1_IC_1_BYTE] = {
0x10
};

/* Register Default - IC 1.CORE_IN_MUX_2_3 Register */
ADI_REG_TYPE R22_CORE_IN_MUX_2_3_IC_1_Default[REG_CORE_IN_MUX_2_3_IC_1_BYTE] = {
0x32
};

/* Register Default - IC 1.DAC_SOURCE_0_1 Register */
ADI_REG_TYPE R23_DAC_SOURCE_0_1_IC_1_Default[REG_DAC_SOURCE_0_1_IC_1_BYTE] = {
0x10
};

/* Register Default - IC 1.PDM_SOURCE_0_1 Register */
ADI_REG_TYPE R24_PDM_SOURCE_0_1_IC_1_Default[REG_PDM_SOURCE_0_1_IC_1_BYTE] = {
0x32
};

/* Register Default - IC 1.SOUT_SOURCE_0_1 Register */
ADI_REG_TYPE R25_SOUT_SOURCE_0_1_IC_1_Default[REG_SOUT_SOURCE_0_1_IC_1_BYTE] = {
0x54
};

/* Register Default - IC 1.SOUT_SOURCE_2_3 Register */
ADI_REG_TYPE R26_SOUT_SOURCE_2_3_IC_1_Default[REG_SOUT_SOURCE_2_3_IC_1_BYTE] = {
0x76
};

/* Register Default - IC 1.SOUT_SOURCE_4_5 Register */
ADI_REG_TYPE R27_SOUT_SOURCE_4_5_IC_1_Default[REG_SOUT_SOURCE_4_5_IC_1_BYTE] = {
0x54
};

/* Register Default - IC 1.SOUT_SOURCE_6_7 Register */
ADI_REG_TYPE R28_SOUT_SOURCE_6_7_IC_1_Default[REG_SOUT_SOURCE_6_7_IC_1_BYTE] = {
0x76
};

/* Register Default - IC 1.ADC_SDATA_CH Register */
ADI_REG_TYPE R29_ADC_SDATA_CH_IC_1_Default[REG_ADC_SDATA_CH_IC_1_BYTE] = {
0x04
};

/* Register Default - IC 1.ASRCO_SOURCE_0_1 Register */
ADI_REG_TYPE R30_ASRCO_SOURCE_0_1_IC_1_Default[REG_ASRCO_SOURCE_0_1_IC_1_BYTE] = {
0x10
};

/* Register Default - IC 1.ASRCO_SOURCE_2_3 Register */
ADI_REG_TYPE R31_ASRCO_SOURCE_2_3_IC_1_Default[REG_ASRCO_SOURCE_2_3_IC_1_BYTE] = {
0x32
};

/* Register Default - IC 1.ASRC_MODE Register */
ADI_REG_TYPE R32_ASRC_MODE_IC_1_Default[REG_ASRC_MODE_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ADC_CONTROL0 Register */
ADI_REG_TYPE R33_ADC_CONTROL0_IC_1_Default[REG_ADC_CONTROL0_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.ADC_CONTROL1 Register */
ADI_REG_TYPE R34_ADC_CONTROL1_IC_1_Default[REG_ADC_CONTROL1_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.ADC_CONTROL2 Register */
ADI_REG_TYPE R35_ADC_CONTROL2_IC_1_Default[REG_ADC_CONTROL2_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.ADC_CONTROL3 Register */
ADI_REG_TYPE R36_ADC_CONTROL3_IC_1_Default[REG_ADC_CONTROL3_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.ADC0_VOLUME Register */
ADI_REG_TYPE R37_ADC0_VOLUME_IC_1_Default[REG_ADC0_VOLUME_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ADC1_VOLUME Register */
ADI_REG_TYPE R38_ADC1_VOLUME_IC_1_Default[REG_ADC1_VOLUME_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ADC2_VOLUME Register */
ADI_REG_TYPE R39_ADC2_VOLUME_IC_1_Default[REG_ADC2_VOLUME_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.ADC3_VOLUME Register */
ADI_REG_TYPE R40_ADC3_VOLUME_IC_1_Default[REG_ADC3_VOLUME_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PGA_CONTROL_0 Register */
ADI_REG_TYPE R41_PGA_CONTROL_0_IC_1_Default[REG_PGA_CONTROL_0_IC_1_BYTE] = {
0x6B
};

/* Register Default - IC 1.PGA_CONTROL_1 Register */
ADI_REG_TYPE R42_PGA_CONTROL_1_IC_1_Default[REG_PGA_CONTROL_1_IC_1_BYTE] = {
0x6B
};

/* Register Default - IC 1.PGA_CONTROL_2 Register */
ADI_REG_TYPE R43_PGA_CONTROL_2_IC_1_Default[REG_PGA_CONTROL_2_IC_1_BYTE] = {
0x6B
};

/* Register Default - IC 1.PGA_CONTROL_3 Register */
ADI_REG_TYPE R44_PGA_CONTROL_3_IC_1_Default[REG_PGA_CONTROL_3_IC_1_BYTE] = {
0x6B
};

/* Register Default - IC 1.PGA_STEP_CONTROL Register */
ADI_REG_TYPE R45_PGA_STEP_CONTROL_IC_1_Default[REG_PGA_STEP_CONTROL_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PGA_10DB_BOOST Register */
ADI_REG_TYPE R46_PGA_10DB_BOOST_IC_1_Default[REG_PGA_10DB_BOOST_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.POP_SUPPRESS Register */
ADI_REG_TYPE R47_POP_SUPPRESS_IC_1_Default[REG_POP_SUPPRESS_IC_1_BYTE] = {
0x3F
};

/* Register Default - IC 1.TALKTHRU Register */
ADI_REG_TYPE R48_TALKTHRU_IC_1_Default[REG_TALKTHRU_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.TALKTHRU_GAIN0 Register */
ADI_REG_TYPE R49_TALKTHRU_GAIN0_IC_1_Default[REG_TALKTHRU_GAIN0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.TALKTHRU_GAIN1 Register */
ADI_REG_TYPE R50_TALKTHRU_GAIN1_IC_1_Default[REG_TALKTHRU_GAIN1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MIC_BIAS Register */
ADI_REG_TYPE R51_MIC_BIAS_IC_1_Default[REG_MIC_BIAS_IC_1_BYTE] = {
0x30
};

/* Register Default - IC 1.DAC_CONTROL1 Register */
ADI_REG_TYPE R52_DAC_CONTROL1_IC_1_Default[REG_DAC_CONTROL1_IC_1_BYTE] = {
0x03
};

/* Register Default - IC 1.DAC0_VOLUME Register */
ADI_REG_TYPE R53_DAC0_VOLUME_IC_1_Default[REG_DAC0_VOLUME_IC_1_BYTE] = {
0xFF
};

/* Register Default - IC 1.DAC1_VOLUME Register */
ADI_REG_TYPE R54_DAC1_VOLUME_IC_1_Default[REG_DAC1_VOLUME_IC_1_BYTE] = {
0xFF
};

/* Register Default - IC 1.OP_STAGE_MUTES Register */
ADI_REG_TYPE R55_OP_STAGE_MUTES_IC_1_Default[REG_OP_STAGE_MUTES_IC_1_BYTE] = {
0x0F
};

/* Register Default - IC 1.SAI_0 Register */
ADI_REG_TYPE R56_SAI_0_IC_1_Default[REG_SAI_0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.SAI_1 Register */
ADI_REG_TYPE R57_SAI_1_IC_1_Default[REG_SAI_1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.SOUT_CONTROL0 Register */
ADI_REG_TYPE R58_SOUT_CONTROL0_IC_1_Default[REG_SOUT_CONTROL0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.SOUT_CONTROL1 Register */
ADI_REG_TYPE R59_SOUT_CONTROL1_IC_1_Default[REG_SOUT_CONTROL1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PDM_OUT Register */
ADI_REG_TYPE R60_PDM_OUT_IC_1_Default[REG_PDM_OUT_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PDM_PATTERN Register */
ADI_REG_TYPE R61_PDM_PATTERN_IC_1_Default[REG_PDM_PATTERN_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP0 Register */
ADI_REG_TYPE R62_MODE_MP0_IC_1_Default[REG_MODE_MP0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP1 Register */
ADI_REG_TYPE R63_MODE_MP1_IC_1_Default[REG_MODE_MP1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP2 Register */
ADI_REG_TYPE R64_MODE_MP2_IC_1_Default[REG_MODE_MP2_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP3 Register */
ADI_REG_TYPE R65_MODE_MP3_IC_1_Default[REG_MODE_MP3_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP4 Register */
ADI_REG_TYPE R66_MODE_MP4_IC_1_Default[REG_MODE_MP4_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP5 Register */
ADI_REG_TYPE R67_MODE_MP5_IC_1_Default[REG_MODE_MP5_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.MODE_MP6 Register */
ADI_REG_TYPE R68_MODE_MP6_IC_1_Default[REG_MODE_MP6_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PB_VOL_SET Register */
ADI_REG_TYPE R69_PB_VOL_SET_IC_1_Default[REG_PB_VOL_SET_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PB_VOL_CONV Register */
ADI_REG_TYPE R70_PB_VOL_CONV_IC_1_Default[REG_PB_VOL_CONV_IC_1_BYTE] = {
0x87
};

/* Register Default - IC 1.DEBOUNCE_MODE Register */
ADI_REG_TYPE R71_DEBOUNCE_MODE_IC_1_Default[REG_DEBOUNCE_MODE_IC_1_BYTE] = {
0x05
};

/* Register Default - IC 1.RESERVED Register */
ADI_REG_TYPE R72_RESERVED_IC_1_Default[REG_RESERVED_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.OP_STAGE_CTRL Register */
ADI_REG_TYPE R73_OP_STAGE_CTRL_IC_1_Default[REG_OP_STAGE_CTRL_IC_1_BYTE] = {
0x30
};

/* Register Default - IC 1.DECIM_PWR_MODES Register */
ADI_REG_TYPE R74_DECIM_PWR_MODES_IC_1_Default[REG_DECIM_PWR_MODES_IC_1_BYTE] = {
0x0F
};

/* Register Default - IC 1.INTERP_PWR_MODES Register */
ADI_REG_TYPE R75_INTERP_PWR_MODES_IC_1_Default[REG_INTERP_PWR_MODES_IC_1_BYTE] = {
0x0C
};

/* Register Default - IC 1.BIAS_CONTROL0 Register */
ADI_REG_TYPE R76_BIAS_CONTROL0_IC_1_Default[REG_BIAS_CONTROL0_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.BIAS_CONTROL1 Register */
ADI_REG_TYPE R77_BIAS_CONTROL1_IC_1_Default[REG_BIAS_CONTROL1_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PAD_CONTROL0 Register */
ADI_REG_TYPE R78_PAD_CONTROL0_IC_1_Default[REG_PAD_CONTROL0_IC_1_BYTE] = {
0x7F
};

/* Register Default - IC 1.PAD_CONTROL1 Register */
ADI_REG_TYPE R79_PAD_CONTROL1_IC_1_Default[REG_PAD_CONTROL1_IC_1_BYTE] = {
0x13
};

/* Register Default - IC 1.PAD_CONTROL2 Register */
ADI_REG_TYPE R80_PAD_CONTROL2_IC_1_Default[REG_PAD_CONTROL2_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PAD_CONTROL3 Register */
ADI_REG_TYPE R81_PAD_CONTROL3_IC_1_Default[REG_PAD_CONTROL3_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PAD_CONTROL4 Register */
ADI_REG_TYPE R82_PAD_CONTROL4_IC_1_Default[REG_PAD_CONTROL4_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.PAD_CONTROL5 Register */
ADI_REG_TYPE R83_PAD_CONTROL5_IC_1_Default[REG_PAD_CONTROL5_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.OP_STAGE_MUTES */
ADI_REG_TYPE R87_OP_STAGE_MUTES_IC_1_Default[REG_OP_STAGE_MUTES_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.DAC0_VOLUME */
ADI_REG_TYPE R88_DAC0_VOLUME_IC_1_Default[REG_DAC0_VOLUME_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.DAC1_VOLUME */
ADI_REG_TYPE R89_DAC1_VOLUME_IC_1_Default[REG_DAC1_VOLUME_IC_1_BYTE] = {
0x00
};


/*
 * Default Download
 */
#define DEFAULT_DOWNLOAD_SIZE_IC_1 90

void default_download_IC_1() {
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC0_VOLUME_IC_1_ADDR, REG_DAC0_VOLUME_IC_1_BYTE, R0_DAC0_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC1_VOLUME_IC_1_ADDR, REG_DAC1_VOLUME_IC_1_BYTE, R1_DAC1_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_OP_STAGE_MUTES_IC_1_ADDR, REG_OP_STAGE_MUTES_IC_1_BYTE, R2_OP_STAGE_MUTES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL0_IC_1_ADDR, REG_PLL_CTRL0_IC_1_BYTE, R3_PLL_CTRL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL1_IC_1_ADDR, REG_PLL_CTRL1_IC_1_BYTE, R4_PLL_CTRL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL2_IC_1_ADDR, REG_PLL_CTRL2_IC_1_BYTE, R5_PLL_CTRL2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL3_IC_1_ADDR, REG_PLL_CTRL3_IC_1_BYTE, R6_PLL_CTRL3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL4_IC_1_ADDR, REG_PLL_CTRL4_IC_1_BYTE, R7_PLL_CTRL4_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL5_IC_1_ADDR, REG_PLL_CTRL5_IC_1_BYTE, R8_PLL_CTRL5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_CONTROL_IC_1_ADDR, REG_CORE_CONTROL_IC_1_BYTE, R9_CORE_CONTROL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_CONTROL_IC_1_ADDR, REG_CORE_CONTROL_IC_1_BYTE, R10_CORE_CONTROL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CLK_CONTROL_IC_1_ADDR, REG_CLK_CONTROL_IC_1_BYTE, R11_CLK_CONTROL_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R12_DELAY_IC_1_SIZE, R12_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CLKOUT_SEL_IC_1_ADDR, REG_CLKOUT_SEL_IC_1_BYTE, R13_CLKOUT_SEL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_REGULATOR_IC_1_ADDR, REG_REGULATOR_IC_1_BYTE, R14_REGULATOR_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_CONTROL_IC_1_ADDR, REG_CORE_CONTROL_IC_1_BYTE, R15_CORE_CONTROL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SLEEP_INST_IC_1_ADDR, REG_SLEEP_INST_IC_1_BYTE, R16_SLEEP_INST_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_ENABLE_IC_1_ADDR, REG_CORE_ENABLE_IC_1_BYTE, R17_CORE_ENABLE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DBREG0_IC_1_ADDR, REG_DBREG0_IC_1_BYTE, R18_DBREG0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DBREG1_IC_1_ADDR, REG_DBREG1_IC_1_BYTE, R19_DBREG1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DBREG2_IC_1_ADDR, REG_DBREG2_IC_1_BYTE, R20_DBREG2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_IN_MUX_0_1_IC_1_ADDR, REG_CORE_IN_MUX_0_1_IC_1_BYTE, R21_CORE_IN_MUX_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CORE_IN_MUX_2_3_IC_1_ADDR, REG_CORE_IN_MUX_2_3_IC_1_BYTE, R22_CORE_IN_MUX_2_3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC_SOURCE_0_1_IC_1_ADDR, REG_DAC_SOURCE_0_1_IC_1_BYTE, R23_DAC_SOURCE_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PDM_SOURCE_0_1_IC_1_ADDR, REG_PDM_SOURCE_0_1_IC_1_BYTE, R24_PDM_SOURCE_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE_0_1_IC_1_ADDR, REG_SOUT_SOURCE_0_1_IC_1_BYTE, R25_SOUT_SOURCE_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE_2_3_IC_1_ADDR, REG_SOUT_SOURCE_2_3_IC_1_BYTE, R26_SOUT_SOURCE_2_3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE_4_5_IC_1_ADDR, REG_SOUT_SOURCE_4_5_IC_1_BYTE, R27_SOUT_SOURCE_4_5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE_6_7_IC_1_ADDR, REG_SOUT_SOURCE_6_7_IC_1_BYTE, R28_SOUT_SOURCE_6_7_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_SDATA_CH_IC_1_ADDR, REG_ADC_SDATA_CH_IC_1_BYTE, R29_ADC_SDATA_CH_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ASRCO_SOURCE_0_1_IC_1_ADDR, REG_ASRCO_SOURCE_0_1_IC_1_BYTE, R30_ASRCO_SOURCE_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ASRCO_SOURCE_2_3_IC_1_ADDR, REG_ASRCO_SOURCE_2_3_IC_1_BYTE, R31_ASRCO_SOURCE_2_3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ASRC_MODE_IC_1_ADDR, REG_ASRC_MODE_IC_1_BYTE, R32_ASRC_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_CONTROL0_IC_1_ADDR, REG_ADC_CONTROL0_IC_1_BYTE, R33_ADC_CONTROL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_CONTROL1_IC_1_ADDR, REG_ADC_CONTROL1_IC_1_BYTE, R34_ADC_CONTROL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_CONTROL2_IC_1_ADDR, REG_ADC_CONTROL2_IC_1_BYTE, R35_ADC_CONTROL2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_CONTROL3_IC_1_ADDR, REG_ADC_CONTROL3_IC_1_BYTE, R36_ADC_CONTROL3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC0_VOLUME_IC_1_ADDR, REG_ADC0_VOLUME_IC_1_BYTE, R37_ADC0_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC1_VOLUME_IC_1_ADDR, REG_ADC1_VOLUME_IC_1_BYTE, R38_ADC1_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC2_VOLUME_IC_1_ADDR, REG_ADC2_VOLUME_IC_1_BYTE, R39_ADC2_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC3_VOLUME_IC_1_ADDR, REG_ADC3_VOLUME_IC_1_BYTE, R40_ADC3_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_CONTROL_0_IC_1_ADDR, REG_PGA_CONTROL_0_IC_1_BYTE, R41_PGA_CONTROL_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_CONTROL_1_IC_1_ADDR, REG_PGA_CONTROL_1_IC_1_BYTE, R42_PGA_CONTROL_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_CONTROL_2_IC_1_ADDR, REG_PGA_CONTROL_2_IC_1_BYTE, R43_PGA_CONTROL_2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_CONTROL_3_IC_1_ADDR, REG_PGA_CONTROL_3_IC_1_BYTE, R44_PGA_CONTROL_3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_STEP_CONTROL_IC_1_ADDR, REG_PGA_STEP_CONTROL_IC_1_BYTE, R45_PGA_STEP_CONTROL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PGA_10DB_BOOST_IC_1_ADDR, REG_PGA_10DB_BOOST_IC_1_BYTE, R46_PGA_10DB_BOOST_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_POP_SUPPRESS_IC_1_ADDR, REG_POP_SUPPRESS_IC_1_BYTE, R47_POP_SUPPRESS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_TALKTHRU_IC_1_ADDR, REG_TALKTHRU_IC_1_BYTE, R48_TALKTHRU_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_TALKTHRU_GAIN0_IC_1_ADDR, REG_TALKTHRU_GAIN0_IC_1_BYTE, R49_TALKTHRU_GAIN0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_TALKTHRU_GAIN1_IC_1_ADDR, REG_TALKTHRU_GAIN1_IC_1_BYTE, R50_TALKTHRU_GAIN1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MIC_BIAS_IC_1_ADDR, REG_MIC_BIAS_IC_1_BYTE, R51_MIC_BIAS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC_CONTROL1_IC_1_ADDR, REG_DAC_CONTROL1_IC_1_BYTE, R52_DAC_CONTROL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC0_VOLUME_IC_1_ADDR, REG_DAC0_VOLUME_IC_1_BYTE, R53_DAC0_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC1_VOLUME_IC_1_ADDR, REG_DAC1_VOLUME_IC_1_BYTE, R54_DAC1_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_OP_STAGE_MUTES_IC_1_ADDR, REG_OP_STAGE_MUTES_IC_1_BYTE, R55_OP_STAGE_MUTES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SAI_0_IC_1_ADDR, REG_SAI_0_IC_1_BYTE, R56_SAI_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SAI_1_IC_1_ADDR, REG_SAI_1_IC_1_BYTE, R57_SAI_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_CONTROL0_IC_1_ADDR, REG_SOUT_CONTROL0_IC_1_BYTE, R58_SOUT_CONTROL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_CONTROL1_IC_1_ADDR, REG_SOUT_CONTROL1_IC_1_BYTE, R59_SOUT_CONTROL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PDM_OUT_IC_1_ADDR, REG_PDM_OUT_IC_1_BYTE, R60_PDM_OUT_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PDM_PATTERN_IC_1_ADDR, REG_PDM_PATTERN_IC_1_BYTE, R61_PDM_PATTERN_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP0_IC_1_ADDR, REG_MODE_MP0_IC_1_BYTE, R62_MODE_MP0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP1_IC_1_ADDR, REG_MODE_MP1_IC_1_BYTE, R63_MODE_MP1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP2_IC_1_ADDR, REG_MODE_MP2_IC_1_BYTE, R64_MODE_MP2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP3_IC_1_ADDR, REG_MODE_MP3_IC_1_BYTE, R65_MODE_MP3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP4_IC_1_ADDR, REG_MODE_MP4_IC_1_BYTE, R66_MODE_MP4_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP5_IC_1_ADDR, REG_MODE_MP5_IC_1_BYTE, R67_MODE_MP5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MODE_MP6_IC_1_ADDR, REG_MODE_MP6_IC_1_BYTE, R68_MODE_MP6_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PB_VOL_SET_IC_1_ADDR, REG_PB_VOL_SET_IC_1_BYTE, R69_PB_VOL_SET_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PB_VOL_CONV_IC_1_ADDR, REG_PB_VOL_CONV_IC_1_BYTE, R70_PB_VOL_CONV_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DEBOUNCE_MODE_IC_1_ADDR, REG_DEBOUNCE_MODE_IC_1_BYTE, R71_DEBOUNCE_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_RESERVED_IC_1_ADDR, REG_RESERVED_IC_1_BYTE, R72_RESERVED_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_OP_STAGE_CTRL_IC_1_ADDR, REG_OP_STAGE_CTRL_IC_1_BYTE, R73_OP_STAGE_CTRL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DECIM_PWR_MODES_IC_1_ADDR, REG_DECIM_PWR_MODES_IC_1_BYTE, R74_DECIM_PWR_MODES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_INTERP_PWR_MODES_IC_1_ADDR, REG_INTERP_PWR_MODES_IC_1_BYTE, R75_INTERP_PWR_MODES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_BIAS_CONTROL0_IC_1_ADDR, REG_BIAS_CONTROL0_IC_1_BYTE, R76_BIAS_CONTROL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_BIAS_CONTROL1_IC_1_ADDR, REG_BIAS_CONTROL1_IC_1_BYTE, R77_BIAS_CONTROL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL0_IC_1_ADDR, REG_PAD_CONTROL0_IC_1_BYTE, R78_PAD_CONTROL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL1_IC_1_ADDR, REG_PAD_CONTROL1_IC_1_BYTE, R79_PAD_CONTROL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL2_IC_1_ADDR, REG_PAD_CONTROL2_IC_1_BYTE, R80_PAD_CONTROL2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL3_IC_1_ADDR, REG_PAD_CONTROL3_IC_1_BYTE, R81_PAD_CONTROL3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL4_IC_1_ADDR, REG_PAD_CONTROL4_IC_1_BYTE, R82_PAD_CONTROL4_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PAD_CONTROL5_IC_1_ADDR, REG_PAD_CONTROL5_IC_1_BYTE, R83_PAD_CONTROL5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, BANK_A_PARAMETERS_ADDR_IC_1, BANK_A_PARAMETERS_SIZE_IC_1, BANK_A_PARAMETERS_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, BANK_B_PARAMETERS_ADDR_IC_1, BANK_B_PARAMETERS_SIZE_IC_1, BANK_B_PARAMETERS_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_OP_STAGE_MUTES_IC_1_ADDR, REG_OP_STAGE_MUTES_IC_1_BYTE, R87_OP_STAGE_MUTES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC0_VOLUME_IC_1_ADDR, REG_DAC0_VOLUME_IC_1_BYTE, R88_DAC0_VOLUME_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC1_VOLUME_IC_1_ADDR, REG_DAC1_VOLUME_IC_1_BYTE, R89_DAC1_VOLUME_IC_1_Default );
}

#endif