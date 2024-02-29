/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "keypad_8x16.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define LARGO_BUFF 10
#define TIMEOUT 30

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

volatile uint8_t tecla = 0, nueva_tecla = 0, flanco = 0, contimer = 0,
		flag_chequeo = 0, indice = 0, flag_config = 0, flag_salir = 0,
		buffer[LARGO_BUFF], caracter[1];
volatile int8_t comparador = 0;
volatile uint8_t matriz_teclas[129] = { 0, 0, 0, '0', 0, 0, 0, 0, 0, 0, '9',
		'8', '7', '4', '3', '2', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '6', '5',
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'N', 'B', 0, 0, 0, 0, 0, '=',
		'\n', 0, 0, 0, 0, 0, '.', ',', 'M', 'V', 'C', 'X', 'Z', 0, 0, 0, 0, 0,
		' ', 0, 0, 0, 0, 0, 'H', 'G', 0, 0, 0, 0, 0, ';', 0, 0, 0, 0, 0, 0, 'L',
		'K', 'J', 'F', 'D', 'S', 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Y', 'T',
		0, 0, '\t', 0, 0, 'P', 0, 0, 0, 0, 0, 0, 'O', 'I', 'U', 'R', 'E', 'W',
		'Q' };

typedef enum {
	ESCRIBIENDO, SETEO, REBOTES_SET, REBOTES_ESC
} estado_t;
estado_t actual = ESCRIBIENDO;

typedef enum {
	evt_presion_tecla,
	evt_timeout_rebotes,
	evt_chequeo_rebotes,
	evt_uart_configurar,
	evt_uart_salir,
	evt_timeout_seteo,
	evt_null,
} evento_t;
evento_t evento = evt_null;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
void leer_comando(volatile uint8_t*, uint8_t);
// uint8_t interpretar_comando(volatile uint8_t*);
void enviar_caracter(void);
void asignar_caracter(void);
void fsm_DATASYS3(estado_t*, evento_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_TIM3_Init();
	MX_USART3_UART_Init();
	/* USER CODE BEGIN 2 */

	HAL_TIM_Base_Start_IT(&htim3);
	HAL_UART_Receive_IT(&huart3, (uint8_t*) buffer + indice, 1);

	keypad_init();
	HAL_UART_Transmit(&huart3,
			(uint8_t*) "El estado actual es de ESCRITURA mediante el DATASYS3\r\n",
			strlen("El estado actual es de ESCRITURA mediante el DATASYS3\r\n"),
			HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3,
			(uint8_t*) "(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n",
			strlen(
					"(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n"),
			HAL_MAX_DELAY);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {

		evento = evt_null;

		if (contimer > (TIMEOUT * 50)) {
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "El estado actual es de ESCRITURA mediante el DATASYS3\r\n",
					strlen(
							"El estado actual es de ESCRITURA mediante el DATASYS3\r\n"),
					HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n",
					strlen(
							"(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n"),
					HAL_MAX_DELAY);
			evento = evt_timeout_seteo;
			flag_chequeo = 0;
			contimer = 0;
		}

		else if (contimer > TIMEOUT) {
			evento = evt_timeout_rebotes;
			flag_chequeo = 0;
			contimer = 0;
		}

		else if (flag_chequeo == 1) {
			evento = evt_chequeo_rebotes;
			nueva_tecla = detector();
			flanco = 0;
		}

		else if ((tecla = detector()) != 0) {
			evento = evt_presion_tecla;
			contimer = 0;
		}

		if (flag_salir == 1) {
			evento = evt_uart_salir;
			flag_salir = 0;
		}

		if (flag_config == 1) {
			evento = evt_uart_configurar;
			flag_config = 0;
		}

		fsm_DATASYS3(&actual, evento);

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 99;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 7199;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */

}

/**
 * @brief USART3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART3_UART_Init(void) {

	/* USER CODE BEGIN USART3_Init 0 */

	/* USER CODE END USART3_Init 0 */

	/* USER CODE BEGIN USART3_Init 1 */

	/* USER CODE END USART3_Init 1 */
	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart3) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART3_Init 2 */

	/* USER CODE END USART3_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
					| GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

	/*Configure GPIO pins : PA1 PA2 PA3 PA4
	 PA5 PA6 PA7 */
	GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4
			| GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : PB0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PB12 PB13 PB14 PB15
	 PB3 PB4 PB5 PB6
	 PB7 PB8 */
	GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15
			| GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7
			| GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PA8 PA9 PA10 PA11
	 PA15 */
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11
			| GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : PA12 */
	GPIO_InitStruct.Pin = GPIO_PIN_12;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void fsm_DATASYS3(estado_t *actual, evento_t evento) {

	switch (*actual) {

	case SETEO:
		switch (evento) {

		case evt_presion_tecla:
			flag_chequeo = 1;
			*actual = REBOTES_SET;
			break;

		case evt_uart_salir:
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "El estado actual es de ESCRITURA mediante el DATASYS3\r\n",
					strlen(
							"El estado actual es de ESCRITURA mediante el DATASYS3\r\n"),
					HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n",
					strlen(
							"(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n"),
					HAL_MAX_DELAY);
			*actual = ESCRIBIENDO;
			break;

		case evt_timeout_seteo:
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "El estado actual es de ESCRITURA mediante el DATASYS3\r\n",
					strlen(
							"El estado actual es de ESCRITURA mediante el DATASYS3\r\n"),
					HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n",
					strlen(
							"(Si desea configurar alguna tecla, ingrese el comando \"conf\" por UART)\r\n"),
					HAL_MAX_DELAY);
			*actual = ESCRIBIENDO;
			break;

		default:
			break;
		}

		break;

	case ESCRIBIENDO:

		switch (evento) {

		case evt_presion_tecla:
			flag_chequeo = 1;
			*actual = REBOTES_ESC;
			break;

		case evt_uart_configurar:
			HAL_UART_Transmit(&huart3,
					(uint8_t*) "Presione la tecla a configurar o envíe el comando \"salir\" para volver al estado de escritura\r\n",
					strlen(
							"Presione la tecla a configurar o envíe el comando \"salir\" para volver al estado de escritura\r\n"),
					HAL_MAX_DELAY);
			*actual = SETEO;
			break;

		default:
			break;
		}

		break;

	case REBOTES_SET:
		switch (evento) {

		case evt_chequeo_rebotes:

			if (nueva_tecla == tecla) {
				comparador++;
			} else {
				comparador--;
			}
			break;

		case evt_timeout_rebotes:

			if (comparador > 0) {
				asignar_caracter();
				HAL_UART_Transmit(&huart3, (uint8_t*) "Tecla reconfigurada\r\n",
						strlen("Tecla reconfigurada\r\n"), HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart3,
						(uint8_t*) "Presione la próxima tecla a configurar o envíe el comando \"salir\" para volver al estado de escritura\r\n",
						strlen(
								"Presione la próxima tecla a configurar o envíe el comando \"salir\" para volver al estado de escritura\r\n"),
						HAL_MAX_DELAY);
			}
			comparador = 0;
			*actual = SETEO;
			break;

		default:
			break;
		}
		break;

	case REBOTES_ESC:
		switch (evento) {

		case evt_chequeo_rebotes:

			if (nueva_tecla == tecla) {
				comparador++;
			} else {
				comparador--;
			}

			break;

		case evt_timeout_rebotes:
			if (comparador > 0) {
				enviar_caracter();
			}
			comparador = 0;
			*actual = ESCRIBIENDO;
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

}

void leer_comando(volatile uint8_t *b, uint8_t MAX) {
	HAL_UART_AbortReceive_IT(&huart3);
	uint8_t i = 0, comando_recibido = 0;
	while (!comando_recibido) {
		HAL_UART_Receive(&huart3, (uint8_t*) b + i, 1, HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, (uint8_t*) b + i, 1, HAL_MAX_DELAY);
		if (b[i] == '\r' || i == MAX) {
			b[i] = '\0';
			comando_recibido = 1;
		} else {
			i++;
		}
	}
	HAL_UART_Receive_IT(&huart3, (uint8_t*) buffer + indice, 1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	contimer++;
	flanco = 1;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	char c = buffer[indice];
	indice = (indice + 1) % LARGO_BUFF;
	buffer[indice] = '\0';
	if (c == '\r' || c == '\n') {
		if ((strcmp((char*) buffer, "conf\r") == 0)
				|| (strcmp((char*) buffer, "CONF\r") == 0)) {
			flag_config = 1;
		} else if ((strcmp((char*) buffer, "salir\r") == 0)
				|| (strcmp((char*) buffer, "SALIR\r") == 0)) {
			flag_salir = 1;
		}
		indice = 0;
		buffer[indice] = 0;
	}

	HAL_UART_Receive_IT(&huart3, (uint8_t*) buffer + indice, 1);

}

void enviar_caracter() {
	caracter[0] = matriz_teclas[tecla];
	HAL_UART_Transmit(&huart3, (uint8_t*) caracter, 1,
	HAL_MAX_DELAY);
}

void asignar_caracter() {
	HAL_UART_Transmit(&huart3,
			(uint8_t*) "Presione el caracter a designar, seguido de enter\r\n",
			strlen("Presione el caracter a designar, seguido de enter\r\n"),
			HAL_MAX_DELAY);
	leer_comando(caracter, 1);
	matriz_teclas[tecla] = caracter[0];
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
