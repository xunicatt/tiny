// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef DELAY1_H
#define DELAY1_H

#include <stdint.h>

void delay_init(void);
void delay_us(uint16_t us);
void delay_ms(uint16_t ms);

uint16_t micros(void);
uint16_t millis(void);

#endif /* DELAY1_H */
