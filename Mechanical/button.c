#include "button.h"

unsigned char ButtonUp (void)
{
  unsigned char result=0;
  unsigned int butcount=0;

  while(!RC7)
  {
    if(butcount < 10000)
    {
      butcount++;
    }
    else
    {
      result = 1;
      break;
    }
  }
  return result;
}

unsigned char ButtonDown(void)
{
  unsigned char result=0;
  unsigned int butcount=0;

  while(!RC6)
  {
    if(butcount < 10000)
    {
      butcount++;
    }
    else
    {
      result = 1;
      break;
    }
  }
  return result;
}

//unsigned char ButtonStart(void)
//{
//  unsigned char result=0;
//  unsigned int butcount=0;
//
//  while(!RC5)
//  {
//    if(butcount < 10000)
//    {
//      butcount++;
//    }
//    else
//    {
//      result = 1;
//      break;
//    }
//  }
//  return result;
//}
//
//unsigned char ButtonStop(void)
//{
//  unsigned char result=0;
//  unsigned int butcount=0;
//
//  while(!RC4)
//  {
//    if(butcount < 10000)
//    {
//      butcount++;
//    }
//    else
//    {
//      result = 1;
//      break;
//    }
//  }
//  return result;
//}