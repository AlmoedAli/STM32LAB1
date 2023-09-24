/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display1(GPIO_PinState A, GPIO_PinState B, GPIO_PinState C, GPIO_PinState D, GPIO_PinState E, GPIO_PinState F,
		GPIO_PinState G)
{
	HAL_GPIO_WritePin(led1A_GPIO_Port, led1A_Pin, A);
	HAL_GPIO_WritePin(led1B_GPIO_Port, led1B_Pin, B);
	HAL_GPIO_WritePin(led1C_GPIO_Port, led1C_Pin, C);
	HAL_GPIO_WritePin(led1D_GPIO_Port, led1D_Pin, D);
	HAL_GPIO_WritePin(led1E_GPIO_Port, led1E_Pin, E);
	HAL_GPIO_WritePin(led1F_GPIO_Port, led1F_Pin, F);
	HAL_GPIO_WritePin(led1G_GPIO_Port, led1G_Pin, G);
}

void display2(GPIO_PinState A, GPIO_PinState B, GPIO_PinState C, GPIO_PinState D, GPIO_PinState E, GPIO_PinState F,
		GPIO_PinState G)
{
	HAL_GPIO_WritePin(led2A_GPIO_Port, led2A_Pin, A);
	HAL_GPIO_WritePin(led2B_GPIO_Port, led2B_Pin, B);
	HAL_GPIO_WritePin(led2C_GPIO_Port, led2C_Pin, C);
	HAL_GPIO_WritePin(led2D_GPIO_Port, led2D_Pin, D);
	HAL_GPIO_WritePin(led2E_GPIO_Port, led2E_Pin, E);
	HAL_GPIO_WritePin(led2F_GPIO_Port, led2F_Pin, F);
	HAL_GPIO_WritePin(led2G_GPIO_Port, led2G_Pin, G);
}

void dislay7Seg1(int number)
{
	switch (number) {
		case 0:
			display1(0, 0, 0, 0, 0, 0, 1);
			break;
		case 1:
			display1(1, 0, 0, 1,  1, 1, 1);
			break;
		case 2:
			display1(0, 0, 1, 0, 0, 1, 0);
			break;

		case 3:
			display1(0, 0, 0, 0, 1, 1, 0);
			break;
		case 4:
			display1(1, 0, 0, 1, 1, 0, 0);
			break;
		case 5:
			display1(0, 1, 0, 0, 1, 0, 0);
			break;
		case 6:
			display1(0, 1, 0, 0, 0, 0, 0);
			break;
		case 7:
			display1(0, 0, 0, 1, 1, 1, 1);
			break;
		case 8:
			display1(0, 0, 0, 0, 0, 0, 0);
			break;
		case 9:
			display1(0, 0, 0, 0, 1, 0, 0);
			break;
		default:
			break;
	}
}

void dislay7Seg2(int number)
{
	switch (number) {
		case 0:
			display2(0, 0, 0, 0, 0, 0, 1);
			break;
		case 1:
			display2(1, 0, 0, 1,  1, 1, 1);
			break;
		case 2:
			display2(0, 0, 1, 0, 0, 1, 0);
			break;

		case 3:
			display2(0, 0, 0, 0, 1, 1, 0);
			break;
		case 4:
			display2(1, 0, 0, 1, 1, 0, 0);
			break;
		case 5:
			display2(0, 1, 0, 0, 1, 0, 0);
			break;
		case 6:
			display2(0, 1, 0, 0, 0, 0, 0);
			break;
		case 7:
			display2(0, 0, 0, 1, 1, 1, 1);
			break;
		case 8:
			display2(0, 0, 0, 0, 0, 0, 0);
			break;
		case 9:
			display2(0, 0, 0, 0, 1, 0, 0);
			break;
		default:
			break;
	}
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int counter = 0;
  int counter1= 0;
  int counter2= 0;
  int red1= 0, red2= 0, green1= 0, green2= 0;
//  int , yellow1= 0, yellow2= 0;
  while (1)
  {
	  switch (red1)
	  {
		case 1:
			switch (green2)
			{
				case 1:  // red1= 1 && green2== 1
					switch (counter)
					{
						case 3:
							HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
							HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
							green2= 0;
//							yellow2= 1;
							counter1-= 1;
							counter2= 1;
							counter= 1;
							break;
						default:
							counter+=1;
							counter1-= 1;
							counter2-= 1;
							break;
					}
					break;
				default:  // red1= 1 && yellow2== 1
					switch (counter)
					{
						case 2:
							HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
							HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
							HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
							HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
							red1=  0;
							red2= 1;
							green1= 1;
							counter2= 4;
							counter1= 2;
							counter= 1;
							break;
						default:
							counter+= 1;
							counter1-= 1;
							counter2-= 1;
							break;
					}
					break;
			}
			break;
		default:
			switch (red2)
			{
				case 1:
					switch (green1)
					{
						case 1:  // red2= 1 && green1= 1
							switch (counter)
							{
								case 3:
									HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
									HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
//									yellow1= 1;
									green1= 0;
									counter= 1;
									counter1= 1;
									counter2-= 1;
									break;
								default:
									counter+= 1;
									counter1-= 1;
									counter2-= 1;
									break;
							}
							break;
						default:   // red2= 1 && yellow1= 1
							switch (counter)
							{
								case 2:
									HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
									HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
									HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
									HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
									red1= 1;
//									yellow1= 0;
									green2= 1;
									red2= 0;
									counter2= 2;
									counter1= 4;
									counter= 1;
									break;
								default:
									counter+= 1;
									counter1-= 1;
									counter2-= 1;
									break;
							}
							break;
					}
					break;
				default:
					HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
					red1= 1;
					HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
					green2= 1;
					counter1= 4;
					counter2= 2;
					counter+= 1;
					break;
			}
			break;
	}
	  dislay7Seg1(counter1);
	  dislay7Seg2(counter2);
	  HAL_Delay(1000);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, red1_Pin|green1_Pin|yellow1_Pin|led1A_Pin
                          |led1B_Pin|led1C_Pin|led1D_Pin|led1E_Pin
                          |led1F_Pin|led1G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, red2_Pin|green2_Pin|yellow2_Pin|led2A_Pin
                          |led2B_Pin|led2C_Pin|led2D_Pin|led2E_Pin
                          |led2F_Pin|led2G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : red1_Pin green1_Pin yellow1_Pin led1A_Pin
                           led1B_Pin led1C_Pin led1D_Pin led1E_Pin
                           led1F_Pin led1G_Pin */
  GPIO_InitStruct.Pin = red1_Pin|green1_Pin|yellow1_Pin|led1A_Pin
                          |led1B_Pin|led1C_Pin|led1D_Pin|led1E_Pin
                          |led1F_Pin|led1G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : red2_Pin green2_Pin yellow2_Pin led2A_Pin
                           led2B_Pin led2C_Pin led2D_Pin led2E_Pin
                           led2F_Pin led2G_Pin */
  GPIO_InitStruct.Pin = red2_Pin|green2_Pin|yellow2_Pin|led2A_Pin
                          |led2B_Pin|led2C_Pin|led2D_Pin|led2E_Pin
                          |led2F_Pin|led2G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
