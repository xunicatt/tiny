// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef TIM2_H
#define TIM2_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    uint8_t reserved_1;
    uint8_t reserved_2;
    volatile uint8_t IER;
    volatile uint8_t SR1;
    volatile uint8_t SR2;
    volatile uint8_t EGR;
    volatile uint8_t CCMR1;
    volatile uint8_t CCMR2;
    volatile uint8_t CCMR3;
    volatile uint8_t CCER1;
    volatile uint8_t CCER2;
    volatile uint8_t CNTRH;
    volatile uint8_t CNTRL;
    volatile uint8_t PSCR;
    volatile uint8_t ARRH;
    volatile uint8_t ARRL;
    volatile uint8_t CCR1H;
    volatile uint8_t CCR1L;
    volatile uint8_t CCR2H;
    volatile uint8_t CCR2L;
    volatile uint8_t CCR3H;
    volatile uint8_t CCR3L;
} tim2_t;

/* Reset values */
enum : uint8_t {
    TIM2_CR1_RESET_VALUE   = 0x00,
    TIM2_IER_RESET_VALUE   = 0x00,
    TIM2_SR1_RESET_VALUE   = 0x00,
    TIM2_SR2_RESET_VALUE   = 0x00,
    TIM2_EGR_RESET_VALUE   = 0x00,
    TIM2_CCMR1_RESET_VALUE = 0x00,
    TIM2_CCMR2_RESET_VALUE = 0x00,
    TIM2_CCMR3_RESET_VALUE = 0x00,
    TIM2_CCER1_RESET_VALUE = 0x00,
    TIM2_CCER2_RESET_VALUE = 0x00,
    TIM2_CNTRH_RESET_VALUE = 0x00,
    TIM2_CNTRL_RESET_VALUE = 0x00,
    TIM2_PSCR_RESET_VALUE  = 0x00,
    TIM2_ARRH_RESET_VALUE  = 0xFF,
    TIM2_ARRL_RESET_VALUE  = 0xFF,
    TIM2_CCR1H_RESET_VALUE = 0x00,
    TIM2_CCR1L_RESET_VALUE = 0x00,
    TIM2_CCR2H_RESET_VALUE = 0x00,
    TIM2_CCR2L_RESET_VALUE = 0x00,
    TIM2_CCR3H_RESET_VALUE = 0x00,
    TIM2_CCR3L_RESET_VALUE = 0x00,
};

/* CR1 */
enum : uint8_t {
    TIM2_CR1_ARPE = BIT(7),
    TIM2_CR1_OPM  = BIT(3),
    TIM2_CR1_URS  = BIT(2),
    TIM2_CR1_UDIS = BIT(1),
    TIM2_CR1_CEN  = BIT(0),
};

/* IER */
enum : uint8_t {
    TIM2_IER_CC3IE = BIT(3),
    TIM2_IER_CC2IE = BIT(2),
    TIM2_IER_CC1IE = BIT(1),
    TIM2_IER_UIE   = BIT(0),
};

/* SR1 */
enum : uint8_t {
    TIM2_SR1_CC3IF = BIT(3),
    TIM2_SR1_CC2IF = BIT(2),
    TIM2_SR1_CC1IF = BIT(1),
    TIM2_SR1_UIF   = BIT(0),
};

/* SR2 */
enum : uint8_t {
    TIM2_SR2_CC3OF = BIT(3),
    TIM2_SR2_CC2OF = BIT(2),
    TIM2_SR2_CC1OF = BIT(1),
};

/* EGR */
enum : uint8_t {
    TIM2_EGR_CC3G = BIT(3),
    TIM2_EGR_CC2G = BIT(2),
    TIM2_EGR_CC1G = BIT(1),
    TIM2_EGR_UG   = BIT(0),
};

/* CCMR */
enum : uint8_t {
    TIM2_CCMR_ICxPSC = 0x0C,
    TIM2_CCMR_ICxF   = 0xF0,
    TIM2_CCMR_OCM    = 0x70,
    TIM2_CCMR_OCxPE  = BIT(3),
    TIM2_CCMR_CCxS   = 0x03,
};

/* CCER1 */
enum : uint8_t {
    TIM2_CCER1_CC2P = BIT(5),
    TIM2_CCER1_CC2E = BIT(4),
    TIM2_CCER1_CC1P = BIT(1),
    TIM2_CCER1_CC1E = BIT(0),
};

/* CCER2 */
enum : uint8_t {
    TIM2_CCER2_CC3P = BIT(1),
    TIM2_CCER2_CC3E = BIT(0),
};

/* Field values */
enum : uint8_t {
    TIM2_PSCR_DIV1     = 0x00,
    TIM2_PSCR_DIV2     = 0x01,
    TIM2_PSCR_DIV4     = 0x02,
    TIM2_PSCR_DIV8     = 0x03,
    TIM2_PSCR_DIV16    = 0x04,
    TIM2_PSCR_DIV32    = 0x05,
    TIM2_PSCR_DIV64    = 0x06,
    TIM2_PSCR_DIV128   = 0x07,
    TIM2_PSCR_DIV256   = 0x08,
    TIM2_PSCR_DIV512   = 0x09,
    TIM2_PSCR_DIV1024  = 0x0A,
    TIM2_PSCR_DIV2048  = 0x0B,
    TIM2_PSCR_DIV4096  = 0x0C,
    TIM2_PSCR_DIV8192  = 0x0D,
    TIM2_PSCR_DIV16384 = 0x0E,
    TIM2_PSCR_DIV32768 = 0x0F,
};

#define TIM2 ((tim2_t *)0x5300)

#endif /* TIM2_H */
