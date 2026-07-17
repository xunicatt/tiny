#ifndef TINY_H
#define TINY_H

#include <bsp/bsp.h>

typedef struct {
    gpio_t* port; 
    gpio_pin_t pin;
} gpio_cfg_t;

#define STATUS_LED1 ((gpio_cfg_t){.port = GPIOD, .pin = GPIO_PIN_4})
#define STATUS_LED2 ((gpio_cfg_t){.port = GPIOD, .pin = GPIO_PIN_6})
#define STATUS_LED3 ((gpio_cfg_t){.port = GPIOA, .pin = GPIO_PIN_3})

#endif /* TINY_H */
