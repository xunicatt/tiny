#ifndef OPT_H
#define OPT_H

#include <stdint.h>

typedef struct {
    volatile uint8_t OPT0;
    volatile uint8_t OPT1;
    volatile uint8_t NOPT1;
    volatile uint8_t OPT2;
    volatile uint8_t NOPT2;
    volatile uint8_t OPT3;
    volatile uint8_t NOPT3;
    volatile uint8_t OPT4;
    volatile uint8_t NOPT4;
    volatile uint8_t OPT5;
    volatile uint8_t NOPT5;
    uint8_t reserved_1;
    uint8_t reserved_2;
    volatile uint8_t OPT7;
    volatile uint8_t NOPT7;
} opt_t;

#define OPT ((opt_t *)0x4800)

#endif /* OPT_H */
