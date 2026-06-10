#include "UART.h"
/*
	Set baudrate : 9600
	PCLK2 =72MHz 
	USARTDIV = Fclk / (16*baudrate);
	USARTDIV = 468.75   
	-> Mantissa =468 = 0x1D4
	-> Fraction = 0.75*16=12=0xC
	Mantissa<<4 + Fraction = 0x1D4C
	*/
void UART1_Init(void){
	
	UART->USART_BRR |= 0x1D4C;
	UART->USART_CR1 |= USART_CR1_UE;  // enable uart
	UART->USART_CR1 |= USART_CR1_TE;   // enable transmit
	UART->USART_CR1 |= USART_CR1_RE;   // enable receive

}
void UART1_Init_IT(void){

	UART->USART_BRR = 0x1D4C;
	UART->USART_CR1 |= USART_CR1_UE;  // enable uart
	UART->USART_CR1 |= USART_CR1_TE;   // enable transmit
	UART->USART_CR1 |= USART_CR1_RE;   // enable receive
	NVIC_UART1_Enable();
	
}
void UART1_Transmit_Char(char c){
	while(!(UART->USART_SR&USART_SR_TXE)); // doi transmit data reg empty
	UART->USART_DR = c;
	  
}
void UART1_Transmit_String(char*s){
	while(*s){
		 UART1_Transmit_Char(*s++);
	}
}
char UART1_Receive_Char(void){
	while(!(UART->USART_SR&USART_SR_RXNE)); // 
	return (char)UART->USART_DR&(0xFF);
}

/*
UART1_Receive_Char_IT  : ready interrupt (Set register RXNEIE )
*/
void UART1_Receive_Char_IT(void){ 
	UART->USART_CR1 |= USART_CR1_RXNEIE;   // rx interrupt enable
}
void USART1_IRQHandler(void){
    if(UART->USART_SR&USART_SR_RXNE){
			// do sth
			char c = (char)(UART->USART_DR & 0xFF);
			UART1_Transmit_Char(c); // transmit gia tri nhan duoc
		}			
}