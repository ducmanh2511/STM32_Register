#ifndef EXTI_H
#define EXTI_H
#include <stdio.h>
#include <stdint.h>
#include <GPIO.h>
#include <AFIO.h>
#define EXTI_ADD_BASE         0x40010400UL
#define NVIC_ADD_BASE         0xE000E100UL
typedef enum {
	  EXTI_RISING,
	  EXTI_FALLING,
	  EXTI_BOTH
	
}EXTI_MODE;
typedef struct{
   volatile uint32_t EXTI_IMR;
	 volatile uint32_t EXTI_EMR;
	 volatile uint32_t EXTI_RTSR;
 	 volatile uint32_t EXTI_FTSR;
	 volatile uint32_t EXTI_SWIER;
	 volatile uint32_t EXTI_PR;
}EXTI_Typedef;
typedef struct {
  volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ICER0;
	volatile uint32_t NVIC_ICER1;
	volatile uint32_t NVIC_ICER2;
	volatile uint32_t NVIC_ISPR0;
	volatile uint32_t NVIC_ISPR1;
	volatile uint32_t NVIC_ISPR2;
	
}NVIC_Typedef;
#define EXTI        ((volatile EXTI_Typedef*)(EXTI_ADD_BASE))
#define NVIC        ((volatile NVIC_Typedef*)(NVIC_ADD_BASE))
	
void EXTI_EnableInterrupt(uint8_t line);
void EXTI_DisableInterrupt(uint8_t line);
uint8_t EXTI_GetPending(uint8_t line);
void EXTI_ClearPending(uint8_t line);
void EXTI_Init(GPIO_Typedef *port, uint8_t pin, EXTI_MODE mode);

void EXTI0_IRQHandler(void);




#endif