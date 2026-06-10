#ifndef I2C_H
#define I2C_H
#include <stdint.h>

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


#endif