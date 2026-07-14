// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef ADC1_H
#define ADC1_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t DB0RH;
    volatile uint8_t DB0RL;
    volatile uint8_t DB1RH;
    volatile uint8_t DB1RL;
    volatile uint8_t DB2RH;
    volatile uint8_t DB2RL;
    volatile uint8_t DB3RH;
    volatile uint8_t DB3RL;
    volatile uint8_t DB4RH;
    volatile uint8_t DB4RL;
    volatile uint8_t DB5RH;
    volatile uint8_t DB5RL;
    volatile uint8_t DB6RH;
    volatile uint8_t DB6RL;
    volatile uint8_t DB7RH;
    volatile uint8_t DB7RL;
    volatile uint8_t DB8RH;
    volatile uint8_t DB8RL;
    volatile uint8_t DB9RH;
    volatile uint8_t DB9RL;
    uint8_t reserved[12];
    volatile uint8_t CSR;
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t CR3;
    volatile uint8_t DRH;
    volatile uint8_t DRL;
    volatile uint8_t TDRH;
    volatile uint8_t TDRL;
    volatile uint8_t HTRH;
    volatile uint8_t HTRL;
    volatile uint8_t LTRH;
    volatile uint8_t LTRL;
    volatile uint8_t AWSRH;
    volatile uint8_t AWSRL;
    volatile uint8_t AWCRH;
    volatile uint8_t AWCRL;
} adc1_t;

/* Reset values */

enum : uint8_t {
    ADC1_CSR_RESET_VALUE   = 0x00,
    ADC1_CR1_RESET_VALUE   = 0x00,
    ADC1_CR2_RESET_VALUE   = 0x00,
    ADC1_CR3_RESET_VALUE   = 0x00,
    ADC1_TDRH_RESET_VALUE  = 0x00,
    ADC1_TDRL_RESET_VALUE  = 0x00,
    ADC1_HTRH_RESET_VALUE  = 0xFF,
    ADC1_HTRL_RESET_VALUE  = 0x03,
    ADC1_LTRH_RESET_VALUE  = 0x00,
    ADC1_LTRL_RESET_VALUE  = 0x00,
    ADC1_AWCRH_RESET_VALUE = 0x00,
    ADC1_AWCRL_RESET_VALUE = 0x00,
};

/* CSR */
enum : uint8_t {
    ADC1_CSR_EOC   = BIT(7),
    ADC1_CSR_AWD   = BIT(6),
    ADC1_CSR_EOCIE = BIT(5),
    ADC1_CSR_AWDIE = BIT(4),

    ADC1_CSR_CH = 0x0F,
};

/* CR1 */
enum : uint8_t {
    ADC1_CR1_SPSEL = 0x70,

    ADC1_CR1_CONT = BIT(1),
    ADC1_CR1_ADON = BIT(0),
};

/* CR2 */
enum : uint8_t {
    ADC1_CR2_EXTTRIG = BIT(6),

    ADC1_CR2_EXTSEL = 0x30,

    ADC1_CR2_ALIGN = BIT(3),
    ADC1_CR2_SCAN  = BIT(1),
};

/* CR3 */
enum : uint8_t {
    ADC1_CR3_DBUF = BIT(7),
    ADC1_CR3_OVR  = BIT(6),
};

#define ADC1 ((adc1_t *)0x53E0)

#endif /* ADC1_H */
