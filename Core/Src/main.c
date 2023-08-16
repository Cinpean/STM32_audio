/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "dma2d.h"
#include "i2c.h"
#include "ltdc.h"
#include "sai.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm324x9i_eval.h"
#include "stm324x9i_eval_lcd.h"
#include "stm324x9i_eval_ts.h"

#define ARM_MATH_CM4
#define DMABuffLength 1024
#define FFTBuffLenth (DMABuffLength * 2)
#include "WM8994.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arm_math.h"
#include "MedianFilter.h"

#define NUM_ELEMENTS    25		// 11 works fine
static sMedianFilter_t medianFilter;
static sMedianNode_t medianBuffer[NUM_ELEMENTS];

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

int medianValue = 0;

q31_t fft_buff[DMABuffLength / 2];
q31_t DMABuffin_ch1[DMABuffLength/2];
q31_t mag_fft_buff[DMABuffLength/2];

arm_rfft_instance_q31 realFFT_Instance;
arm_rfft_instance_q31 realIFFT_Instance;

int16_t DMABuffin   [DMABuffLength];
int16_t DMABuffout  [DMABuffLength];

int16_t wave4p[] = {0,0,245,0,490,0,733,0,975,0,1214,0,1451,0,1684,0,1913,0,2137,0,2356,0,2570,0,2777,0,2978,0,3171,0,3357,0,3535,0,3704,0,3865,0,4016,0,4157,0,4288,0,4409,0,4519,0,4619,0,4707,0,4784,0,4850,0,4903,0,4945,0,4975,0,4993,0,5000,0,4993,0,4975,0,4945,0,4903,0,4850,0,4784,0,4707,0,4619,0,4519,0,4409,0,4288,0,4157,0,4016,0,3865,0,3704,0,3535,0,3357,0,3171,0,2978,0,2777,0,2570,0,2356,0,2137,0,1913,0,1684,0,1451,0,1214,0,975,0,733,0,490,0,245,0,0,0,-245,0,-490,0,-733,0,-975,0,-1214,0,-1451,0,-1684,0,-1913,0,-2137,0,-2356,0,-2570,0,-2777,0,-2978,0,-3171,0,-3357,0,-3535,0,-3704,0,-3865,0,-4016,0,-4157,0,-4288,0,-4409,0,-4519,0,-4619,0,-4707,0,-4784,0,-4850,0,-4903,0,-4945,0,-4975,0,-4993,0,-5000,0,-4993,0,-4975,0,-4945,0,-4903,0,-4850,0,-4784,0,-4707,0,-4619,0,-4519,0,-4409,0,-4288,0,-4157,0,-4016,0,-3865,0,-3704,0,-3535,0,-3357,0,-3171,0,-2978,0,-2777,0,-2570,0,-2356,0,-2137,0,-1913,0,-1684,0,-1451,0,-1214,0,-975,0,-733,0,-490,0,-245,0,0,0,245,0,490,0,733,0,975,0,1214,0,1451,0,1684,0,1913,0,2137,0,2356,0,2570,0,2777,0,2978,0,3171,0,3357,0,3535,0,3704,0,3865,0,4016,0,4157,0,4288,0,4409,0,4519,0,4619,0,4707,0,4784,0,4850,0,4903,0,4945,0,4975,0,4993,0,5000,0,4993,0,4975,0,4945,0,4903,0,4850,0,4784,0,4707,0,4619,0,4519,0,4409,0,4288,0,4157,0,4016,0,3865,0,3704,0,3535,0,3357,0,3171,0,2978,0,2777,0,2570,0,2356,0,2137,0,1913,0,1684,0,1451,0,1214,0,975,0,733,0,490,0,245,0,0,0,-245,0,-490,0,-733,0,-975,0,-1214,0,-1451,0,-1684,0,-1913,0,-2137,0,-2356,0,-2570,0,-2777,0,-2978,0,-3171,0,-3357,0,-3535,0,-3704,0,-3865,0,-4016,0,-4157,0,-4288,0,-4409,0,-4519,0,-4619,0,-4707,0,-4784,0,-4850,0,-4903,0,-4945,0,-4975,0,-4993,0,-4999,0,-4993,0,-4975,0,-4945,0,-4903,0,-4850,0,-4784,0,-4707,0,-4619,0,-4519,0,-4409,0,-4288,0,-4157,0,-4016,0,-3865,0,-3704,0,-3535,0,-3357,0,-3171,0,-2978,0,-2777,0,-2570,0,-2356,0,-2137,0,-1913,0,-1684,0,-1451,0,-1214,0,-975,0,-733,0,-490,0,-245,0,0,0,245,0,490,0,733,0,975,0,1214,0,1451,0,1684,0,1913,0,2137,0,2356,0,2570,0,2777,0,2978,0,3171,0,3357,0,3535,0,3704,0,3865,0,4016,0,4157,0,4288,0,4409,0,4519,0,4619,0,4707,0,4784,0,4850,0,4903,0,4945,0,4975,0,4993,0,4999,0,4993,0,4975,0,4945,0,4903,0,4850,0,4784,0,4707,0,4619,0,4519,0,4409,0,4288,0,4157,0,4016,0,3865,0,3704,0,3535,0,3357,0,3171,0,2978,0,2777,0,2570,0,2356,0,2137,0,1913,0,1684,0,1451,0,1214,0,975,0,733,0,490,0,245,0,0,0,-245,0,-490,0,-733,0,-975,0,-1214,0,-1451,0,-1684,0,-1913,0,-2137,0,-2356,0,-2570,0,-2777,0,-2978,0,-3171,0,-3357,0,-3535,0,-3704,0,-3865,0,-4016,0,-4157,0,-4288,0,-4409,0,-4519,0,-4619,0,-4707,0,-4784,0,-4850,0,-4903,0,-4945,0,-4975,0,-4993,0,-4999,0,-4993,0,-4975,0,-4945,0,-4903,0,-4850,0,-4784,0,-4707,0,-4619,0,-4519,0,-4409,0,-4288,0,-4157,0,-4016,0,-3865,0,-3704,0,-3535,0,-3357,0,-3171,0,-2978,0,-2777,0,-2570,0,-2356,0,-2137,0,-1913,0,-1684,0,-1451,0,-1214,0,-975,0,-733,0,-490,0,-245,0,0,0,245,0,490,0,733,0,975,0,1214,0,1451,0,1684,0,1913,0,2137,0,2356,0,2570,0,2777,0,2978,0,3171,0,3357,0,3535,0,3704,0,3865,0,4016,0,4157,0,4288,0,4409,0,4519,0,4619,0,4707,0,4784,0,4850,0,4903,0,4945,0,4975,0,4993,0,4999,0,4993,0,4975,0,4945,0,4903,0,4850,0,4784,0,4707,0,4619,0,4519,0,4409,0,4288,0,4157,0,4016,0,3865,0,3704,0,3535,0,3357,0,3171,0,2978,0,2777,0,2570,0,2356,0,2137,0,1913,0,1684,0,1451,0,1214,0,975,0,733,0,490,0,245,0,0,0,-245,0,-490,0,-733,0,-975,0,-1214,0,-1451,0,-1684,0,-1913,0,-2137,0,-2356,0,-2570,0,-2777,0,-2978,0,-3171,0,-3357,0,-3535,0,-3704,0,-3865,0,-4016,0,-4157,0,-4288,0,-4409,0,-4519,0,-4619,0,-4707,0,-4784,0,-4850,0,-4903,0,-4945,0,-4975,0,-4993,0,-4999,0,-4993,0,-4975,0,-4945,0,-4903,0,-4850,0,-4784,0,-4707,0,-4619,0,-4519,0,-4409,0,-4288,0,-4157,0,-4016,0,-3865,0,-3704,0,-3535,0,-3357,0,-3171,0,-2978,0,-2777,0,-2570,0,-2356,0,-2137,0,-1913,0,-1684,0,-1451,0,-1214,0,-975,0,-733,0,-490,0,-245,0};

int16_t amount_of_modulation;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */

//static void drawLine(int8_t xpos, int8_t ypos )
//{
//	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
//	BSP_LCD_FillRect(xpos, 240 - height, 25, height);
////	BSP_LCD_DrawVLine();
//}

static void Table (void)
{
	/* clear LCD */
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	/* draw and write */
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawLine(30,240,460,240);
	BSP_LCD_DrawLine(30,30,30,240);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(10, 10, (uint8_t *)"Spectrum analyzer", CENTER_MODE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(30, 250, (uint8_t *)"250Hz  500HZ  1kHz  2kHz  3kHz  4kHz  5kHz  6kHz  7kHz  8kHz", LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 30,(uint8_t *)"+4",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 50,(uint8_t *)"+2",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 70,(uint8_t *)"+0",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 90,(uint8_t *)"-2",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 110,(uint8_t *)"-4",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 130,(uint8_t *)"-8",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 150,(uint8_t *)"-12",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 170,(uint8_t *)"-14",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 190,(uint8_t *)"-16",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 210,(uint8_t *)"-20",LEFT_MODE);
	BSP_LCD_DisplayVertStringAt(5, 230,(uint8_t *)"-40",LEFT_MODE);

//	drawCollumn(30,45);
//	drawCollumn(73,38);
//	drawCollumn(116,105);
	BSP_LCD_DrawVLine(130,120,40);
//	BSP_LCD_DrawLine(30,30,280,134);
//	BSP_LCD_DrawLine(280,134,310,84);
}

void audio_changer (q31_t *buff, int nrelements_to_shift)
{
   if(nrelements_to_shift > 0)
    {
            for(int i = 0; i< DMABuffLength/2 ; i++)
        {
            buff[i] = buff[i + nrelements_to_shift];
            if(i > (DMABuffLength/2) - nrelements_to_shift -1 ) buff[i] = 0;
        }
   }
   else
   {
	   nrelements_to_shift = abs(nrelements_to_shift);
       for(int i = (DMABuffLength/2) -1; i>=0 ; i--)
       {
           buff[i] = buff[i - nrelements_to_shift ];
           if(i< nrelements_to_shift) buff[i] = 0;
       }
   }
}

uint8_t shiftFact = 7;
void soundProcess (q31_t *buff, int nrelements)
{

	arm_rfft_q31(&realFFT_Instance, buff, fft_buff);

	audio_changer (fft_buff, medianValue);

	arm_shift_q31(fft_buff, shiftFact, fft_buff, DMABuffLength / 2);

	arm_cmplx_mag_q31(fft_buff, mag_fft_buff, DMABuffLength / 2);

	arm_rfft_q31(&realIFFT_Instance, fft_buff, buff);

//	arm_shift_q15((q15_t *)buff, shiftFact, (q15_t *)buff, DMABuffLength / 2);

}

/* callbacks */

void HAL_SAI_RxHalfCpltCallback (SAI_HandleTypeDef *hsai_BlockB1)
{
	HAL_GPIO_WritePin(Verificare_samplerate_GPIO_Port, Verificare_samplerate_Pin, GPIO_PIN_RESET); //pin PA5

	for(uint16_t i = 0, j = 0; i < DMABuffLength / 2; i++, j++)
	{
//		DMABuffin_ch1[j] = wave4p[i++];
		DMABuffin_ch1[j] = DMABuffin[i++];
	}

	soundProcess(DMABuffin_ch1, 0);

	for(uint16_t i = 0, j = 0; i < DMABuffLength / 2; i++, j++)
	{
		DMABuffout[i++] = (int16_t) DMABuffin_ch1[j];
		DMABuffout[i] = 0;
	}

	HAL_GPIO_WritePin(Verificare_samplerate_GPIO_Port, Verificare_samplerate_Pin, GPIO_PIN_SET); //pin PA5
}


void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef *hsai_BlockB1)
{
	HAL_GPIO_WritePin(Verificare_samplerate_GPIO_Port, Verificare_samplerate_Pin, GPIO_PIN_RESET); //pin PA5

	uint16_t j =0;

	for(uint16_t i = 0; i < DMABuffLength / 2; i++)
	{
		if(i % 2 == 0)
		{
//			DMABuffin_ch1[j++] = wave4p[DMABuffLength / 2 + i];
			DMABuffin_ch1[j++] = DMABuffin[DMABuffLength / 2 + i];
		}
	}

	soundProcess(&DMABuffin_ch1[0], 0);

	j = 0;
	for(uint16_t i = 0; i < DMABuffLength / 2; i++)
	{
		if(i % 2 == 0)
		{
		   DMABuffout[DMABuffLength / 2 + i] = (int16_t) DMABuffin_ch1[j++];
		}
		else
		{
			DMABuffout[DMABuffLength / 2 + i] = 0;
		}
	}
	HAL_GPIO_WritePin(Verificare_samplerate_GPIO_Port, Verificare_samplerate_Pin, GPIO_PIN_SET); //pin PA5
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (hadc == &hadc3)
	{
		uint16_t readValue = HAL_ADC_GetValue(&hadc3);
		amount_of_modulation = (readValue / 32) - 64;
		medianValue = MEDIANFILTER_Insert(&medianFilter, amount_of_modulation);
		HAL_ADC_Start_IT(&hadc3);
	}
}


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
TS_StateTypeDef  ts;

char xTouchStr[10];
char xTouchStry[10];
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  medianFilter.numNodes = NUM_ELEMENTS;
  medianFilter.medianBuffer = medianBuffer;

  MEDIANFILTER_Init(&medianFilter);

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_DMA_Init();
  MX_SAI1_Init();
  MX_ADC3_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  MX_LTDC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  BSP_TS_Init(480, 272);

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  BSP_LCD_DisplayOn();

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);

  Table();

  WM8994_Init(&hi2c1);

  arm_rfft_init_q31(&realFFT_Instance, 256, 0, 1);
  arm_rfft_init_q31(&realIFFT_Instance, DMABuffLength / 4, 1, 1);

  HAL_SAI_Receive_DMA (&hsai_BlockA1, (uint8_t*) &DMABuffin, DMABuffLength);
  HAL_SAI_Transmit_DMA(&hsai_BlockB1, (uint8_t*) &DMABuffout, DMABuffLength);

  HAL_ADC_Start_IT(&hadc3);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Macro to configure SAI1BlockB clock source selection
  */
  __HAL_RCC_SAI_BLOCKBCLKSOURCE_CONFIG(SAI_CLKSOURCE_PLLI2S);

  /** Macro to configure SAI1BlockA clock source selection
  */
  __HAL_RCC_SAI_BLOCKACLKSOURCE_CONFIG(SAI_CLKSOURCE_PLLI2S);

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI_PLLI2S;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 50;
  PeriphClkInitStruct.PLLI2S.PLLI2SQ = 2;
  PeriphClkInitStruct.PLLI2SDivQ = 1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
