// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef ITC_H
#define ITC_H

#include <stdint.h>

typedef struct {
    volatile uint8_t ISPR1;
    volatile uint8_t ISPR2;
    volatile uint8_t ISPR3;
    volatile uint8_t ISPR4;
    volatile uint8_t ISPR5;
    volatile uint8_t ISPR6;
    volatile uint8_t ISPR7;
    volatile uint8_t ISPR8;
} itc_t;

/* Reset values */
enum : uint8_t {
    ITC_SPRX_RESET_VALUE = 0xFF,
};

/* CPU CC */
enum : uint8_t {
    CPU_CC_I1I0 = 0x28,
};

/* Field values */
enum : uint8_t {
    ITC_PRIORITY_LEVEL_0 = 0x02,
    ITC_PRIORITY_LEVEL_1 = 0x01,
    ITC_PRIORITY_LEVEL_2 = 0x00,
    ITC_PRIORITY_LEVEL_3 = 0x03,
};

#define ITC ((itc_t *)0x7F70)

#endif /* ITC_H */
