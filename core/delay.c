// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#include <bsp/bsp.h>
#include <core/delay.h>

static uint16_t ms;

void delay_init(void)
{
    // A1. Enable timer 1 clock
    CLK->PCKENR1 |= CLK_PCKENR1_TIM1;

    // B1. Disable timer 1
    TIM1->CR1 &= ~TIM1_CR1_CEN;

    // B2. Set prescaler to 16 (15 + 1) for 1 Mhz
    TIM1->PSCRH = 0x00;
    TIM1->PSCRL = 0x0F;

    // B3. Set auto reload to 999 (0 - 999 = 1000 steps)
    TIM1->ARRH = 0x03;
    TIM1->ARRL = 0xE7;

    // B4. Reset counter
    TIM1->CNTRH = 0;
    TIM1->CNTRL = 0;

    // B5. Enable auto reload
    TIM1->CR1 |= TIM1_CR1_ARPE;
    // B6. Enable interrups for ARR update
    TIM1->IER |= TIM1_IER_UIE;

    // B7. Enable timer 1
    TIM1->CR1 |= TIM1_CR1_CEN;

    ms = 0;
}

void delay_us(uint16_t us)
{
    const uint16_t start = micros();
    while ((micros() - start) < us) {
        nop();
    }
}

void delay_ms(uint16_t ms)
{
    const uint16_t start = millis();
    while ((millis() - start) < ms) {
        nop();
    }
}

uint16_t micros(void)
{
    uint16_t cnt;

    disableInterrupts();
    cnt = (TIM1->CNTRH << 8) | TIM1->CNTRL;
    enableInterrupts();

    return cnt;
}

uint16_t millis(void)
{
    uint16_t _ms;

    disableInterrupts();
    _ms = ms;
    enableInterrupts();

    return _ms;
}

void TIM1_UPD_OVF_IRQHandler(void) __interrupt(11)
{
    ms++;
    TIM1->SR1 &= ~TIM1_SR1_UIF;
}
