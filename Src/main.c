#include <stdio.h>
#include "RCC.h"
#include "GPIO.h"
void delay(uint32_t time){
	while(time--);
}
void RCC_SetSysCLK_72MHz(void);

int main(){
     GPIO_InitPin(GPIOA,GPIO_PIN_0,GPIO_MODE_OUTPUT_PP_50MHz);
	while(1){
		
		GPIO_WritePin(GPIOA,GPIO_PIN_0,1);
		delay(1000000);
		GPIO_WritePin(GPIOA,GPIO_PIN_0,0);
		delay(1000000);
	}
}