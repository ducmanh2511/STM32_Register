#ifndef EXTI_H
#define EXTI_H
#include <stdio.h>
#include <stdint.h>
#define EXTI_ADD_BASE         0x40010400
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

#define EXTI        ((volatile EXTI_Typedef*)(EXTI_ADD_BASE))
	
void EXTI_EnableInterrupt(uint8_t line);
void EXTI_DisableInterrupt(uint8_t line);
void EXTI_SetMode(uint8_t line, EXTI_MODE mode);
uint8_t EXTI_GetPending(uint8_t line);
void EXTI_ClearPending(uint8_t line);




#endif