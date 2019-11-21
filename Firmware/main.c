#include "main.h"


void __interrupt() isr()
{
  if(TMR0IE&&TMR0IF)
  {
    TIM0_Callback();
    T0IF=0;
  } 
}

void SetPWM (unsigned char nm, unsigned int dc)
{
    switch(nm)
  {
    case 1:
        CCPR1L = dc>>2;
        CCP1CON &= 0xCF;
        CCP1CON |= 0x30&(dc<<4);
      break;
//    case 2:
//        CCPR2L = dc>>2;
//        CCP2CON &= 0xCF;
//        CCP2CON |= 0x30&(dc<<4);
//      break;
  }

}

void main(void) {
    
    unsigned char fl=0;
    unsigned char i = EEPROM_ReadByte(0x00);
    
    TRISA = 0x00; PORTA = 0x00;    
    TRISB = 0x00;   PORTB = 0xFF;  
    TRISC = 0b11000000; PORTC = 0b00000000;  
    OPTION_REG=0b00000010;
    GIE=1;
    PEIE=1;
    T0IE=1;
    TMR0=0;
    
    CCP1CON = 0x0F;
    //CCP2CON = 0x0F;
    
    PR2 = 0xFF; //TIMER2 Period 255
    T2CKPS1 = 1; //TIMER2 prescaler 1:16
    T2CKPS0 = 0;
    TMR2ON = 1; //TIMER2 ON
    
    //ledprint(123);
    while(1)
    {      
        if(ButtonUp())
        {
            PORTCbits.RC5=1;
            __delay_ms(100);
            PORTCbits.RC5=0;
            i++;
            //if (i<45) i=45;
            //if (i>200) i=200;
            if (i<1) i=1;
            if (i>100) i=100;
            ledprint(i);
            while(ButtonUp())
            {
                i++;
//                if (i<45) i=45;
//                if (i>200) i=200;
                if (i<1) i=1;
                if (i>100) i=100;
                ledprint(i);
            }
            //SetPWM(1, 0);
            //__delay_ms(500);
            EEPROM_WriteByte(0x00,i);
        }
        
        if(ButtonDown())
        {
            PORTCbits.RC5=1;
            __delay_ms(100);
            PORTCbits.RC5=0;
                i--;
//                if (i<45) i=45;
//                if (i>200) i=200;
                if (i<1) i=1;
                if (i>100) i=100;                
                ledprint(i);
            while(ButtonDown())
            {
                
                i--;
//                if (i<45) i=45;
//                if (i>200) i=200;
                if (i<1) i=1;
                if (i>100) i=100;                
                ledprint(i);
            }
            EEPROM_WriteByte(0x00,i);
        }
        
        ledprint(i);
        
        //SetPWM(1, 1023-((i-42)/0.4));
        SetPWM(1, 1023-((i*200)/100));
        //SetPWM(1, 1023);
        //SetPWM(1, 1023-(i-36));
        //SetPWM(2, 1023-i);
//        if(fl==0) i++;
//        else i--;
//        if(i>1023) fl=1;
//        else if(i<=0) fl=0;
        //__delay_us(1000);
    }
    return;
}