#ifndef UART_H
#define UART_H
#include <stdint.h>
#include "NVIC.h"
#include "GPIO.h"
#define UART_ADD_BASE        0x40013800     
typedef struct{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}UART_Typedef;

#define UART      ((UART_Typedef *)UART_ADD_BASE)

#define USART_CR1_UE          (0x01<<13)
#define USART_CR1_TE          (0x01<<3)
#define USART_CR1_RE          (0x01<<2)
#define USART_CR1_TXEIE       (0x01<<7)
#define USART_CR1_RXNEIE      (0x01<<5)
#define USART_SR_RXNE         (0x01<<5)
#define USART_SR_TXE          (0x01<<7)
    

void UART1_Init(void);
void UART1_Transmit_String(char*s);
void UART1_Transmit_Char(char c);
char UART1_Receive_Char(void);
void USART1_IRQHandler(void);


#endif