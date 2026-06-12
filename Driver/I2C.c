#include "I2C.h"

void I2C1_Init(void){
	RCC->RCC_APB1ENR |= (1U<<21);   // enable I2C1 clock
	RCC_GPIOB_EnableClock();
	RCC_AFIO_EnableClock();
	
	// PB6 = SCL, PB7 = SDA, open drain
	GPIO_InitPin(GPIOB, GPIO_PIN_6, GPIO_MODE_AF_OD_50MHz);
	GPIO_InitPin(GPIOB, GPIO_PIN_7, GPIO_MODE_AF_OD_50MHz);
	
	I2C->I2C_CR1 &= ~I2C_CR1_PE;   // disable I2C
	I2C->I2C_CR2 |= I2C_CR2_FREQ;  // set freq = 8MHz
	

	I2C->I2C_CCR = 40;
	I2C->I2C_TRISE = 9;  
	
	I2C->I2C_CR1 |= I2C_CR1_PE;    // enable I2C
}

void I2C1_Start(void){
	while(I2C->I2C_SR2 & (1U<<1));  // wait bus not busy
	I2C->I2C_CR1 |= I2C_CR1_START;
	while(!(I2C->I2C_SR1 & I2C_SR1_SB));  // wait START sent
}

void I2C1_Stop(void){
	I2C->I2C_CR1 |= I2C_CR1_STOP;
	while(I2C->I2C_CR1 & I2C_CR1_STOP);  // wait STOP sent
}

void I2C1_SendAddr(uint8_t addr, uint8_t rw){
	uint8_t tmp = (addr << 1) | (rw&0x01);
	I2C->I2C_DR = tmp;
    /*
    Khi master gui dia chi, slave nhan duoc se ACK lai va set ADDR len 1
    De clear ADDR phai doc I2C_SR1 va I2C_SR2
      */
	while(!(I2C->I2C_SR1 & I2C_SR1_ADDR));  // wait ADDR ACK
	tmp = I2C->I2C_SR2;  // clear ADDR flag
}

void I2C1_SendData(uint8_t data){
	while(!(I2C->I2C_SR1 & I2C_SR1_TXE));  // wait TXE
	I2C->I2C_DR = data;
	while(!(I2C->I2C_SR1 & I2C_SR1_BTF)); // wait byte transfer finish
}

uint8_t I2C1_RecvData(void){
	while(!(I2C->I2C_SR1 & I2C_SR1_RXNE));  // wait data
	return (uint8_t)I2C->I2C_DR;
}

void I2C1_Ack(void){
	I2C->I2C_CR1 |= I2C_CR1_ACK;
}

void I2C1_Nack(void){
	I2C->I2C_CR1 &= ~I2C_CR1_ACK;
}

