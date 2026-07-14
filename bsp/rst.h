// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef RST_H
#define RST_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t SR;
} rst_t;

/* SR */
enum : uint8_t {
    RST_SR_EMCF   = BIT(4),
    RST_SR_SWIMF  = BIT(3),
    RST_SR_ILLOPF = BIT(2),
    RST_SR_IWDGF  = BIT(1),
    RST_SR_WWDGF  = BIT(0),
};

#define RST ((rst_t *)0x50B3)

#endif /* RST_H */
