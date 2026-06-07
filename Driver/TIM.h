#ifndef TIM_H
#define TIM_H
#include <stdint.h>  
#include <NVIC.h>
#define TIM2_ADD_BASE       0x40000000UL
#define TIM3_ADD_BASE       0x40000400UL
#define TIM4_ADD_BASE       0x40000800UL
// x: 2 to 5
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;

}TIMx_Typedef;
#define TIM_CR1_CEN     (1U << 0)
#define TIM_DIER_UIE    (1U << 0)
#define TIM_SR_UIF      (1U << 0)
#define TIM_EGR_UG      (1U << 0)

#define TIM2        ((volatile TIMx_Typedef*)TIM2_ADD_BASE)
#define TIM3        ((volatile TIMx_Typedef*)TIM3_ADD_BASE)
#define TIM4        ((volatile TIMx_Typedef*)TIM4_ADD_BASE)
void TIM_Init(TIMx_Typedef*tim, uint16_t psc, uint16_t arr);
void TIM_Start(TIMx_Typedef*tim);
void TIM_Start_IT(TIMx_Typedef*tim);
void TIM_Stop(TIMx_Typedef*tim);
void TIM_Stop_IT(TIMx_Typedef*tim);
uint8_t TIM_GetFlag(TIMx_Typedef *tim);
void TIM_ClearFlag(TIMx_Typedef *tim);
void TIM2_IRQHandler(void);

#endif
