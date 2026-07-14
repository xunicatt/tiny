// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef UART1_H
#define UART1_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t SR;
    volatile uint8_t DR;
    volatile uint8_t BRR1;
    volatile uint8_t BRR2;
    volatile uint8_t CR1;
    volatile uint8_t CR2;
    volatile uint8_t CR3;
    volatile uint8_t CR4;
    volatile uint8_t CR5;
    volatile uint8_t GTR;
    volatile uint8_t PSCR;
} uart1_t;

/* Reset values */
enum : uint8_t {
    UART1_SR_RESET_VALUE   = 0xC0,
    UART1_BRR1_RESET_VALUE = 0x00,
    UART1_BRR2_RESET_VALUE = 0x00,
    UART1_CR1_RESET_VALUE  = 0x00,
    UART1_CR2_RESET_VALUE  = 0x00,
    UART1_CR3_RESET_VALUE  = 0x00,
    UART1_CR4_RESET_VALUE  = 0x00,
    UART1_CR5_RESET_VALUE  = 0x00,
    UART1_GTR_RESET_VALUE  = 0x00,
    UART1_PSCR_RESET_VALUE = 0x00,
};

/* SR */
enum : uint8_t {
    UART1_SR_TXE  = BIT(7),
    UART1_SR_TC   = BIT(6),
    UART1_SR_RXNE = BIT(5),
    UART1_SR_IDLE = BIT(4),
    UART1_SR_OR   = BIT(3),
    UART1_SR_NF   = BIT(2),
    UART1_SR_FE   = BIT(1),
    UART1_SR_PE   = BIT(0),
};

/* BRR1 */
enum : uint8_t {
    UART1_BRR1_DIVM = 0xFF,
};

/* BRR2 */
enum : uint8_t {
    UART1_BRR2_DIVM = 0xF0,
    UART1_BRR2_DIVF = 0x0F,
};

/* CR1 */
enum : uint8_t {
    UART1_CR1_R8    = BIT(7),
    UART1_CR1_T8    = BIT(6),
    UART1_CR1_UARTD = BIT(5),
    UART1_CR1_M     = BIT(4),
    UART1_CR1_WAKE  = BIT(3),
    UART1_CR1_PCEN  = BIT(2),
    UART1_CR1_PS    = BIT(1),
    UART1_CR1_PIEN  = BIT(0),
};

/* CR2 */
enum : uint8_t {
    UART1_CR2_TIEN  = BIT(7),
    UART1_CR2_TCIEN = BIT(6),
    UART1_CR2_RIEN  = BIT(5),
    UART1_CR2_ILIEN = BIT(4),
    UART1_CR2_TEN   = BIT(3),
    UART1_CR2_REN   = BIT(2),
    UART1_CR2_RWU   = BIT(1),
    UART1_CR2_SBK   = BIT(0),
};

/* CR3 */
enum : uint8_t {
    UART1_CR3_LINEN = BIT(6),
    UART1_CR3_STOP  = 0x30,
    UART1_CR3_CKEN  = BIT(3),
    UART1_CR3_CPOL  = BIT(2),
    UART1_CR3_CPHA  = BIT(1),
    UART1_CR3_LBCL  = BIT(0),
};

/* Field values */
enum : uint8_t {
    UART1_CR3_STOP_1BIT  = 0x00,
    UART1_CR3_STOP_HALF  = 0x10,
    UART1_CR3_STOP_2BIT  = 0x20,
    UART1_CR3_STOP_1HALF = 0x30,
};

/* CR4 */
enum : uint8_t {
    UART1_CR4_LBDIEN = BIT(6),
    UART1_CR4_LBDL   = BIT(5),
    UART1_CR4_LBDF   = BIT(4),
    UART1_CR4_ADD    = 0x0F,
};

/* CR5 */
enum : uint8_t {
    UART1_CR5_SCEN  = BIT(5),
    UART1_CR5_NACK  = BIT(4),
    UART1_CR5_HDSEL = BIT(3),
    UART1_CR5_IRLP  = BIT(2),
    UART1_CR5_IREN  = BIT(1),
};

#define UART1 ((uart1_t *)0x5230)

#endif /* UART1_H */
