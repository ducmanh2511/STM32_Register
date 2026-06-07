#ifndef ADC_H
#define ADC_H
#include <stdint.h>
#define ADC1_ADD_BASE     0x4001 2400 
#define ADC2_ADD_BASE     0x4001 2400  
typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;
} ADC_TypeDef;
#define ADC_CR2_ADON       (1U << 0)
#define ADC_CR2_CAL        (1U << 2)
#define ADC_CR2_RSTCAL     (1U << 3)
#define ADC_CR2_EXTTRIG    (1U << 20)
#define ADC_CR2_SWSTART    (1U << 22)

#define ADC_SR_EOC         (1U << 1)
#define ADC_SAMPLE_55_5    5

void ADC1_Init(void);
void ADC1_SelectChannel(uint8_t channel);
void ADC1_Start(void);
uint16_t ADC1_Read(void);
uint16_t ADC1_ReadChannel(uint8_t channel);
#define ADC1    ((ADC_TypeDef *)ADC1_BASE_ADDR)


#endif

