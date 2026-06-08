#ifndef ADC_H
#define ADC_H
#include <stdint.h>
#define ADC1_ADD_BASE     0x40012400 
 
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


#define ADC_SAMPLE_28_5_CYCLES       0x03
#define ADC_SAMPLE_41_5_CYCLES       0x04
#define ADC_SAMPLE_55_5_CYCLES       0x05



#define ADC_SR_EOC         (1U << 1)
#define ADC_SAMPLE_55_5    5
#define ADC1    ((ADC_TypeDef *)ADC1_ADD_BASE)
void ADC1_Init(uint8_t channel, uint32_t sample);
void ADC1_Start(void);
void ADC1_Stop(void);
uint16_t ADC1_Read(void);




#endif

