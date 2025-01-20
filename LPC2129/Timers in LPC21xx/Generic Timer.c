//Delay.c

#include<LPC21xx.H>
void delay_sec(unsigned int sec)
{
  T0PR=15000000-1;
  T0PC=0;
  T0TC=0;
  T0TCR=1;
  while(T0TC<sec);
  T0TCR=0;
}

void delay_ms(unsigned int ms)
{
  T0PR=15000-1;
  T0PC=0;
  T0TC=0;
  T0TCR=1;
  while(T0TC<ms);
  T0TCR=0;
}

//main.c

#include<LPC21xx.H>
main()
{
delay_sec(1);   //delay second
delay_ms(100);  //delay 100 milliseconds
}

//here in case warnings due to compiling main it doesnot what function hey are calling through they are in delay.c
so you should prototype or declare extern or create header.h

  //header.h

  #include<LPC21xx.h>

  extern void delay_sec(unsiigned int sec);
  extern void delay_ms(unsigned int ms);

  
