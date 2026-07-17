// SPDX-License-Identifier: GPL-2.0
// Author: xunicatt
// Project: tiny 
// Copyright (c) 2026 xunicatt <contact.aniket.biswas@gmail.com>

#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>
#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t ODR;
    volatile uint8_t IDR;
    volatile uint8_t DDR;
    volatile uint8_t CR1;
    volatile uint8_t CR2;
} gpio_t;

/* Reset values */
enum : uint8_t {
    GPIO_ODR_RESET_VALUE = 0x00,
    GPIO_DDR_RESET_VALUE = 0x00,
    GPIO_CR1_RESET_VALUE = 0x00,
    GPIO_CR2_RESET_VALUE = 0x00,
};

/* Ports */
#define GPIOA ((gpio_t *)0x5000)
#define GPIOB ((gpio_t *)0x5005)
#define GPIOC ((gpio_t *)0x500A)
#define GPIOD ((gpio_t *)0x500F)

/* Pins */
enum : uint8_t {
    GPIO_PIN_0 = BIT(0),
    GPIO_PIN_1 = BIT(1),
    GPIO_PIN_2 = BIT(2),
    GPIO_PIN_3 = BIT(3),
    GPIO_PIN_4 = BIT(4),
    GPIO_PIN_5 = BIT(5),
    GPIO_PIN_6 = BIT(6),
    GPIO_PIN_7 = BIT(7),
};

/* Field values */
typedef enum : uint8_t {
    GPIO_MODE_IN_FLT      = 0x0,
    GPIO_MODE_IN_FLT_IT   = 0x1,
    GPIO_MODE_IN_PU       = 0x2,
    GPIO_MODE_IN_PU_IT    = 0x3,
    GPIO_MODE_OUT_OD      = 0x4,
    GPIO_MODE_OUT_OD_FAST = 0x5,
    GPIO_MODE_OUT_PP      = 0x6,
    GPIO_MODE_OUT_PP_FAST = 0x7,
} gpio_mode_t;

static inline void gpio_init(gpio_t *port, uint8_t pin, gpio_mode_t mode)
{
    if (mode & BIT(2))
        port->DDR |= pin;
    else
        port->DDR &= ~pin;

    if (mode & BIT(1))
        port->CR1 |= pin;
    else
        port->CR1 &= ~pin;

    if (mode & BIT(0))
        port->CR2 |= pin;
    else
        port->CR2 &= ~pin;
}

static inline void gpio_deinit(gpio_t *port, uint8_t pin)
{
    port->DDR &= ~pin;
    port->CR1 &= ~pin;
    port->CR2 &= ~pin;
}

static inline void gpio_pin_set(gpio_t *port, uint8_t pin, bool value)
{
    if (value)
        port->ODR |= pin;
    else
        port->ODR &= ~pin;
}

static inline void gpio_pin_toggle(gpio_t *port, uint8_t pin)
{
    port->ODR ^= pin;
}

static inline bool gpio_pin_get(gpio_t *port, uint8_t pin)
{
    return (port->IDR & pin) != 0;
}

#endif /* GPIO_H */
