#include "EXTI.h"
void EXTI_EnableInterrupt(uint8_t line){
  if(line >19){
		return ;
	}
	else{
		EXTI->EXTI_IMR|= (1<<line);
	}

}
void EXTI_DisableInterrupt(uint8_t line){
	if(line >19){
		return ;
	}
	else{
		EXTI->EXTI_IMR &= ~(1U<<line);
		
	}
}
void EXTI_Init(GPIO_Typedef *port, uint8_t pin, EXTI_MODE mode){
	if(port==GPIOA){
		AFIO_SetEXTI_Port(AFIO_EXTI_PA,pin);
		
	}
	else if(port==GPIOB){
		AFIO_SetEXTI_Port(AFIO_EXTI_PB,pin);
	}
	else if(port==GPIOC){
		AFIO_SetEXTI_Port(AFIO_EXTI_PC,pin);
	}
	else if(port==GPIOD){
		AFIO_SetEXTI_Port(AFIO_EXTI_PD,pin);
	}
	
	EXTI->EXTI_RTSR &= ~(1U<<pin); // reset 
	EXTI->EXTI_FTSR &= ~(1U<<pin);   // reset
	switch (mode){
		case EXTI_RISING :
			EXTI->EXTI_RTSR |= (1U<<pin);
			break;
		
	 	case EXTI_FALLING :
			EXTI->EXTI_FTSR |= (1U<<pin);
	  	break;
		case EXTI_BOTH :
			EXTI->EXTI_RTSR |= (1U<<pin);
      EXTI->EXTI_FTSR |= (1U<<pin);
			break;
		default :
			break;
		
	}
	EXTI_EnableInterrupt(pin);
}
uint8_t EXTI_GetPending(uint8_t line)
{
    if(line > 19) return 0;

    return (EXTI->EXTI_PR & (1U << line)) ? 1 : 0;
}
void EXTI_ClearPending(uint8_t line){
    EXTI->EXTI_PR = (1U << line);
}


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
void EXTI0_IRQHandler(void){ 
	   if(EXTI_GetPending(0)){
			 // do something
			 EXTI_ClearPending(0);
		 }
	
}




