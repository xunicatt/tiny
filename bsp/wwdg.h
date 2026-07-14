// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef WWDG_H
#define WWDG_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR;
    volatile uint8_t WR;
} wwdg_t;

/* Reset values */
enum : uint8_t {
    WWDG_CR_RESET_VALUE = 0x7F,
    WWDG_WR_RESET_VALUE = 0x7F,
};

/* CR */
enum : uint8_t {
    WWDG_CR_WDGA = BIT(7),
    WWDG_CR_T6   = BIT(6),
    WWDG_CR_T    = 0x7F,
};

/* WR */
enum : uint8_t {
    WWDG_WR_MSB = BIT(7),
    WWDG_WR_W   = 0x7F,
};

#define WWDG ((wwdg_t *)0x50D1)

#endif /* WWDG_H */
