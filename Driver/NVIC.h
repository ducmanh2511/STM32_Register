#ifndef NVIC_H
#define NVIC_H
#include <stdint.h>
#define NVIC_ADD_BASE         0xE000E100UL
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
#define NVIC        ((volatile NVIC_Typedef*)(NVIC_ADD_BASE))
	void NVIC_EXTI0_Enable(void);
void NVIC_EXTI1_Enable(void);
void NVIC_EXTI2_Enable(void);
void NVIC_UART1_Enable(void);
void NVIC_TIM2_Enable(void);
void NVIC_TIM3_Enable(void);
void NVIC_TIM4_Enable(void);



#endif