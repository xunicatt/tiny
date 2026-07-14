#ifndef IRQ_H
#define IRQ_H

#include <bsp/bsp.h>

void TIM1_UPD_OVF_IRQHandler(void) __interrupt(11);

#endif /* IRQ_H */
