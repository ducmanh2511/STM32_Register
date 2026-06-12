#ifndef I2C_H
#define I2C_H
#include <stdint.h>
#include "GPIO.h"

#define I2C_ADD_BASE       0x40005400
typedef struct {
	volatile uint32_t I2C_CR1;
	volatile uint32_t I2C_CR2;
	volatile uint32_t I2C_OAR1;
	volatile uint32_t I2C_OAR2;
	volatile uint32_t I2C_DR;
	volatile uint32_t I2C_SR1;
	volatile uint32_t I2C_SR2;
	volatile uint32_t I2C_CCR;
	volatile uint32_t I2C_TRISE;
	
}I2C_Typedef;
#define I2C                ((I2C_Typedef *)I2C_ADD_BASE)

#define I2C_CR1_PE         (1U<<0)
#define I2C_CR1_START      (1U<<8)
#define I2C_CR1_STOP       (1U<<9)
#define I2C_CR1_ACK        (1U<<10)
#define I2C_CR2_FREQ       (8U<<0)
#define I2C_SR1_SB         (1U<<0)
#define I2C_SR1_ADDR       (1U<<1)
#define I2C_SR1_BTF        (1U<<2)
#define I2C_SR1_RXNE       (1U<<6)
#define I2C_SR1_TXE        (1U<<7)

#define I2C_WRITE          0
#define I2C_READ           1

void I2C1_Init(void);
void I2C1_Start(void);
void I2C1_Stop(void);
void I2C1_SendAddr(uint8_t addr, uint8_t dir);
void I2C1_SendData(uint8_t data);
uint8_t I2C1_RecvData(void);
void I2C1_Ack(void);
void I2C1_Nack(void);
uint8_t I2C1_CheckFlag(uint32_t flag);

#endif