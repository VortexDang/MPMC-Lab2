/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "software_timer.h"
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
void display7SEG(int num){
	if(num == 0){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		}
		else if(num == 1){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		}
		else if(num == 2){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 3){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 4){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 5){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 6){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 7){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		}
		else if(num == 8){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		}
		else if(num == 9){
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int index_led = 0;
  int led_buffer [4] = {0 , 0 , 0 , 0};
  int hour=15, minute=8, second=50;

  void update7SEG ( int index ) {
  	switch ( index ) {
  	case 0:
  		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,RESET);
  		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,SET);
  		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,SET);
  		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,SET);
  		display7SEG(led_buffer[index]);
  		break;
  	case 1:
  		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,SET);
  		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,RESET);
  		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,SET);
  		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,SET);
  		display7SEG(led_buffer[index]);
  		break;
  	case 2:
  		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,SET);
  		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,SET);
  		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,RESET);
  		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,SET);
  		display7SEG(led_buffer[index]);
  		break;
  	case 3:
  		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,SET);
  		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,SET);
  		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,SET);
  		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,RESET);
  		display7SEG(led_buffer[index]);
  		break;
  	}
  }

  void updateClockBuffer(int hour, int minute){
	  led_buffer[0] = hour / 10;
	  led_buffer[1] = hour % 10;
	  led_buffer[2] = minute / 10;
	  led_buffer[3] = minute % 10;
  }

  void clearAllLEDMatrix() {
	  HAL_GPIO_WritePin(GPIOB, ROW0_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW1_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW2_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW3_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW4_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW5_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW6_Pin , SET);
	  HAL_GPIO_WritePin(GPIOB, ROW7_Pin , SET);

	  HAL_GPIO_WritePin(GPIOA, COL0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL2_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL6_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, COL7_Pin, SET);
  }
  uint8_t matrix_buffer[8]={0x7E,0x81,0x81,0x81,0xFF,0x81,0x81,0x81};
  void updateMatrixBuffer() {
	  uint8_t temp = matrix_buffer[0];
	  matrix_buffer[0] = matrix_buffer[1];
	  matrix_buffer[1] = matrix_buffer[2];
	  matrix_buffer[2] = matrix_buffer[3];
	  matrix_buffer[3] = matrix_buffer[4];
	  matrix_buffer[4] = matrix_buffer[5];
	  matrix_buffer[5] = matrix_buffer[6];
	  matrix_buffer[6] = matrix_buffer[7];
	  matrix_buffer[7] = temp;
  }

  void updateLEDMatrix (int index ){
	  clearAllLEDMatrix();
  	  switch(index) {
  	  case 0:
  	      HAL_GPIO_WritePin(GPIOB, ROW0_Pin , 0);
  	      HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[0] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[0] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[0] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[0] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[0] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[0] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[0] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[0] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 1:
  		  HAL_GPIO_WritePin(GPIOB, ROW1_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[1] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[1] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[1] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[1] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[1] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[1] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[1] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[1] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 2:
  		  HAL_GPIO_WritePin(GPIOB, ROW2_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[2] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[2] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[2] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[2] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[2] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[2] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[2] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[2] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 3:
  		  HAL_GPIO_WritePin(GPIOB, ROW3_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[3] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[3] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[3] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[3] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[3] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[3] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[3] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[3] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 4:
  		  HAL_GPIO_WritePin(GPIOB, ROW4_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[4] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[4] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[4] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[4] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[4] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[4] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[4] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[4] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 5:
  		  HAL_GPIO_WritePin(GPIOB, ROW5_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[5] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[5] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[5] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[5] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[5] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[5] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[5] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[5] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  case 6:
  		  HAL_GPIO_WritePin(GPIOB, ROW6_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[6] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[6] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[6] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[6] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[6] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[6] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[6] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[6] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  break;
  	  case 7:
  		  HAL_GPIO_WritePin(GPIOB, ROW7_Pin , 0);
  		  HAL_GPIO_WritePin(GPIOA, COL0_Pin, (matrix_buffer[7] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL1_Pin, (matrix_buffer[7] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL2_Pin, (matrix_buffer[7] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL3_Pin, (matrix_buffer[7] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL4_Pin, (matrix_buffer[7] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL5_Pin, (matrix_buffer[7] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL6_Pin, (matrix_buffer[7] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOA, COL7_Pin, (matrix_buffer[7] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
  	      break;
  	  default:
  		  break;
  	  }
    }

  setTimer1(10);
  setTimer2(15);
  setTimer3(15);
  setTimer4(10);
  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, SET);
  const int MAX_LED_MATRIX = 8;
  int index_matrix = 0;

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // updateClockBuffer
	  if(timer1_flag == 1) {
		  if (second >= 60){
			  second = 0;
		      minute++;
		  }
		  if(minute >= 60){
			  minute = 0;
		      hour++;
		  }
		  if(hour >=24){
			  hour = 0;
		  }
		  second++;
		  updateClockBuffer(hour, minute);
		  setTimer1(100);
	  }
	  // update7Seg
	  if(timer2_flag == 1) {
		  update7SEG(index_led);
		  if(index_led >= 3) {
			  index_led = 0;
		  }
		  else {
			  index_led++;
		  }
		  setTimer2(10);
	  }
	  // DOT and LED-RED
	  if(timer3_flag == 1) {
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  setTimer3(100);
	  }
	  // 8x8 Matrix
	  if(timer4_flag == 1) {
		  updateLEDMatrix(index_matrix++);
		  if(index_matrix == MAX_LED_MATRIX) {
			  updateMatrixBuffer();
			  index_matrix = 0;
		  }
		  setTimer4(5);
	  }
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
  HAL_GPIO_WritePin(GPIOA, COL0_Pin|COL1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |COL2_Pin|COL3_Pin|COL4_Pin|COL5_Pin
                          |COL6_Pin|COL7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : COL0_Pin COL1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           COL2_Pin COL3_Pin COL4_Pin COL5_Pin
                           COL6_Pin COL7_Pin */
  GPIO_InitStruct.Pin = COL0_Pin|COL1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |COL2_Pin|COL3_Pin|COL4_Pin|COL5_Pin
                          |COL6_Pin|COL7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	timer1Run();
	timer2Run();
	timer3Run();
	timer4Run();
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
