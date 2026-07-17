// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#include <bsp/bsp.h>
#include <device/tiny.h>
#include <drivers/statusled.h>

static void tim2_pwm_mode_init(void);

void status_led_init(void)
{
    gpio_init(
        CONFIG_STATUS_LED_1_PORT,
        CONFIG_STATUS_LED_1_PIN,
        GPIO_MODE_OUT_PP_FAST
    );

    gpio_init(
        CONFIG_STATUS_LED_2_PORT,
        CONFIG_STATUS_LED_2_PIN,
        GPIO_MODE_OUT_PP /* doesn't support brightness control */
    );

    gpio_init(
        CONFIG_STATUS_LED_3_PORT,
        CONFIG_STATUS_LED_3_PIN,
        GPIO_MODE_OUT_PP_FAST
    );

    tim2_pwm_mode_init();
}

void status_led_on(status_led_t led)
{
    if (led & STATUS_LED_1) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR3H = 0x03;
        TIM2->CCR3L = 0xE8;
    }

    if (led & STATUS_LED_2) {
        gpio_pin_set(
            CONFIG_STATUS_LED_2_PORT,
            CONFIG_STATUS_LED_2_PIN,
            true
        );
    }

    if (led & STATUS_LED_3) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR1H = 0x03;
        TIM2->CCR1L = 0xE8;
    }
}

void status_led_off(status_led_t led)
{
    if (led & STATUS_LED_1) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR3H = 0x00;
        TIM2->CCR3L = 0x00;
    }

    if (led & STATUS_LED_2) {
        gpio_pin_set(
            CONFIG_STATUS_LED_2_PORT,
            CONFIG_STATUS_LED_2_PIN,
            false
        );
    }

    if (led & STATUS_LED_3) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR1H = 0x00;
        TIM2->CCR1L = 0x00;
    }
}

void status_led_set_brightness(status_led_t led, uint16_t brightness)
{
    if (led & STATUS_LED_1) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR3H = brightness >> 8;
        TIM2->CCR3L = (uint8_t)brightness;
    }

    if (led & STATUS_LED_2) {
        gpio_pin_set(
            CONFIG_STATUS_LED_2_PORT,
            CONFIG_STATUS_LED_2_PIN,
            brightness >= (UINT16_MAX >> 1)
        );
    }

    if (led & STATUS_LED_3) {
        /* Set PWM to 100% Duty Cycle */
        TIM2->CCR1H = brightness >> 8;
        TIM2->CCR1L = (uint8_t)brightness;
    }
}

void status_led_toggle(status_led_t led)
{
    uint16_t brightness;

    if (led & STATUS_LED_1) {
        brightness = (TIM2->CCR3H << 8) | TIM2->CCR3L;
        brightness = 1000 - brightness; /* inverse the brightness */
        TIM2->CCR3H = brightness >> 8;
        TIM2->CCR3L = (uint8_t)brightness;
    }

    if (led & STATUS_LED_2) {
        gpio_pin_toggle(
            CONFIG_STATUS_LED_2_PORT,
            CONFIG_STATUS_LED_2_PIN
        );
    }

    if (led & STATUS_LED_3) {
        brightness = (TIM2->CCR1H << 8) | TIM2->CCR1L;
        brightness = 1000 - brightness; /* inverse the brightness */
        TIM2->CCR1H = brightness >> 8;
        TIM2->CCR1L = (uint8_t)brightness;
    }
}

static void tim2_pwm_mode_init(void)
{
    /* A1. Enable Timer 2 peripheral */
    CLK->PCKENR1 |= CLK_PCKENR1_TIM2;

    /* B1. Disable TIM2 */
    TIM2->CR1 &= ~TIM2_CR1_CEN;

    /* B2. 16Mhz / 16 -> 1 Mhz */
    TIM2->PSCR = 0x04;

    /* B3. Auto reload at: 999 (0 - 999 => 1000 steps) */
    TIM2->ARRH = 0x03;
    TIM2->ARRL = 0xE7;

    /* B4. Set PWM to 0% (LED3) */
    TIM2->CCR1H = 0x00;
    TIM2->CCR1L = 0x00;

    /* B5: Set PWM to 0% (LED1) */
    TIM2->CCR3H = 0x00;
    TIM2->CCR3L = 0x00;

    /* B5. Captuer/Compare Mode Register
     * - PWM Mode[6:4] (6 (0b110) << 4)
     * - Output Comare Preload Enable[3] (1 << 3)
     * - Output mode[1:0] (0)
     */
    TIM2->CCMR1 |= 0x68;

    /* B6. Caputer/Compare 1 Output Enable */
    TIM2->CCER1 |= TIM2_CCER1_CC1E;
    /* B7. Caputer/Compare 1 Output active high */
    TIM2->CCER1 &= ~TIM2_CCER1_CC1P;

    /* B7. Captuer/Compare Mode Register
     * - PWM Mode[6:4] ((0b110) << 4) [0x60]
     * - Output Comare Preload Enable[3] (1 << 3) [0x08]
     * - Output mode[1:0] (0) [0x00]
     */
    TIM2->CCMR3 |= 0x68;

    /* B8. Caputer/Compare 3 Output Enable */
    TIM2->CCER2 |= TIM2_CCER2_CC3E;
    /* B7. Caputer/Compare 3 Output active high */
    TIM2->CCER2 &= ~TIM2_CCER2_CC3P;

    /* B9. Enable Timer 2 */
    TIM2->CR1 |= TIM2_CR1_CEN;
}
