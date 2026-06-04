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
void EXTI_SetMode(uint8_t line, EXTI_MODE mode){
	EXTI->EXTI_RTSR &= ~(1U<<line); // reset 
	EXTI->EXTI_FTSR &= ~(1U<<line);   // reset
	switch (mode){
		case EXTI_RISING :
			EXTI->EXTI_RTSR |= (1U<<line);
			break;
		
	 	case EXTI_FALLING :
			EXTI->EXTI_FTSR |= (1U<<line);
	  	break;
		case EXTI_BOTH :
			EXTI->EXTI_RTSR |= (1U<<line);
      EXTI->EXTI_FTSR |= (1U<<line);
			break;
		default :
			break;
		
	}
}
uint8_t EXTI_GetPending(uint8_t line)
{
    if(line > 19) return 0;

    return (EXTI->EXTI_PR & (1U << line)) ? 1 : 0;
}
void EXTI_ClearPending(uint8_t line){
    EXTI->EXTI_PR = (1U << line);
}




