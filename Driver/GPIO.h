#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#include "RCC.h"
/*===========BASE ADDRESS=============*/
#define GPIOA_ADD_BASE    0x40010800UL
#define GPIOB_ADD_BASE    0x40010C00UL
#define GPIOC_ADD_BASE    0x40011000UL
#define GPIOD_ADD_BASE    0x40011400UL
#define GPIOE_ADD_BASE    0x40011800UL
/*=====================================*/
typedef struct{
	volatile uint32_t GPIO_CRL;
	volatile uint32_t GPIO_CRH;
	volatile uint32_t GPIO_IDR;
	volatile uint32_t GPIO_ODR;
	volatile uint32_t GPIO_BSRR;
	volatile uint32_t GPIO_BRR;
	volatile uint32_t GPIO_LCKR;
	
}GPIO_Typedef;
/*=======PERIPHERAL DEFINITION======= */
#define GPIOA      ((GPIO_Typedef*)GPIOA_ADD_BASE)
#define GPIOB      ((GPIO_Typedef*)GPIOB_ADD_BASE)
#define GPIOC      ((GPIO_Typedef*)GPIOC_ADD_BASE)
#define GPIOD      ((GPIO_Typedef*)GPIOD_ADD_BASE)
#define GPIOE      ((GPIO_Typedef*)GPIOE_ADD_BASE)
/*=========GPIO PIN NUMBER======*/
#define GPIO_PIN_0   0
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15
/*=============GPIO MODE================*/

#define GPIO_MODE_INPUT_ANALOG          0x0
#define GPIO_MODE_INPUT_FLOATING        0x4     
#define GPIO_MODE_INPUT_PULL            0x8

#define GPIO_MODE_OUTPUT_PP_10MHz       0x1            
#define GPIO_MODE_OUTPUT_PP_2MHz        0x2
#define GPIO_MODE_OUTPUT_PP_50MHz       0x3

#define GPIO_MODE_OUTPUT_OD_10MHz       0x5
#define GPIO_MODE_OUTPUT_OD_2MHz        0x6
#define GPIO_MODE_OUTPUT_OD_50MHz       0x7

#define GPIO_MODE_AF_PP_2MHz            0x9
#define GPIO_MODE_AF_PP_10MHz           0xA
#define GPIO_MODE_AF_PP_50MHz           0xB

#define GPIO_MODE_AF_OD_2MHz            0xD
#define GPIO_MODE_AF_OD_10MHz           0xE
#define GPIO_MODE_AF_OD_50MHz           0xF
/*=============GPIO STATUS==========*/
#define GPIO_PIN_SET          1
#define GPIO_PIN_RESET        0 



void GPIO_InitPin(GPIO_Typedef*GPIOx, uint8_t pin,uint8_t mode);
void GPIO_WritePin(GPIO_Typedef*GPIOx, uint8_t pin, uint8_t status);
uint8_t GPIO_ReadPin(GPIO_Typedef*GPIOx, uint8_t pin);
void GPIO_TogglePin(GPIO_Typedef*GPIOx, uint8_t pin);


#endif