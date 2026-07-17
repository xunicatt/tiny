// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#include <bsp/bsp.h>
#include <core/irq.h>
#include <core/delay.h>
#include <stdbool.h>
#include <drivers/statusled.h>

static void sysclock_init(void);

void main(void)
{
    sysclock_init();
    delay_init();
    status_led_init();
    status_led_set_brightness(STATUS_LED_ALL, 100);

    while (true) {
        status_led_toggle(STATUS_LED_ALL);
        delay_ms(1000);
    }
}

static void sysclock_init(void)
{
    // A1. Enable HSI
    CLK->ICKR |= CLK_ICKR_HSIEN;

    // A2. Wait for HSI to be stable
    while ((CLK->ICKR & CLK_ICKR_HSIRDY) == 0) {
        nop();
    }

    // A3. Force the master clock to switch to HSI (0xE1)
    CLK->SWR = 0xE1; 

    // A4. Enable the clock switch
    CLK->SWCR |= CLK_SWCR_SWEN; 

    // A5. Wait until the clock switch is no longer busy
    while ((CLK->SWCR & CLK_SWCR_SWBSY) != 0) {
        nop();
    }

    // A6. Set clock div to 1 to run the Core at 16Mhz
    CLK->CKDIVR = 0x00;

    // B1. Enable LSI
    CLK->ICKR |= CLK_ICKR_LSIEN;

    // B2. wait for LSI to be stable
    while (!(CLK->ICKR & CLK_ICKR_LSIRDY))
        nop();

    // C1. Disable HSE
    CLK->ECKR &= ~CLK_ECKR_HSEEN;

    // D1. Disable all peripherals
    CLK->PCKENR1 = 0x00;
    CLK->PCKENR2 = 0x00;
}
