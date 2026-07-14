// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef TIM1_H
#define TIM1_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t SMCR;
    volatile uint8_t ETR;
    volatile uint8_t IER;
    volatile uint8_t SR1;
    volatile uint8_t SR2;
    volatile uint8_t EGR;
    volatile uint8_t CCMR1;
    volatile uint8_t CCMR2;
    volatile uint8_t CCMR3;
    volatile uint8_t CCMR4;
    volatile uint8_t CCER1;
    volatile uint8_t CCER2;
    volatile uint8_t CNTRH;
    volatile uint8_t CNTRL;
    volatile uint8_t PSCRH;
    volatile uint8_t PSCRL;
    volatile uint8_t ARRH;
    volatile uint8_t ARRL;
    volatile uint8_t RCR;
    volatile uint8_t CCR1H;
    volatile uint8_t CCR1L;
    volatile uint8_t CCR2H;
    volatile uint8_t CCR2L;
    volatile uint8_t CCR3H;
    volatile uint8_t CCR3L;
    volatile uint8_t CCR4H;
    volatile uint8_t CCR4L;
    volatile uint8_t BKR;
    volatile uint8_t DTR;
    volatile uint8_t OISR;
} tim1_t;

/* Reset values */
enum : uint8_t {
    TIM1_CR1_RESET_VALUE   = 0x00,
    TIM1_CR2_RESET_VALUE   = 0x00,
    TIM1_SMCR_RESET_VALUE  = 0x00,
    TIM1_ETR_RESET_VALUE   = 0x00,
    TIM1_IER_RESET_VALUE   = 0x00,
    TIM1_SR1_RESET_VALUE   = 0x00,
    TIM1_SR2_RESET_VALUE   = 0x00,
    TIM1_EGR_RESET_VALUE   = 0x00,
    TIM1_CCMR1_RESET_VALUE = 0x00,
    TIM1_CCMR2_RESET_VALUE = 0x00,
    TIM1_CCMR3_RESET_VALUE = 0x00,
    TIM1_CCMR4_RESET_VALUE = 0x00,
    TIM1_CCER1_RESET_VALUE = 0x00,
    TIM1_CCER2_RESET_VALUE = 0x00,
    TIM1_CNTRH_RESET_VALUE = 0x00,
    TIM1_CNTRL_RESET_VALUE = 0x00,
    TIM1_PSCRH_RESET_VALUE = 0x00,
    TIM1_PSCRL_RESET_VALUE = 0x00,
    TIM1_ARRH_RESET_VALUE  = 0xFF,
    TIM1_ARRL_RESET_VALUE  = 0xFF,
    TIM1_RCR_RESET_VALUE   = 0x00,
    TIM1_CCR1H_RESET_VALUE = 0x00,
    TIM1_CCR1L_RESET_VALUE = 0x00,
    TIM1_CCR2H_RESET_VALUE = 0x00,
    TIM1_CCR2L_RESET_VALUE = 0x00,
    TIM1_CCR3H_RESET_VALUE = 0x00,
    TIM1_CCR3L_RESET_VALUE = 0x00,
    TIM1_CCR4H_RESET_VALUE = 0x00,
    TIM1_CCR4L_RESET_VALUE = 0x00,
    TIM1_BKR_RESET_VALUE   = 0x00,
    TIM1_DTR_RESET_VALUE   = 0x00,
    TIM1_OISR_RESET_VALUE  = 0x00,
};

/* CR1 */
enum : uint8_t {
    TIM1_CR1_ARPE = BIT(7),
    TIM1_CR1_CMS  = 0x60,
    TIM1_CR1_DIR  = BIT(4),
    TIM1_CR1_OPM  = BIT(3),
    TIM1_CR1_URS  = BIT(2),
    TIM1_CR1_UDIS = BIT(1),
    TIM1_CR1_CEN  = BIT(0),
};

/* CR2 */
enum : uint8_t {
    TIM1_CR2_TI1S = BIT(7),
    TIM1_CR2_MMS  = 0x70,
    TIM1_CR2_COMS = BIT(2),
    TIM1_CR2_CCPC = BIT(0),
};

/* SMCR */
enum : uint8_t {
    TIM1_SMCR_MSM = BIT(7),
    TIM1_SMCR_TS  = 0x70,
    TIM1_SMCR_SMS = 0x07,
};

/* ETR */
enum : uint8_t {
    TIM1_ETR_ETP  = BIT(7),
    TIM1_ETR_ECE  = BIT(6),
    TIM1_ETR_ETPS = 0x30,
    TIM1_ETR_ETF  = 0x0F,
};

/* IER */
enum : uint8_t {
    TIM1_IER_BIE   = BIT(7),
    TIM1_IER_TIE   = BIT(6),
    TIM1_IER_COMIE = BIT(5),
    TIM1_IER_CC4IE = BIT(4),
    TIM1_IER_CC3IE = BIT(3),
    TIM1_IER_CC2IE = BIT(2),
    TIM1_IER_CC1IE = BIT(1),
    TIM1_IER_UIE   = BIT(0),
};

/* SR1 */
enum : uint8_t {
    TIM1_SR1_BIF   = BIT(7),
    TIM1_SR1_TIF   = BIT(6),
    TIM1_SR1_COMIF = BIT(5),
    TIM1_SR1_CC4IF = BIT(4),
    TIM1_SR1_CC3IF = BIT(3),
    TIM1_SR1_CC2IF = BIT(2),
    TIM1_SR1_CC1IF = BIT(1),
    TIM1_SR1_UIF   = BIT(0),
};

/* SR2 */
enum : uint8_t {
    TIM1_SR2_CC4OF = BIT(4),
    TIM1_SR2_CC3OF = BIT(3),
    TIM1_SR2_CC2OF = BIT(2),
    TIM1_SR2_CC1OF = BIT(1),
};

/* EGR */
enum : uint8_t {
    TIM1_EGR_BG   = BIT(7),
    TIM1_EGR_TG   = BIT(6),
    TIM1_EGR_COMG = BIT(5),
    TIM1_EGR_CC4G = BIT(4),
    TIM1_EGR_CC3G = BIT(3),
    TIM1_EGR_CC2G = BIT(2),
    TIM1_EGR_CC1G = BIT(1),
    TIM1_EGR_UG   = BIT(0),
};

/* CCMR */
enum : uint8_t {
    TIM1_CCMR_ICxPSC = 0x0C,
    TIM1_CCMR_ICxF   = 0xF0,
    TIM1_CCMR_OCM    = 0x70,
    TIM1_CCMR_OCxPE  = BIT(3),
    TIM1_CCMR_OCxFE  = BIT(2),
    TIM1_CCMR_CCxS   = 0x03,
};

/* CCER1 */
enum : uint8_t {
    TIM1_CCER1_CC2NP = BIT(7),
    TIM1_CCER1_CC2NE = BIT(6),
    TIM1_CCER1_CC2P  = BIT(5),
    TIM1_CCER1_CC2E  = BIT(4),
    TIM1_CCER1_CC1NP = BIT(3),
    TIM1_CCER1_CC1NE = BIT(2),
    TIM1_CCER1_CC1P  = BIT(1),
    TIM1_CCER1_CC1E  = BIT(0),
};

/* CCER2 */
enum : uint8_t {
    TIM1_CCER2_CC4P  = BIT(5),
    TIM1_CCER2_CC4E  = BIT(4),
    TIM1_CCER2_CC3NP = BIT(3),
    TIM1_CCER2_CC3NE = BIT(2),
    TIM1_CCER2_CC3P  = BIT(1),
    TIM1_CCER2_CC3E  = BIT(0),
};

/* BKR */
enum : uint8_t {
    TIM1_BKR_MOE  = BIT(7),
    TIM1_BKR_AOE  = BIT(6),
    TIM1_BKR_BKP  = BIT(5),
    TIM1_BKR_BKE  = BIT(4),
    TIM1_BKR_OSSR = BIT(3),
    TIM1_BKR_OSSI = BIT(2),
    TIM1_BKR_LOCK = 0x03,
};

/* DTR */
enum : uint8_t {
    TIM1_DTR_DTG = 0xFF,
};

/* OISR */
enum : uint8_t {
    TIM1_OISR_OIS4  = BIT(6),
    TIM1_OISR_OIS3N = BIT(5),
    TIM1_OISR_OIS3  = BIT(4),
    TIM1_OISR_OIS2N = BIT(3),
    TIM1_OISR_OIS2  = BIT(2),
    TIM1_OISR_OIS1N = BIT(1),
    TIM1_OISR_OIS1  = BIT(0),
};

#define TIM1 ((tim1_t *)0x5250)

#endif /* TIM1_H */
