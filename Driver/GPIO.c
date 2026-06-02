#include "GPIO.h"
void GPIO_InitPin(GPIO_Typedef*GPIOx, uint8_t pin,uint8_t mode){
	if(GPIOx == GPIOA){
		RCC_GPIOA_EnableClock();
	}
	else if(GPIOx == GPIOB){
		RCC_GPIOB_EnableClock();
	}
  else if(GPIOx == GPIOC){
		RCC_GPIOC_EnableClock();
	}
	else if(GPIOx == GPIOD){
		RCC_GPIOD_EnableClock();
	}
	else if(GPIOx == GPIOE){
		RCC_GPIOE_EnableClock();
	}
	uint8_t shift;
	if(pin<=7){
		shift = 4*pin;
		 GPIOx->GPIO_CRL &= ~(0xF<<(shift));
		 GPIOx->GPIO_CRL |= (mode<<(shift));
	}
	else{
		shift = 4*(pin-8);
	  	GPIOx->GPIO_CRH &= ~(0xF<<(shift));
		  GPIOx->GPIO_CRH |= (mode<<(shift));
	}
}
void GPIO_WritePin(GPIO_Typedef*GPIOx, uint8_t pin, uint8_t state){
	   if(state == GPIO_PIN_SET){
			 GPIOx->GPIO_BSRR = (1<<pin);
		 }
		  if(state == GPIO_PIN_RESET){
			 GPIOx->GPIO_BRR = (1<<pin);
		 }
}
uint8_t GPIO_ReadPin(GPIO_Typedef*GPIOx, uint8_t pin){
   	if((GPIOx->GPIO_IDR &(1<<pin)) == 0){
			return GPIO_PIN_RESET;
		}
		else{
			return GPIO_PIN_SET;
		}
}
void GPIO_TogglePin(GPIO_Typedef*GPIOx, uint8_t pin){
	GPIOx->GPIO_ODR ^= (1<<pin);
}
