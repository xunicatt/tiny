// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef STATUSLED_H
#define STATUSLED_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef enum : uint8_t {
    STATUS_LED_1 = BIT(0),
    STATUS_LED_2 = BIT(1),
    STATUS_LED_3 = BIT(2),
    STATUS_LED_ALL = STATUS_LED_1 | STATUS_LED_2 | STATUS_LED_3,
} status_led_t;

void status_led_init(void);
void status_led_on(status_led_t led);
void status_led_off(status_led_t led);
void status_led_set_brightness(status_led_t led, uint16_t brightness);
void status_led_toggle(status_led_t led);

#endif /* STATUSLED_H */
