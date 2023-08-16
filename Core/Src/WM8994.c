/*
 * WM8994.c
 *
 *  Created on: Mar 2, 2022
 *      Author:
 */

#include <stdint.h>
#include <stm32f4xx_hal.h>
#include "WM8994.h"

//#define REG_ADDRESS			0x58E
#define REG_ADDR_SIZE		2
#define REG_DATA_SIZE		2
#define DEV_ADDRESS		 	(0x1A << 1)

//#define VOLUME_IN_CONVERT(Volume)     (((Volume) >= 100)? 239:((uint8_t)(((Volume) * 240) / 100)))


struct config
{
	uint16_t regAddress;
	uint16_t regValue;
	uint16_t regDelay;

};

//convertedvol = VOLUME_IN_CONVERT(Volume);

const struct config myConfig[] =
{
		// Registers modification
		// wm8994 Errata Work-Arounds
		{ 0x102, 0x0003 },
		{ 0x817, 0x0000 },
		{ 0x102, 0x0000 },

		{ 0x39,	0x006E, 0},				// VMID_RAMP SOFT FAST START, BIAS_SRC STARTUP BIAS (6c)

		{ 0x01,	0x0323,50},				//**Enable bias generator, Enable VMID, Enable HPOUT1 (Left) and Enable HPOUT1 (Right) input stages  idem for Speaker

		{ 0x3A,	0x0000, 0}, 			//** MICBIAS voltage control to (0.9  AVDD1)

		{ 0x05,  0x0303,0}, 			// Enable DAC1 (Left), Enable DAC1 (Right), Disable DAC2 (Left), Disable DAC2 (Right)
		{ 0x601, 0x0001,0}, 			// Enable the AIF1 Timeslot 0 (Left) to DAC 1 (Left) mixer path
		{ 0x602, 0x0001,0}, 			// Enable the AIF1 Timeslot 0 (Right) to DAC 1 (Right) mixer path
		{ 0x604, 0x0000,0},				// Disable the AIF1 Timeslot 1 (Left) to DAC 2 (Left) mixer path
		{ 0x605, 0x0000,0},				// Disable the AIF1 Timeslot 1 (Right) to DAC 2 (Right) mixer path

		{ 0x28, 0x0010,0},				//** IN1LN_TO_IN1L, IN1LP_TO_VMID
		{ 0x29, 0x0030,0},				//** Disable mute on IN1L_TO_MIXINL and +30dB on IN1L PGA output to MIXINL Gain and Mute MIXOUTL_MIXINL_VOL
//		{ 0x2A, 0x0020,0},				//** (no IN1R)
		{ 0x04,  0x0202,0}, 			//** Enable Left ADC, Disable Right ADC /
		{ 0x440, 0x01D2,0}, 			//** Enable AIF1 DRC1 Signal Detect & DRC in AIF1ADC1 Left Timeslot 0 + AIF1DRC1 Noise Gate Enable
		{ 0x02,  0x6240,0}, 			//** Enable IN1L and MIXINL, Disable IN2L and IN2R, Enable Thermal sensor & shutdown
		{ 0x606, 0x0002,0}, 			// Enable the ADCL(Left) to AIF1 Timeslot 0 (Left) mixer path
//		{ 0x607, 0x0002,0},
		{ 0x700, 0x800D,0}, 			//** GPIO1 pin configuration GP1_DIR = input, GP1_FN = AIF1 DRC1 signal detect

		{ 0x210,  0x0033,0},			// AIF1 Sample Rate = 16 (KHz) AUDIO_FREQUENCY_16K
		{ 0x300, 0x4010,0}, 			// AIF1 WORD LENGTH = 16BIT AIF1 FORMAT = I2S
		{ 0x302, 0x0000,0},				// slave mode
		{ 0x208, 0x000A,0}, 			// DSP processing, EN core clock
		{ 0x200, 0x0001,0}, 			// Enable AIF1 Clock, AIF1 Clock Source = MCLK1 pin
		{ 0x03, 0x0300, 0},				// MIXOUTLVOL_ENA  MIXOUTRVOL_ENA  MIXOUTRVOL_ENA  MIXOUTL_ENA  MIXOUTR_ENA 0x00F0
		{ 0x22,  0x0000,0},				// Left Speaker Mixer Volume = 0dB
		{ 0x23,  0x0000,0},				// Speaker output mode = Class D, Right Speaker Mixer Volume = 0dB ((0x23, 0x0100) = class AB)
		{ 0x36,  0x0300,0},				// Unmute DAC2 (Left) to Left Speaker Mixer (SPKMIXL) path, Unmute DAC2 (Right) to Right Speaker Mixer (SPKMIXR) path
		//{ 0x01,  0x3023,0},				//** 3003
		{ 0x51,  0x0005,0},				// Enable SPKOUTL, Enable SPKOUTR
		//{ 0x01,  0x3303,0},
		{ 0x60,  0x0022,0}, 			// HPOUT1 INTERMEDIATE STAGES
		{ 0x4C,  0x9F25,15}, 			// CHARGE PUMP
		{ 0x2D, 0x0001,0},				// DAC1L_TO_MIXOUTL unmute
		{ 0x2E,	0x0001,0},				// DAC1R_TO_MIXOUTR unmute
		{ 0x03,  (0x0030 | 0x0300),0}, 	// Enable Left Output Mixer (MIXOUTL), Enable Right Output Mixer (MIXOUTR)
		{ 0X54,  0X0033,250},			// Enable DC Servo and trigger start-up mode on left and right channels
		{ 0x60,  0x00EE,0}, 			// Enable HPOUT1 (Left) and HPOUT1 (Right) intermediate and output stages. Remove clamps
		{ 0x610, 0x00C0,0},				// Unmute DAC 1 (Left)
		{ 0x611, 0x00C0,0},				// Unmute DAC 1 (Right)
		{ 0x420, 0x0000,0},				// Unmute the AIF1 Timeslot 0 DAC path
		{ 0x612, 0x00C0,0},				// Unmute DAC 2 (Left)
		{ 0x613, 0x00C0,0},				// Unmute DAC 2 (Right)
		{ 0x422, 0x0000,0},				// Unmute the AIF1 Timeslot 1 DAC2 path

		{ 0x420, 0x0000,0},
		{ 0x422, 0x0000,0},

		{ 0x1C, 0x017F,0},
		{ 0x1D, 0x017F,0},
		{ 0x26, 0x017F,0},
		{ 0x27, 0x017F,0},

//		{ 0x400, 0x00EF,0},
//		{ 0x401, 0x00EF,0},
//		{ 0x404, 0x00EF,0},
//		{ 0x405, 0x00EF,0},

		{ 0x400, (150 | 0x100),0},		//  Left AIF1 ADC1
		{ 0x401, (150 | 0x100),0},		//  Right AIF1 ADC1
		{ 0x404, (150 | 0x100),0},		//  Left AIF1 ADC2
		{ 0x405, (150 | 0x100),0},



		/************************************************************************************/
		{ 0x18,	0x0119,0},				//** Disable mute on IN1L, IN1L Volume = +21dB, IN1_VU set to 1
//		{ 0x301, 0x0000,0},				// AIF1 Control 2 set to 0
		{ 0x1A,	0x018B,0},				//* IN1L_VOL IN1R_VOL Simultaneous
		{ 0x410, 0x7000,0},				//** AIF ADC1 HPF enable, HPF cut = voice mode 3, fc=267Hz at fs=8kHz
		{ 0x301, 0x0000,0},				//**
//		{ 0x1C,  0x140,0}, 				// HPOUT1_U ENABLE  HPOUT1L_MUTE_N DISABLE  HPOUT1L_VOL DEFAULT
//		{ 0x1D,  0x140,0},				// HPOUT1_U ENABLE  HPOUT1R_MUTE_N DISABLE  HPOUT1R_VOL DEFAULT
//		{ 0x20,	0x014F,0},				// MIXOUT_VU ENABLE : MIXOUTLVOL and MIXOUTRVOL volumes simultaneously MIXOUTL_MUTE_N : UNMUTE
//		{ 0x21, 0x014F,0},				// MIXOUT_VU ENABLE : MIXOUTVOL and MIXOUTRVOL volumes simultaneously MIXOUTR_MUTE_N : UNMUTE
//		{ 0x2A, 0x0033	},				// MIXOUTR_MIXINR_VOL
		/*************************************************************************************/

		{ 0x420, 0x0000,0},
		{ 0x422, 0x0000,0},

		{ 0x1C, 0x017F,0},
		{ 0x1D, 0x017F,0},
		{ 0x26, 0x017F,0},
		{ 0x27, 0x017F,0},

//		{ 0x400, 0x00EF,0},
//		{ 0x401, 0x00EF,0},
//		{ 0x404, 0x00EF,0},
//		{ 0x405, 0x00EF,0},

		{ 0x400, (150 | 0x100),0},		//  Left AIF1 ADC1
		{ 0x401, (150 | 0x100),0},		//  Right AIF1 ADC1
		{ 0x404, (150 | 0x100),0},		//  Left AIF1 ADC2
		{ 0x405, (150 | 0x100),0},


		/*************************************************************************************/
//		{ 0x2D,   0x0100,0},			// DAC1L_TO_HPOUT1L
//		{ 0x2E,   0x0100,0},			// DAC1R_TO_HPOUT1R
//		{ 0x0110, 0x8100,0},			// Initiate Control Write Sequencer at Index Address 0 (00h) (Headphone Cold Start-Up sequence)
//		{ 0x0420, 0x0000,0},			// Soft un-mute DAC1L and DAC1R
//		{ 0x31,	  0x0200},				// DAC1L_MIXOUTL_VOL
//		{ 0x32,   0x0200},				// DAC1R_MIXOUTR_VOL
		/**************************************************************************************/

		///////////////////////////////////////////////////////////////////////////////////////

//		{ 0x39,   0x006C, 1},  // 0x1Bh << 2
//		{ 0x1,    0x0003, 33},  // 0x03h << 0
//		{ 0x4C,   0x8000, 5},  // 0x01h << 15
//		{ 0x1,    0x0300, 1},  // 0x03h << 8
//		{ 0x60,   0x0022, 1},  // 0x11h << 1
//		{ 0x54,   0x0033, 1},  // 0x33h << 0
//		{ 0xFF,   0x0000, 1},  // 0x00h << 0
//		{ 0x60,   0x00EC, 1},  // 0x3Bh << 2

		///////////////////////////////////////////////////////////////////////////////////////




		/***************************************************************************************/

//		{ 0x400, 0x100,0},		//  Left AIF1 ADC1
//		{ 0x401, 0x100,0},		//  Right AIF1 ADC1
//		{ 0x404, 0x100,0},		//  Left AIF1 ADC2
//		{ 0x405, 0x100,0},		//  Right AIF1 ADC2
//		{ 0x300, 0x000A },


};

static uint16_t swap16(uint16_t data)
{
	return ((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8);
}

bool WM8994_Init(I2C_HandleTypeDef *i2cDev)
{
	// i2cDev_s = i2cDev;

	for (unsigned int i = 0; i < sizeof(myConfig) / sizeof(myConfig[0]); i++)
	{
		uint16_t regValue = swap16(myConfig[i].regValue);
		if(HAL_I2C_Mem_Write(i2cDev, DEV_ADDRESS, myConfig[i].regAddress, REG_ADDR_SIZE, (uint8_t*) &regValue, REG_DATA_SIZE, HAL_MAX_DELAY) != HAL_OK)
		{
			return false;
		}
		HAL_Delay(myConfig[i].regDelay);
	}

	return true;
}





