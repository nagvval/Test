#ifndef LED_H
#define	LED_H

#include <xc.h>
#include "main.h"

void TIM0_Callback(void);
void ledprint(unsigned int number);
void segchar (unsigned int seg);


unsigned char n_count, R1, R2, R3;

#endif	/* LED_H */