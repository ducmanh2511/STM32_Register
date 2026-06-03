#include "AFIO.h"

void AFIO_SetEXTI_Port(uint8_t port, uint8_t pin){
     uint16_t crx = pin/4;
	   uint16_t shift = (pin%4)*4;
	   if(pin>15){ return ;}
		 
		 else{
			 switch (crx){
				 case 0:
					 AFIO->AFIO_EXTICR1 &= ~(0xF)<<shift;
				   AFIO->AFIO_EXTICR1 |= port<<shift;
				   break;
				 case 1:
					 AFIO->AFIO_EXTICR2 &= ~(0xF)<<shift;
				   AFIO->AFIO_EXTICR2 |= port<<shift;
				   break;
				 case 2:
					 AFIO->AFIO_EXTICR3 &= ~(0xF)<<shift;
				   AFIO->AFIO_EXTICR3 |= port<<shift;
				   break;
				 case 3:
					 AFIO->AFIO_EXTICR4 &= ~(0xF)<<shift;
				   AFIO->AFIO_EXTICR4 |= port<<shift;
				   break;
				 default:
					 break;
				 
			 }				 
			
		 }

}