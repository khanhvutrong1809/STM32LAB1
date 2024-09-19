/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
  void display7_SEG(int num) {

        switch(num) {
            case 0:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, SET);
                break;
            case 1:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, SET);
                break;
            case 2:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, SET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 3:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 4:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 5:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 6:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 7:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, SET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, SET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, SET);
                break;
            case 8:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, RESET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
            case 9:
                HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
                HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
                HAL_GPIO_WritePin(A3_GPIO_Port, A3_Pin, RESET);
                HAL_GPIO_WritePin(A4_GPIO_Port, A4_Pin, RESET);
                HAL_GPIO_WritePin(A5_GPIO_Port, A5_Pin, SET);
                HAL_GPIO_WritePin(A6_GPIO_Port, A6_Pin, RESET);
                HAL_GPIO_WritePin(A7_GPIO_Port, A7_Pin, RESET);
                break;
        }
    }
    void display7SEG(int num) {
          // Make 10 case for 7SEG led to display from 0 to 9
          switch(num) {
              case 0:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, SET);
                  break;
              case 1:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, SET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, SET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, SET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, SET);
                  break;
              case 2:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, SET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, SET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 3:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, SET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 4:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, SET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, SET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 5:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, SET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 6:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, SET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 7:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, SET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, SET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, SET);
                  break;
              case 8:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
              case 9:
                  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
                  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
                  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
                  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
                  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, SET);
                  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
                  HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, RESET);
                  break;
          }
      }

    int count1 = 0; // Count for Led 1,3
    int count2 = 0; // Count for Led 2,4
    int count1_1 = 0; // Count for 7-SEG 1,3
    int count2_1 = 0; // Count for 7-SEG 2,4
  while (1)
  {
	  // TRAFFIC LIGHT
	        // State 0 (TL1-3: Green, TL2-4: Red)
	        if (count1 == 0) {
	            // GREEN
	            HAL_GPIO_TogglePin(W2_GPIO_Port, W2_Pin);
	            HAL_GPIO_TogglePin(W1_GPIO_Port, W1_Pin);
	            HAL_GPIO_TogglePin(W8_GPIO_Port, W8_Pin);
	            HAL_GPIO_TogglePin(W7_GPIO_Port, W7_Pin);
	            count1_1 = 3;
	        }

	        if (count2 == 0) {
	            // RED
	            HAL_GPIO_TogglePin(W5_GPIO_Port, W5_Pin);
	            HAL_GPIO_TogglePin(W6_GPIO_Port, W6_Pin);
	            HAL_GPIO_TogglePin(W10_GPIO_Port, W11_Pin);
	            HAL_GPIO_TogglePin(W12_GPIO_Port, W12_Pin);
	            count2_1 = 5;
	        }

	        // State 1 (TL1-3: Yellow, TL2-4: Green)
	        if (count1 == 3) {
	            // YELLOW
	            HAL_GPIO_TogglePin(W3_GPIO_Port, W3_Pin);
	            HAL_GPIO_TogglePin(W2_GPIO_Port, W2_Pin);
	            HAL_GPIO_TogglePin(W9_GPIO_Port, W9_Pin);
	            HAL_GPIO_TogglePin(W8_GPIO_Port, W8_Pin);
	            count1_1 = 2;
	        }

	        if (count2 == 5) {
	            // GREEN
	            HAL_GPIO_TogglePin(W4_GPIO_Port, W4_Pin);
	            HAL_GPIO_TogglePin(W6_GPIO_Port, W6_Pin);
	            HAL_GPIO_TogglePin(W10_GPIO_Port, W10_Pin);
	            HAL_GPIO_TogglePin(W12_GPIO_Port, W12_Pin);
	            count2_1 = 3;
	        }
	        // State 2 (TL1-3: Red, TL2-4: Yellow)
	        if (count1 == 5) {
	            // RED
	            HAL_GPIO_TogglePin(W2_GPIO_Port, W2_Pin);
	            HAL_GPIO_TogglePin(W1_GPIO_Port, W1_Pin);
	            HAL_GPIO_TogglePin(W8_GPIO_Port, W8_Pin);
	            HAL_GPIO_TogglePin(W7_GPIO_Port, W7_Pin);
	            count1_1 = 5;
	        }

	        if (count2 == 8) {
	            // YELLOW
	            HAL_GPIO_TogglePin(W5_GPIO_Port, W5_Pin);
	            HAL_GPIO_TogglePin(W6_GPIO_Port, W6_Pin);
	            HAL_GPIO_TogglePin(W11_GPIO_Port, W11_Pin);
	            HAL_GPIO_TogglePin(W12_GPIO_Port, W12_Pin);
	            count2_1 = 2;
	        }

	        // State 3 (TL1-3: Green, TL2-4: Red)
	        if (count1 == 10) {
	            // GREEN
	            HAL_GPIO_TogglePin(W3_GPIO_Port, W3_Pin);
	            HAL_GPIO_TogglePin(W1_GPIO_Port, W1_Pin);
	            HAL_GPIO_TogglePin(W9_GPIO_Port, W9_Pin);
	            HAL_GPIO_TogglePin(W7_GPIO_Port, W7_Pin);
	            count1_1 = 3;
	        }

	        if (count2 == 10) {
	            // RED
	            HAL_GPIO_TogglePin(W5_GPIO_Port, W5_Pin);
	            HAL_GPIO_TogglePin(W4_GPIO_Port, W4_Pin);
	            HAL_GPIO_TogglePin(W11_GPIO_Port, W11_Pin);
	            HAL_GPIO_TogglePin(W10_GPIO_Port, W10_Pin);
	            count2_1 = 5;
	        }

	        display7_SEG(count1_1);
	        display7SEG(count2_1);

	        // Setting counter variable
	        count1++;
	        count2++;

	        if (count1 == 13) count1 = 3;
	        if (count1 == 15) count2 = 5;

	        // Count down "7 SEG" led
	        count1_1--;
	        count2_1--;
	        HAL_Delay(1000); // Set cycle time to 1 second for real-time display


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
  HAL_GPIO_WritePin(GPIOA, W1_Pin|W2_Pin|W3_Pin|W4_Pin
                          |W5_Pin|W6_Pin|W7_Pin|W8_Pin
                          |W9_Pin|W10_Pin|W11_Pin|W12_Pin
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S1_Pin|S2_Pin|S3_Pin|A3_Pin
                          |A4_Pin|A5_Pin|A6_Pin|A7_Pin
                          |S4_Pin|S5_Pin|S6_Pin|S7_Pin
                          |A1_Pin|A2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : W1_Pin W2_Pin W3_Pin W4_Pin
                           W5_Pin W6_Pin W7_Pin W8_Pin
                           W9_Pin W10_Pin W11_Pin W12_Pin
                           PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = W1_Pin|W2_Pin|W3_Pin|W4_Pin
                          |W5_Pin|W6_Pin|W7_Pin|W8_Pin
                          |W9_Pin|W10_Pin|W11_Pin|W12_Pin
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S1_Pin S2_Pin S3_Pin A3_Pin
                           A4_Pin A5_Pin A6_Pin A7_Pin
                           S4_Pin S5_Pin S6_Pin S7_Pin
                           A1_Pin A2_Pin */
  GPIO_InitStruct.Pin = S1_Pin|S2_Pin|S3_Pin|A3_Pin
                          |A4_Pin|A5_Pin|A6_Pin|A7_Pin
                          |S4_Pin|S5_Pin|S6_Pin|S7_Pin
                          |A1_Pin|A2_Pin;
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
