#ifndef AFIO_H
#define AFIO_H
#include <stdio.h>
#include <stdint.h>
/*==================BASE ADDRESS===========================*/
#define AFIO_ADD_BASE      0x40010000UL
/*=========================================================*/
typedef struct{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
	volatile uint32_t AFIO_MAPR2;
}AFIO_Typedef;
#define   AFIO       ((volatile AFIO_Typedef*) (AFIO_ADD_BASE))
/*==============================================================*/
#define AFIO_EXTI_PA      0x00
#define AFIO_EXTI_PB      0x01
#define AFIO_EXTI_PC      0x02
#define AFIO_EXTI_PD      0x03


void AFIO_SetEXTI_Port(uint8_t port, uint8_t pin);

#endif