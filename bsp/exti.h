// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    volatile uint8_t CR2;
} exti_t;

/* Reset values */
enum : uint8_t {
    EXTI_CR1_RESET_VALUE = 0x00,
    EXTI_CR2_RESET_VALUE = 0x00,
};

/* CR1 */
enum : uint8_t {
    EXTI_CR1_PDIS = 0xC0,
    EXTI_CR1_PCIS = 0x30,
    EXTI_CR1_PBIS = 0x0C,
    EXTI_CR1_PAIS = 0x03,
};

/* CR2 */
enum : uint8_t {
    EXTI_CR2_TLIS = BIT(2),
    EXTI_CR2_PEIS = 0x03,
};

/* Sensitivity */
enum : uint8_t {
    EXTI_SENSITIVITY_FALL_LOW  = 0x00,
    EXTI_SENSITIVITY_RISE      = 0x01,
    EXTI_SENSITIVITY_FALL      = 0x02,
    EXTI_SENSITIVITY_RISE_FALL = 0x03,
};

#define EXTI ((exti_t *)0x50A0)

#endif /* EXTI_H */
