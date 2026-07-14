#ifndef BSP_H
#define BSP_H

// #include "adc1.h"   /* ADC1 (10-channel, with data buffer and watchdog) */
// #include "awu.h"    /* Auto Wake-up Unit */
// #include "beep.h"   /* Beeper */
// #include "cfg.h"    /* Global Configuration (SWIM disable) */
// #include "clk.h"    /* Clock Controller */
// #include "exti.h"   /* External Interrupt Controller */
// #include "flash.h"  /* Flash and EEPROM */
// #include "gpio.h"   /* General Purpose I/O (GPIOA-D) */
// #include "i2c.h"    /* I2C */
// #include "itc.h"    /* Interrupt Controller */
// #include "iwdg.h"   /* Independent Watchdog */
// #include "opt.h"    /* Option Bytes */
// #include "rst.h"    /* Reset Controller */
// #include "spi.h"    /* SPI */
// #include "tim1.h"   /* TIM1 (16-bit, advanced, complementary PWM) */
// #include "tim2.h"   /* TIM2 (16-bit, general purpose, 3 channels) */
// #include "tim4.h"   /* TIM4 (8-bit, basic) */
// #include "uart1.h"  /* UART1 */
// #include "wwdg.h"   /* Window Watchdog */

#define nop()                __asm__("nop")
#define disableInterrupts()  __asm__("sim")
#define enableInterrupts()   __asm__("rim")

#ifndef __SDCC
  /* workaround for LSPs */
  #define __interrupt(_x)
  #define __at(_x)
#endif

#endif /* BSP_H */
