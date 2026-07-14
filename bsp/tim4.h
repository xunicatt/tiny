#ifndef TIM4_H
#define TIM4_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    uint8_t reserved_1;
    uint8_t reserved_2;
    volatile uint8_t IER;
    volatile uint8_t SR1;
    volatile uint8_t EGR;
    volatile uint8_t CNTR;
    volatile uint8_t PSCR;
    volatile uint8_t ARR;
} tim4_t;

/* Reset values */
enum : uint8_t {
    TIM4_CR1_RESET_VALUE  = 0x00,
    TIM4_IER_RESET_VALUE  = 0x00,
    TIM4_SR1_RESET_VALUE  = 0x00,
    TIM4_EGR_RESET_VALUE  = 0x00,
    TIM4_CNTR_RESET_VALUE = 0x00,
    TIM4_PSCR_RESET_VALUE = 0x00,
    TIM4_ARR_RESET_VALUE  = 0xFF,
};

/* CR1 */
enum : uint8_t {
    TIM4_CR1_ARPE = BIT(7),
    TIM4_CR1_OPM  = BIT(3),
    TIM4_CR1_URS  = BIT(2),
    TIM4_CR1_UDIS = BIT(1),
    TIM4_CR1_CEN  = BIT(0),
};

/* IER */
enum : uint8_t {
    TIM4_IER_UIE = BIT(0),
};

/* SR1 */
enum : uint8_t {
    TIM4_SR1_UIF = BIT(0),
};

/* EGR */
enum : uint8_t {
    TIM4_EGR_UG = BIT(0),
};

/* Field values */
enum : uint8_t {
    TIM4_PSCR_DIV1   = 0x00,
    TIM4_PSCR_DIV2   = 0x01,
    TIM4_PSCR_DIV4   = 0x02,
    TIM4_PSCR_DIV8   = 0x03,
    TIM4_PSCR_DIV16  = 0x04,
    TIM4_PSCR_DIV32  = 0x05,
    TIM4_PSCR_DIV64  = 0x06,
    TIM4_PSCR_DIV128 = 0x07,
};

#define TIM4 ((tim4_t *)0x5340)

#endif /* TIM4_H */
