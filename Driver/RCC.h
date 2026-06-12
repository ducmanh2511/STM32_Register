#ifndef RCC_H
#define RCC_H
#include <stdint.h>

/*================================BASE ADDRESS===============================*/
#define RCC_ADD_BASE              0x40021000UL

/*===========================================================================*/
#define RCC_CR_HSION                       (1U<<0)
#define RCC_CR_HSIRDY                      (1U<<1)      

#define RCC_CR_HSEON                       (1U<<16)
#define RCC_CR_HSERDY                      (1U<<17) 
#define RCC_CR_HSEBYP                      (1U<<18)

#define RCC_CR_CSSON                       (1U<<19)
#define RCC_CR_PLLON                       (1U<<24)
#define RCC_CR_PLLRDY                      (1U<<25)

#define RCC_CFGR_SW_MASK                   (0x3U<<0)
#define RCC_CFGR_SW_HSI                    (0x0U<<0)
#define RCC_CFGR_SW_HSE                    (0x1U<<0)
#define RCC_CFGR_SW_PLL                    (0x2U<<0)
#define RCC_CFGR_SW_NOT_ALLOW              (0x3U<<0)

#define RCC_CFGR_SWS_MASK                  (0x3U<<2)
#define RCC_CFGR_SWS_HSI                   (0x0U<<2)
#define RCC_CFGR_SWS_HSE                   (0x1U<<2)
#define RCC_CFGR_SWS_PLL                   (0x2U<<2)
#define RCC_CFGR_SWS_NOT_APPLICABLE        (0x3U<<2)


#define RCC_CFGR_HPRE_MASK                (0xFU << 4)
#define RCC_CFGR_HPRE_DIV1                (0x0U<<4)
#define RCC_CFGR_HPRE_DIV2                (0x8U<<4)
#define RCC_CFGR_HPRE_DIV4                (0x9U<<4)
#define RCC_CFGR_HPRE_DIV8                (0xAU<<4)

#define RCC_CFGR_PPRE1_MASK               (0x7U<< 8)
#define RCC_CFGR_PPRE1_HCLK_DIV1          (0x0U<<8)
#define RCC_CFGR_PPRE1_HCLK_DIV2          (0x4U<<8)
#define RCC_CFGR_PPRE1_HCLK_DIV4          (0x5U<<8)
#define RCC_CFGR_PPRE1_HCLK_DIV8          (0x6U<<8)

#define RCC_CFGR_PPRE2_MASK               (0x7U<<11)
#define RCC_CFGR_PPRE2_HCLK_DIV1          (0x0U<<11)
#define RCC_CFGR_PPRE2_HCLK_DIV2          (0x4U<<11)
#define RCC_CFGR_PPRE2_HCLK_DIV4          (0x5U<<11)
#define RCC_CFGR_PPRE2_HCLK_DIV8          (0x6U<<11)

#define RCC_CFGR_PLLSRC_MASK              (0x1U<<16)
#define RCC_CFGR_PLLSRC_HSI               (0x0U<<16)
#define RCC_CFGR_PLLSRC_HSE               (0x1U<<16)

#define RCC_CFGR_PLLXTPRE_MASK                  (0x1U<<17)
#define RCC_CFGR_PLLXTPRE_HSE_DIV1              (0x0U<<17)
#define RCC_CFGR_PLLXTPRE_HSE_DIV2              (0x1U<<17)

#define RCC_CFGR_PLLMUL_MASK                    (0xFU<<18)
#define RCC_CFGR_PLLMUL_x2                      (0x0U<<18)
#define RCC_CFGR_PLLMUL_x3                      (0x1U<<18)
#define RCC_CFGR_PLLMUL_x4                      (0x2U<<18)
#define RCC_CFGR_PLLMUL_x5                      (0x3U<<18)
#define RCC_CFGR_PLLMUL_x6                      (0x4U<<18)
#define RCC_CFGR_PLLMUL_x7                      (0x5U<<18)
#define RCC_CFGR_PLLMUL_x8                      (0x6U<<18)
#define RCC_CFGR_PLLMUL_x9                      (0x7U<<18)

#define RCC_APB2ENR_AFIO                        (0x1U<<0)

#define RCC_APB2ENR_IOPA                        (0x1U<<2)
#define RCC_APB2ENR_IOPB                        (0x1U<<3)
#define RCC_APB2ENR_IOPC                        (0x1U<<4)
#define RCC_APB2ENR_IOPD                        (0x1U<<5)
#define RCC_APB2ENR_IOPE                        (0x1U<<6)

#define RCC_APB2ENR_ADC1                        (0x1U<<9)
#define RCC_APB2ENR_ADC2                        (0x1U<<10)

#define RCC_APB2ENR_TIM1                        (0x1U<<11)
#define RCC_APB2ENR_SPI1                        (0x1U<<12)
#define RCC_APB2ENR_UART1                       (0x1U<<14)

#define RCC_APB1ENR_TIM2                       (0x1U<<0)
#define RCC_APB1ENR_TIM3                       (0x1U<<1)
#define RCC_APB1ENR_SPI2                       (0x1U<<14)
#define RCC_APB1ENR_UART2                      (0x1U<<17)
#define RCC_APB1ENR_I2C1                       (0x1U<<21)
#define RCC_APB1ENR_I2C2                       (0x1U<<22)

/*==================BASE ADDRESS FLASH================*/
#define FLASH_ACR_BASE                             0x40022000UL
#define FLASH_ACR                                  (0x40022000UL+0x00UL)
#define ACR                                        (*((volatile uint32_t*)FLASH_ACR))
#define FLASH_ACR_LATENCY_MASK                     (0x7U<<0)
#define FLASH_ACR_LATENCY0                         (0x0U<<0)
#define FLASH_ACR_LATENCY1                         (0x1U<<0)
#define FLASH_ACR_LATENCY2                         (0x2U<<0)
#define FLASH_ACR_PRFTBE                           (1U<<4)

typedef struct{
	volatile uint32_t RCC_CR; 
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
}RCC_Typedef;


#define RCC        ((RCC_Typedef*)RCC_ADD_BASE)


void RCC_GPIOA_EnableClock(void);
void RCC_GPIOB_EnableClock(void);
void RCC_GPIOC_EnableClock(void);
void RCC_GPIOD_EnableClock(void);
void RCC_GPIOE_EnableClock(void);
void RCC_TIM2_EnableClock(void);
void RCC_ADC1_EnableClock(void);
void RCC_I2C1_EnableClock(void);
void RCC_UART1_EnableClock(void);
void RCC_AFIO_EnableClock(void);
void RCC_SetSysCLK_72MHz(void);
#endif 