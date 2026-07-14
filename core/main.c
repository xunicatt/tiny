// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#include <bsp/bsp.h>
#include <core/irq.h>
#include <core/delay.h>
#include <stdbool.h>

static void sysclock_init(void);

void main(void)
{
    sysclock_init();
    delay_init();

    while (true)
        delay_ms(1000);
}

static void sysclock_init(void)
{
    // enable HSI,LSI and disable HSE
    CLK->ICKR |= CLK_ICKR_HSIEN;
    CLK->ICKR |= CLK_ICKR_LSIEN;
    CLK->ECKR &= ~CLK_ECKR_HSEEN;

    // wait for HSI to be stable
    while (!(CLK->ICKR & CLK_ICKR_HSIRDY))
        nop();

    // switch to highest clock frequency 16Mhz
    CLK->CKDIVR = 0x00;

    // wait for LSI to be stable
    while (!(CLK->ICKR & CLK_ICKR_LSIRDY))
        nop();

    // disable all peripherals
    CLK->PCKENR1 = 0x00;
    CLK->PCKENR2 = 0x00;
}
