# Timer 0 Timer Control Register(T0TCR)

By default timer is in `off condition`

31 - 2  Reserved (for futire expansion)    
1       reset
0       start/stop     

T0TCR 4 byte   

if 0th bit is '1'  -> start    
              '0'  -> stop   

if 1st bit is '1'  -> Reset (reset timer default)  
              '0'  -> no effect  

To communicate with timer SFRs are needed. (Register in processor is general purpose register in RAM at SFR.  

  
```bash
#to set
num=num|1<<pos;
num|=1<<pos;
```
```bash
#to clear
num=num&~(1<<pos);
num&=~(1<<pos);
```
```bash
#To set 0th bit
T0TCR|=(1<<0);
T0TCR|=1;
T0TCR=1;
```
```bash
#To reset
T0TCR|=1<<1;
T0TCR=2;
```

```bash
#to stop timer
T0TCR=0;
```

T0PR(Timer 0 Prescale Register)  
T0PC(Timer 0 Prescale Counter)  
T0TC(Timer 0 timer Counter)  


T0PR holds maximum for countng clock pulses.  
T0PC holds the starting value for counting clock pulses.  


*Initializing T0PR*

```bash
T0PR=15000000-1; //for 1 second delay
T0PC=0;          //Starting value of counting
```

*To check overflow condition(SFR) all timer registers or SFR*

T0TC register is used  
initaillt T0TC=0;  

if  T0PC==(T0PR+1)  -> timer overflow  
then T0Tc=1
     T0TC++&T0PC=0;  

```c
T0PR=15000000-1;
T0PC=0;
T0TC=0;
T0TCR=1; //start
while(T0TC<1); //processor continously checking T0TC while timer cpunts clock pulse.
T0TCR=0; //stop
```

**for LPC21xx header #include<LPC21xx.h>**  
all SFRs are defined  

//#define T0TCR((*volatile unisgned int*)0xE0004004))  
```c
  #define<LPC21xx.h>
  main()
  {
  T0TCR=1;
  }
```
