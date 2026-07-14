// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef AWU_H
#define AWU_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CSR;
    volatile uint8_t APR;
    volatile uint8_t TBR;
} awu_t;

/* Reset values */
enum : uint8_t {
    AWU_CSR_RESET_VALUE = 0x00,
    AWU_APR_RESET_VALUE = 0x3F,
    AWU_TBR_RESET_VALUE = 0x00,
};

/* CSR */
enum : uint8_t {
    AWU_CSR_AWUF  = BIT(5),
    AWU_CSR_AWUEN = BIT(4),
    AWU_CSR_MSR   = BIT(0),
};

/* APR */
enum : uint8_t {
    AWU_APR_APR = 0x3F,
};

/* TBR */
enum : uint8_t {
    AWU_TBR_AWUTB = 0x0F,
};

#define AWU ((awu_t *)0x50F0)

#endif /* AWU_H */
