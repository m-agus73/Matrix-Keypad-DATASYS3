/*
 * keypad_8x16.h
 *
 *  Created on: Sep 22, 2023
 *      Author: Lalo
 */

#ifndef INC_KEYPAD_8X16_H_
#define INC_KEYPAD_8X16_H_

#include "stm32f1xx_hal.h"

#define FILA_1_PUERTO GPIOA
#define FILA_2_PUERTO GPIOA
#define FILA_3_PUERTO GPIOA
#define FILA_4_PUERTO GPIOA
#define FILA_5_PUERTO GPIOA
#define FILA_6_PUERTO GPIOA
#define FILA_7_PUERTO GPIOA
#define FILA_8_PUERTO GPIOB

#define FILA_1_PIN GPIO_PIN_1
#define FILA_2_PIN GPIO_PIN_2
#define FILA_3_PIN GPIO_PIN_3
#define FILA_4_PIN GPIO_PIN_4
#define FILA_5_PIN GPIO_PIN_5
#define FILA_6_PIN GPIO_PIN_6
#define FILA_7_PIN GPIO_PIN_7
#define FILA_8_PIN GPIO_PIN_0

#define COLUM_1_PUERTO GPIOB
#define COLUM_2_PUERTO GPIOB
#define COLUM_3_PUERTO GPIOB
#define COLUM_4_PUERTO GPIOB
#define COLUM_5_PUERTO GPIOB
#define COLUM_6_PUERTO GPIOB
#define COLUM_7_PUERTO GPIOA
#define COLUM_8_PUERTO GPIOA
#define COLUM_9_PUERTO GPIOA
#define COLUM_10_PUERTO GPIOA
#define COLUM_11_PUERTO GPIOA
#define COLUM_12_PUERTO GPIOA
#define COLUM_13_PUERTO GPIOB
#define COLUM_14_PUERTO GPIOB
#define COLUM_15_PUERTO GPIOB
#define COLUM_16_PUERTO GPIOB

#define COLUM_1_PIN GPIO_PIN_8
#define COLUM_2_PIN GPIO_PIN_7
#define COLUM_3_PIN GPIO_PIN_6
#define COLUM_4_PIN GPIO_PIN_5
#define COLUM_5_PIN GPIO_PIN_4
#define COLUM_6_PIN GPIO_PIN_3
#define COLUM_7_PIN GPIO_PIN_15
#define COLUM_8_PIN GPIO_PIN_12
#define COLUM_9_PIN GPIO_PIN_11
#define COLUM_10_PIN GPIO_PIN_10
#define COLUM_11_PIN GPIO_PIN_9
#define COLUM_12_PIN GPIO_PIN_8
#define COLUM_13_PIN GPIO_PIN_15
#define COLUM_14_PIN GPIO_PIN_14
#define COLUM_15_PIN GPIO_PIN_13
#define COLUM_16_PIN GPIO_PIN_12


uint8_t detector(void);
void keypad_init(void);



#endif /* INC_KEYPAD_8X16_H_ */
