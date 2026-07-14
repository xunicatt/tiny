#ifndef CFG_H
#define CFG_H

#include <stdint.h>

#define BIT(x) (1 << x)

typedef struct {
    volatile uint8_t GCR;
} cfg_t;

/* Reset values */
enum : uint8_t {
    CFG_GCR_RESET_VALUE = 0x00,
};

/* GCR */
enum : uint8_t {
    CFG_GCR_SWD = BIT(0),
    CFG_GCR_AL  = BIT(1),
};

#define CFG ((cfg_t *)0x7F60)

#endif /* CFG_H */
