#include "TIM.h"
void TIM_Init(TIMx_Typedef *tim, uint16_t psc, uint16_t arr)
{
    tim->CR1 &= ~TIM_CR1_CEN;

    tim->PSC = psc;
    tim->ARR = arr;
    tim->CNT = 0;

    tim->EGR |= TIM_EGR_UG;     // update psc arr ngay lap tuc
    tim->SR  &= ~TIM_SR_UIF;    // xoa do UG tao ra
}
void TIM_Start(TIMx_Typedef*tim){
	tim->CR1 |= TIM_CR1_CEN;
}
void TIM_Start_IT(TIMx_Typedef *tim)
{
    tim->SR   &= ~TIM_SR_UIF;   // xoa co ngat
    tim->DIER |= TIM_DIER_UIE;   // enable  update interrupt
    tim->CR1  |= TIM_CR1_CEN;
}
void TIM_Stop(TIMx_Typedef*tim){	
    tim->CR1 &= ~TIM_CR1_CEN; // disable interrupt
}

uint8_t TIM_GetFlag(TIMx_Typedef *tim){
	return (tim->SR&TIM_SR_UIF) ? 1:0;
}
void TIM_ClearFlag(TIMx_Typedef *tim){
	tim->SR &=~TIM_SR_UIF;
}
void TIM2_IRQHandler(void){
	if(TIM_GetFlag(TIM2)){
		// do something
		TIM_ClearFlag(TIM2);
	}
}