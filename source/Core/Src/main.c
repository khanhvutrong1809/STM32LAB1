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
#include "Timer.h"

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// Array to hold the LED segment values for digits 0-9
const int MAX_LED = 4;
int index_led = 0;
int hour = 15 , minute = 8 , second = 50;
int led_buffer [4] = {1 , 2 , 3 , 4};

void display7SEG(int num) {
    switch(num) {
        case 0:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_SET);  // Led thứ 7 tắt
            break;
        case 1:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET);   // Led thứ 1 tắt
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);   // Led thứ 4 tắt
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);   // Led thứ 6 tắt
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_SET);   // Led thứ 7 tắt
            break;
        case 2:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_SET);   // Led thứ 3 tắt
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);   // Led thứ 6 tắt
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        // Các case khác từ 3 đến 9 được xử lý tương tự
        case 3:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);   // Led thứ 6 tắt
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET);   // Led thứ 1 tắt
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);   // Led thứ 4 tắt
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_SET);   // Led thứ 2 tắt
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_SET);   // Led thứ 2 tắt
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);   // Led thứ 4 tắt
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);   // Led thứ 6 tắt
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_SET);   // Led thứ 7 tắt
            break;
        case 8:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);   // Led thứ 5 tắt
            HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void update7SEG(int index) {
    // Tắt tất cả các chân điều khiển để chuẩn bị cập nhật
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);

    switch(index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);  // Bật chân tương ứng với LED đầu tiên
            display7SEG(led_buffer[0]);                            // Hiển thị giá trị
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
            display7SEG(led_buffer[1]);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
            display7SEG(led_buffer[2]);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
            display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}

void updateClockBuffer ()
{
 led_buffer [0] = hour / 10;
 led_buffer [1] = hour % 10;
 led_buffer [2] = minute / 10;
 led_buffer [3] = minute % 10;
 }

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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer(0,1000);
  setTimer(1,1000);
  setTimer(2,1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

  while (1) {

                 if (Timer_Flag[0]) {
                     update7SEG(index_led);
                     index_led = (index_led + 1) % MAX_LED;  // Tăng index_led, quay về 0 nếu đạt MAX_LED
                     setTimer(0, 1000);  // Cài lại timer 0 với thời gian 1000ms

                 }

                 if (Timer_Flag[1]) {
                     HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);  // Đổi trạng thái chân GPIOA_PIN_4
                     setTimer(1, 1000);  // Cài lại timer 1 với thời gian 1000ms

                 }

                 if (Timer_Flag[2]) {
                     second++;
                     if (second >= 60) {
                         second = 0;
                         minute++;
                     }
                     if (minute >= 60) {
                         minute = 0;
                         hour++;
                     }
                     if (hour >= 24) {
                         hour = 0;
                     }

                     updateClockBuffer();  // Cập nhật buffer hiển thị thời gian
                     setTimer(2, 1000);  // Cài lại timer 2 với thời gian 1000ms

                 }



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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|LED_RED_Pin|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 LED_RED_Pin PA6 PA7
                           PA8 PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|LED_RED_Pin|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	runTimer();
}
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
