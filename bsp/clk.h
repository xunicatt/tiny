#ifndef CLK_H
#define CLK_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t ICKR;
    volatile uint8_t ECKR;
    uint8_t reserved;
    volatile uint8_t CMSR;
    volatile uint8_t SWR;
    volatile uint8_t SWCR;
    volatile uint8_t CKDIVR;
    volatile uint8_t PCKENR1;
    volatile uint8_t CSSR;
    volatile uint8_t CCOR;
    volatile uint8_t PCKENR2;
    uint8_t reserved1;
    volatile uint8_t HSITRIMR;
    volatile uint8_t SWIMCCR;
} clk_t;

/* Reset values */
enum : uint8_t {
    CLK_ICKR_RESET_VALUE     = 0x01,
    CLK_ECKR_RESET_VALUE     = 0x00,
    CLK_CMSR_RESET_VALUE     = 0xE1,
    CLK_SWR_RESET_VALUE      = 0xE1,
    CLK_SWCR_RESET_VALUE     = 0x00,
    CLK_CKDIVR_RESET_VALUE   = 0x18,
    CLK_PCKENR1_RESET_VALUE  = 0xFF,
    CLK_PCKENR2_RESET_VALUE  = 0xFF,
    CLK_CSSR_RESET_VALUE     = 0x00,
    CLK_CCOR_RESET_VALUE     = 0x00,
    CLK_HSITRIMR_RESET_VALUE = 0x00,
    CLK_SWIMCCR_RESET_VALUE  = 0x00,
};

/* ICKR */
enum : uint8_t {
    CLK_ICKR_SWUAH  = BIT(5),
    CLK_ICKR_LSIRDY = BIT(4),
    CLK_ICKR_LSIEN  = BIT(3),
    CLK_ICKR_FHWU   = BIT(2),
    CLK_ICKR_HSIRDY = BIT(1),
    CLK_ICKR_HSIEN  = BIT(0),
};

/* ECKR */
enum : uint8_t {
    CLK_ECKR_HSERDY = BIT(1),
    CLK_ECKR_HSEEN  = BIT(0),
};

/* CMSR */
enum : uint8_t {
    CLK_CMSR_CKM = 0xFF,
};

/* SWR */
enum : uint8_t {
    CLK_SWR_SWI = 0xFF,
};

/* SWCR */
enum : uint8_t {
    CLK_SWCR_SWIF  = BIT(3),
    CLK_SWCR_SWIEN = BIT(2),
    CLK_SWCR_SWEN  = BIT(1),
    CLK_SWCR_SWBSY = BIT(0),
};

/* CKDIVR */
enum : uint8_t {
    CLK_CKDIVR_HSIDIV = 0x18,
    CLK_CKDIVR_CPUDIV = 0x07,
};

/* PCKENR1 */
enum : uint8_t {
    CLK_PCKENR1_TIM1  = BIT(7),
    CLK_PCKENR1_TIM3  = BIT(6),
    CLK_PCKENR1_TIM2  = BIT(5),
    CLK_PCKENR1_TIM4  = BIT(4),
    CLK_PCKENR1_UART1 = BIT(2),
    CLK_PCKENR1_SPI   = BIT(1),
    CLK_PCKENR1_I2C   = BIT(0),
};

/* PCKENR2 */
enum : uint8_t {
    CLK_PCKENR2_ADC = BIT(3),
    CLK_PCKENR2_AWU = BIT(2),
};

/* CSSR */
enum : uint8_t {
    CLK_CSSR_CSSD   = BIT(3),
    CLK_CSSR_CSSDIE = BIT(2),
    CLK_CSSR_AUX    = BIT(1),
    CLK_CSSR_CSSEN  = BIT(0),
};

/* CCOR */
enum : uint8_t {
    CLK_CCOR_CCOBSY = BIT(6),
    CLK_CCOR_CCORDY = BIT(5),
    CLK_CCOR_CCOSEL = 0x1E,
    CLK_CCOR_CCOEN  = BIT(0),
};

/* HSITRIMR */
enum : uint8_t {
    CLK_HSITRIMR_HSITRIM = 0x07,
};

/* SWIMCCR */
enum : uint8_t {
    CLK_SWIMCCR_SWIMDIV = BIT(0),
};

#define CLK ((clk_t *)0x50C0)

#endif /* CLK_H */
