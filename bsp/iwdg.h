#ifndef IWDG_H
#define IWDG_H

#include <stdint.h>

typedef struct {
    volatile uint8_t KR;
    volatile uint8_t PR;
    volatile uint8_t RLR;
} iwdg_t;

/* Reset values */
enum : uint8_t {
    IWDG_PR_RESET_VALUE  = 0x00,
    IWDG_RLR_RESET_VALUE = 0xFF,
};

/* Keys */
enum : uint8_t {
    IWDG_KR_KEY_ENABLE  = 0xCC,
    IWDG_KR_KEY_REFRESH = 0xAA,
    IWDG_KR_KEY_ACCESS  = 0x55,
};

/* Field values */
enum : uint8_t {
    IWDG_PR_DIV4   = 0x00,
    IWDG_PR_DIV8   = 0x01,
    IWDG_PR_DIV16  = 0x02,
    IWDG_PR_DIV32  = 0x03,
    IWDG_PR_DIV64  = 0x04,
    IWDG_PR_DIV128 = 0x05,
    IWDG_PR_DIV256 = 0x06,
};

#define IWDG ((iwdg_t *)0x50E0)

#endif /* IWDG_H */
