#include "NVIC.h"
void NVIC_EXTI0_Enable(void){
	NVIC->NVIC_ISER0 |= 1U<<6;
	
}
void NVIC_EXTI1_Enable(void){
   NVIC->NVIC_ISER0 |= 1U<<7;}
void NVIC_EXTI2_Enable(void){
	NVIC->NVIC_ISER0 |= 1U<<8;
}
void NVIC_UART1_Enable(void){
   NVIC->NVIC_ISER1 |= 1<<5;
  
}
void NVIC_TIM2_Enable(void){
	NVIC->NVIC_ISER0 |= 1U<<28;
}
void NVIC_TIM3_Enable(void){
	NVIC->NVIC_ISER0 |= 1U<<29;
}
void NVIC_TIM4_Enable(void){
	NVIC->NVIC_ISER0 |= 1U<<30;
}