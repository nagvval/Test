#include "EEPROM.h"

void EEPROM_WriteByte (unsigned char addr, unsigned char dt)
{
    unsigned char status;
    while(WR);
    EEADR = addr;
    EEDATA = dt;
    WREN = 1;
    status = GIE;
    GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    WR = 1;
    GIE = status;
    WREN = 0;
}

unsigned char EEPROM_ReadByte (unsigned char addr)
{
    while(RD||WR);
    EEADR = addr;
    RD = 1;
    return EEDATA;
}