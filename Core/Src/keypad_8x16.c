/*
 * keypad_8x16.c
 *
 *  Created on: Sep 22, 2023
 *      Author: Lalo
 */
#include "keypad_8x16.h"

void keypad_init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Configuración pines de entrada: FILAS

	HAL_GPIO_WritePin(FILA_1_PUERTO, FILA_1_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_1_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_2_PUERTO, FILA_2_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_2_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_3_PUERTO, FILA_3_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_3_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_1_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_4_PUERTO, FILA_4_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_4_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_4_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_5_PUERTO, FILA_5_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_5_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_5_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_6_PUERTO, FILA_6_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_6_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_6_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_7_PUERTO, FILA_7_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_7_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_7_PUERTO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(FILA_8_PUERTO, FILA_8_PIN, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = FILA_8_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FILA_8_PUERTO, &GPIO_InitStruct);

	// Configuración pines de salida: COLUMNAS

	GPIO_InitStruct.Pin = COLUM_1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_1_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_2_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_3_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_3_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_4_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_4_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_5_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_5_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_6_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_6_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_7_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_7_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_8_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_8_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_9_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_9_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_10_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_10_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_11_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_11_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_12_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_12_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_13_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_13_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_14_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_14_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_15_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_15_PUERTO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = COLUM_16_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(COLUM_16_PUERTO, &GPIO_InitStruct);
}

uint8_t detector(void) {

	HAL_GPIO_WritePin(FILA_2_PUERTO, FILA_2_PIN, SET);
	HAL_GPIO_WritePin(FILA_3_PUERTO, FILA_3_PIN, SET);
	HAL_GPIO_WritePin(FILA_4_PUERTO, FILA_4_PIN, SET);
	HAL_GPIO_WritePin(FILA_5_PUERTO, FILA_5_PIN, SET);
	HAL_GPIO_WritePin(FILA_6_PUERTO, FILA_6_PIN, SET);
	HAL_GPIO_WritePin(FILA_7_PUERTO, FILA_7_PIN, SET);
	HAL_GPIO_WritePin(FILA_8_PUERTO, FILA_8_PIN, SET);

	uint8_t i = 0;

	HAL_GPIO_WritePin(FILA_1_PUERTO, FILA_1_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_1_PUERTO, FILA_1_PIN, SET);
	HAL_GPIO_WritePin(FILA_2_PUERTO, FILA_2_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_2_PUERTO, FILA_2_PIN, SET);
	HAL_GPIO_WritePin(FILA_3_PUERTO, FILA_3_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_3_PUERTO, FILA_3_PIN, SET);
	HAL_GPIO_WritePin(FILA_4_PUERTO, FILA_4_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_4_PUERTO, FILA_4_PIN, SET);
	HAL_GPIO_WritePin(FILA_5_PUERTO, FILA_5_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_5_PUERTO, FILA_5_PIN, SET);
	HAL_GPIO_WritePin(FILA_6_PUERTO, FILA_6_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}
	HAL_GPIO_WritePin(FILA_6_PUERTO, FILA_6_PIN, SET);
	HAL_GPIO_WritePin(FILA_7_PUERTO, FILA_7_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}

	HAL_GPIO_WritePin(FILA_7_PUERTO, FILA_7_PIN, SET);
	HAL_GPIO_WritePin(FILA_8_PUERTO, FILA_8_PIN, RESET);
	i++;
	if (HAL_GPIO_ReadPin(COLUM_1_PUERTO, COLUM_1_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_2_PUERTO, COLUM_2_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_3_PUERTO, COLUM_3_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_4_PUERTO, COLUM_4_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_5_PUERTO, COLUM_5_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_6_PUERTO, COLUM_6_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_7_PUERTO, COLUM_7_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_8_PUERTO, COLUM_8_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_9_PUERTO, COLUM_9_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_10_PUERTO, COLUM_10_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_11_PUERTO, COLUM_11_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_12_PUERTO, COLUM_12_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_13_PUERTO, COLUM_13_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_14_PUERTO, COLUM_14_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_15_PUERTO, COLUM_15_PIN) == 0) {
		return i;
	}
	i++;
	if (HAL_GPIO_ReadPin(COLUM_16_PUERTO, COLUM_16_PIN) == 0) {
		return i;
	}
	return 0;
}

