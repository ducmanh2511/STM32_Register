#include "ADC.h"
void ADC1_Init(uint8_t channel, uint32_t sample){
	uint16_t shift = 3*channel;
	   if(channel<10){
			 ADC1->SMPR2 &= ~(0x07U<<shift);
			 ADC1->SMPR2 |= (sample<<shift);
		 }
		 else{
        channel -= 10;
        shift = 3 * channel;

        ADC1->SMPR1 &= ~(0x07U << shift);
        ADC1->SMPR1 |=  (sample << shift);
    }
		    ADC1->SQR3 &= ~(0x1FU);
        ADC1->SQR3 |= channel;
		    ADC1->SQR1 &= ~(0xFU << 20);
		
	    	ADC1->CR2 |= ADC_CR2_ADON; // ADC on
		
     for ( int i = 0; i < 1000; i++);
		   ADC1->CR2 |= ADC_CR2_RSTCAL; 
    while (ADC1->CR2 & ADC_CR2_RSTCAL);

    ADC1->CR2 |= ADC_CR2_CAL;  
    while (ADC1->CR2 & ADC_CR2_CAL);

    /* enable trigger */
    ADC1->CR2 |= (7U << 17);
    ADC1->CR2 |= ADC_CR2_EXTTRIG;
}
void ADC1_Start(void)
{
    ADC1->CR2 |= ADC_CR2_SWSTART;
}
uint16_t ADC1_Read(void)
{
    while (!(ADC1->SR & ADC_SR_EOC));

    return (uint16_t)ADC1->DR;
}