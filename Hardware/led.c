#include "led.h"

unsigned char n_count, R1, R2, R3;
unsigned int num_gl;

void segchar (unsigned int seg) 
{
  switch (seg)
  {
    case 1:
      PORTB = 0b11111001;
      break;
    case 2:
      PORTB = 0b10100100;
      break;
    case 3:
      PORTB = 0b10110000;
      break;
    case 4:
      PORTB = 0b10011001;
      break;
    case 5:
      PORTB = 0b10010010;
      break;
    case 6:
      PORTB = 0b10000010;
      break;
    case 7:
      PORTB = 0b11111000;
      break;
    case 8:
      PORTB = 0b10000000;
      break; 
    case 9:
      PORTB = 0b10010000;
      break;
    case 0:
      PORTB = 0b11000000;
      break;
  }        
}

void TIM0_Callback(void)
{
  if(n_count==0)
  {
     PORTA = 0b00000000; 
    segchar(R1);
    PORTA = 0b00000100;
  }
  else if(n_count==1)
  {
      PORTA = 0b00000000;
      if (num_gl>=10)
      { 
        
        segchar(R2);
        PORTA = 0b00000010;
      }
      else
      {
          PORTA = 0b00000000;
      }
  }
  else if(n_count==2)
  {
      PORTA = 0b00000000;
      if (num_gl>=100)
      {
//          if(R3==1)PORTB = 0b01111001;
//          if(R3==2)PORTB = 0b00100100;
//          if(R3==3)PORTB = 0b00110000;
//          if(R3==4)PORTB = 0b00011001;
//          if(R3==5)PORTB = 0b00010010;
//          if(R3==6)PORTB = 0b00000010;
//          if(R3==7)PORTB = 0b01111000;
//          if(R3==8)PORTB = 0b00000000;
//          if(R3==9)PORTB = 0b00010000;
//          if(R3==0)PORTB = 0b01000000; 
          segchar(R3);
    PORTA = 0b00000001;
      }
      else
      {
          PORTA = 0b00000000;
      }
  }
  n_count++;
  if (n_count>2) n_count=0;
}

void ledprint(unsigned int number)
{
  num_gl = number;
  R1 = number%10;
  R2 = number%100/10;
  R3 = number%1000/100;
  //R4 = number/1000;
}