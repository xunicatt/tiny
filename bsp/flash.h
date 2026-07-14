// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t NCR2;
    volatile uint8_t FPR;
    volatile uint8_t NFPR;
    volatile uint8_t IAPSR;
    uint8_t reserved_1;
    uint8_t reserved_2;
    volatile uint8_t PUKR;
    uint8_t reserved_3;
    volatile uint8_t DUKR;
} flash_t;

/* Reset values */
enum : uint8_t {
    FLASH_CR1_RESET_VALUE   = 0x00,
    FLASH_CR2_RESET_VALUE   = 0x00,
    FLASH_NCR2_RESET_VALUE  = 0xFF,
    FLASH_IAPSR_RESET_VALUE = 0x40,
    FLASH_PUKR_RESET_VALUE  = 0x00,
    FLASH_DUKR_RESET_VALUE  = 0x00,
};

/* CR1 */
enum : uint8_t {
    FLASH_CR1_HALT  = BIT(3),
    FLASH_CR1_AHALT = BIT(2),
    FLASH_CR1_IE    = BIT(1),
    FLASH_CR1_FIX   = BIT(0),
};

/* CR2 */
enum : uint8_t {
    FLASH_CR2_OPT   = BIT(7),
    FLASH_CR2_WPRG  = BIT(6),
    FLASH_CR2_ERASE = BIT(5),
    FLASH_CR2_FPRG  = BIT(4),
    FLASH_CR2_PRG   = BIT(0),
};

/* NCR2 */
enum : uint8_t {
    FLASH_NCR2_NOPT   = BIT(7),
    FLASH_NCR2_NWPRG  = BIT(6),
    FLASH_NCR2_NERASE = BIT(5),
    FLASH_NCR2_NFPRG  = BIT(4),
    FLASH_NCR2_NPRG   = BIT(0),
};

/* IAPSR */
enum : uint8_t {
    FLASH_IAPSR_HVOFF     = BIT(6),
    FLASH_IAPSR_DUL       = BIT(3),
    FLASH_IAPSR_EOP       = BIT(2),
    FLASH_IAPSR_PUL       = BIT(1),
    FLASH_IAPSR_WR_PG_DIS = BIT(0),
};

/* Keys */
enum : uint8_t {
    FLASH_PUKR_KEY1 = 0x56,
    FLASH_PUKR_KEY2 = 0xAE,

    FLASH_DUKR_KEY1 = 0xAE,
    FLASH_DUKR_KEY2 = 0x56,
};

#define FLASH ((flash_t *)0x505A)

#endif /* FLASH_H */
