#ifndef BEEP_H
#define BEEP_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t CSR;
} beep_t;

/* Reset values */
enum : uint8_t {
    BEEP_CSR_RESET_VALUE = 0x1F,
};

/* CSR */
enum : uint8_t {
    BEEP_CSR_BEEPSEL = 0xC0,
    BEEP_CSR_BEEPEN  = BIT(5),
    BEEP_CSR_BEEPDIV = 0x1F,
};

#define BEEP ((beep_t *)0x50F3)

#endif /* BEEP_H */
