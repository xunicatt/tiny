// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t FREQR;
    volatile uint8_t OARL;
    volatile uint8_t OARH;
    uint8_t reserved_1;
    volatile uint8_t DR;
    volatile uint8_t SR1;
    volatile uint8_t SR2;
    volatile uint8_t SR3;
    volatile uint8_t ITR;
    volatile uint8_t CCRL;
    volatile uint8_t CCRH;
    volatile uint8_t TRISER;
    uint8_t reserved_2;
} i2c_t;

/* Reset values */
enum : uint8_t {
    I2C_CR1_RESET_VALUE    = 0x00,
    I2C_CR2_RESET_VALUE    = 0x00,
    I2C_FREQR_RESET_VALUE  = 0x00,
    I2C_OARL_RESET_VALUE   = 0x00,
    I2C_OARH_RESET_VALUE   = 0x00,
    I2C_DR_RESET_VALUE     = 0x00,
    I2C_SR1_RESET_VALUE    = 0x00,
    I2C_SR2_RESET_VALUE    = 0x00,
    I2C_SR3_RESET_VALUE    = 0x00,
    I2C_ITR_RESET_VALUE    = 0x00,
    I2C_CCRL_RESET_VALUE   = 0x00,
    I2C_CCRH_RESET_VALUE   = 0x00,
    I2C_TRISER_RESET_VALUE = 0x02,
};

/* CR1 */
enum : uint8_t {
    I2C_CR1_NOSTRETCH = BIT(7),
    I2C_CR1_ENGC      = BIT(6),
    I2C_CR1_PE        = BIT(0),
};

/* CR2 */
enum : uint8_t {
    I2C_CR2_SWRST = BIT(7),
    I2C_CR2_POS   = BIT(3),
    I2C_CR2_ACK   = BIT(2),
    I2C_CR2_STOP  = BIT(1),
    I2C_CR2_START = BIT(0),
};

/* FREQR */
enum : uint8_t {
    I2C_FREQR_FREQ = 0x3F,
};

/* OARL */
enum : uint8_t {
    I2C_OARL_ADD  = 0xFE,
    I2C_OARL_ADD0 = BIT(0),
};

/* OARH */
enum : uint8_t {
    I2C_OARH_ADDMODE = BIT(7),
    I2C_OARH_ADDCONF = BIT(6),
    I2C_OARH_ADD     = 0x06,
};

/* SR1 */
enum : uint8_t {
    I2C_SR1_TXE   = BIT(7),
    I2C_SR1_RXNE  = BIT(6),
    I2C_SR1_STOPF = BIT(4),
    I2C_SR1_ADD10 = BIT(3),
    I2C_SR1_BTF   = BIT(2),
    I2C_SR1_ADDR  = BIT(1),
    I2C_SR1_SB    = BIT(0),
};

/* SR2 */
enum : uint8_t {
    I2C_SR2_WUFH = BIT(5),
    I2C_SR2_OVR  = BIT(3),
    I2C_SR2_AF   = BIT(2),
    I2C_SR2_ARLO = BIT(1),
    I2C_SR2_BERR = BIT(0),
};

/* SR3 */
enum : uint8_t {
    I2C_SR3_GENCALL = BIT(4),
    I2C_SR3_TRA     = BIT(2),
    I2C_SR3_BUSY    = BIT(1),
    I2C_SR3_MSL     = BIT(0),
};

/* ITR */
enum : uint8_t {
    I2C_ITR_ITBUFEN = BIT(2),
    I2C_ITR_ITEVTEN = BIT(1),
    I2C_ITR_ITERREN = BIT(0),
};

/* CCRH */
enum : uint8_t {
    I2C_CCRH_FS   = BIT(7),
    I2C_CCRH_DUTY = BIT(6),
    I2C_CCRH_CCR  = 0x0F,
};

/* TRISER */
enum : uint8_t {
    I2C_TRISER_TRISE = 0x3F,
};

#define I2C ((i2c_t *)0x5210)

#endif /* I2C_H */
