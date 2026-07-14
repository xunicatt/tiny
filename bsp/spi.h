// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef SPI_H
#define SPI_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t ICR;
    volatile uint8_t SR;
    volatile uint8_t DR;
    volatile uint8_t CRCPR;
    volatile uint8_t RXCRCR;
    volatile uint8_t TXCRCR;
} spi_t;

/* Reset values */
enum : uint8_t {
    SPI_CR1_RESET_VALUE    = 0x00,
    SPI_CR2_RESET_VALUE    = 0x00,
    SPI_ICR_RESET_VALUE    = 0x00,
    SPI_SR_RESET_VALUE     = 0x02,
    SPI_DR_RESET_VALUE     = 0x00,
    SPI_CRCPR_RESET_VALUE  = 0x07,
    SPI_RXCRCR_RESET_VALUE = 0x00,
    SPI_TXCRCR_RESET_VALUE = 0x00,
};

/* CR1 */
enum : uint8_t {
    SPI_CR1_LSBFIRST = BIT(7),
    SPI_CR1_SPE      = BIT(6),
    SPI_CR1_BR       = 0x38,
    SPI_CR1_MSTR     = BIT(2),
    SPI_CR1_CPOL     = BIT(1),
    SPI_CR1_CPHA     = BIT(0),
};

/* Field values */
enum : uint8_t {
    SPI_CR1_BR_DIV2   = 0x00,
    SPI_CR1_BR_DIV4   = 0x08,
    SPI_CR1_BR_DIV8   = 0x10,
    SPI_CR1_BR_DIV16  = 0x18,
    SPI_CR1_BR_DIV32  = 0x20,
    SPI_CR1_BR_DIV64  = 0x28,
    SPI_CR1_BR_DIV128 = 0x30,
    SPI_CR1_BR_DIV256 = 0x38,
};

/* CR2 */
enum : uint8_t {
    SPI_CR2_BDM     = BIT(7),
    SPI_CR2_BDOE    = BIT(6),
    SPI_CR2_CRCEN   = BIT(5),
    SPI_CR2_CRCNEXT = BIT(4),
    SPI_CR2_RXONLY  = BIT(2),
    SPI_CR2_SSM     = BIT(1),
    SPI_CR2_SSI     = BIT(0),
};

/* ICR */
enum : uint8_t {
    SPI_ICR_TXEI  = BIT(7),
    SPI_ICR_RXEI  = BIT(6),
    SPI_ICR_ERRIE = BIT(5),
    SPI_ICR_WKIE  = BIT(4),
};

/* SR */
enum : uint8_t {
    SPI_SR_BSY    = BIT(7),
    SPI_SR_OVR    = BIT(6),
    SPI_SR_MODF   = BIT(5),
    SPI_SR_CRCERR = BIT(4),
    SPI_SR_WKUP   = BIT(3),
    SPI_SR_TXE    = BIT(1),
    SPI_SR_RXNE   = BIT(0),
};

#define SPI ((spi_t *)0x5200)

#endif /* SPI_H */
