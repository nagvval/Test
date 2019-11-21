#ifndef _EEPROM_H_H
#define	_EEPROM_H_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

void EEPROM_WriteByte (unsigned char addr, unsigned char dt);
unsigned char EEPROM_ReadByte (unsigned char addr);

#endif	/* _EEPROM_H_H */