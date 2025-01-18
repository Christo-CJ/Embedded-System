 Main purpose of using timer is delay generation
## Two methods of using timer is delay generation
- software method(using loop)
- Hardware method(using timer)

 ## what is delay?
 Assume we have 4 line of code the job of processor is to execute these 4 lines of code
 so the 4 lines are like this   
 1. _____  
 2. _____ 1sec
 3. _____ 500 ms  
 4. _____ 1 sec

Busying the processor is called as Delay  

ie, after executing 1st line we need to execute the 2nd line after 1 sec .After executing 2nd line of code we need to execute 3rd line after 500ms.  
Executing the loop means busying the processor . if we know the time for loop means that we know how many time we need to rotate the loop.  
if we dont know how many times the rotation of loop then we get any random delay only not exeact delay.  
we will go by hardware method,ie using timer.

## What is timer?

The timer is on chip peripheral of microcontroller which counts the internal clock pulses in our case clock pulses is CCLK.   
Due to vibration XTAL will produce oscillation ,Then the oscillation is given to clock generator. 
Output of clock pulses is given to timer.  
Processor will use them clock pulses to execute instructions or execute code.  
Timer also getting the same clock pulses, But Timer will count the clock pulses. Timer cannot execute instruction only processor can execute the instruction.

Assume timer is getting 1000 clock pulses in 1 second.Insisde timer we get flag.Initial flag value is 0.Timer will count the clock pulses.As soon as timer counts 1000;flag value is 1.Processor is chcekcing the flag value.If the processor monitors the flag value as 1 sec then it count execute next.  
If we want 2000 clock pulses the write the code at 2000 clock pulses timer counts;makes the flag value as 1.  
If we tell the processor to monitor the flag; then the processor is busying.  
This flag is called `overflow flag`.  

As long as flag is 0 execute the 1st line only.  when condition fails (flag ==1) will execute the 2nd line.  

Timer is counting and it has to score the clock pulses cout to register.  
Timer store the count into Register  
ie, 3rd clock pulses is counted;value 3 is stored in Register  
    4th clock pulses is counted;value 4 is stored in Register.

 In every microcontroller the timer concept is same,If the size of register is 16 bit then that timer is called as 16 bit timer. If the register where the count is stored is 32 bit,then that timer i called as 32 bit timer.  
 16bit -> Register can store 2^16 -> 65535  -> these many timer it can count.  
 As soon as we get 65536 -> the register value is 0. This condition is called `timer overflow condition`.
  
When 65535 at this time when the counter counts one more time then register value become 0 ,timer overflow.

In *LPC21xx* ,overflow condition is different,but in every microcontrollre timer theory remains same.  
Processor executing the code only and timer is counting.  
Timer and processor will run parallely /simultaneously.  
Timer is not depend upon processor.   
Timer will store clock pulses sets flag.  
Processor is only monitoring the flag.  


# Features of LPC21XX Timer#

- two 32 bit timer (timer 0 and timer 1)
- Timer works into two differen modes
  - Match mode
  - Capture mode(allocate counter mode)
- Timer is connected on APB bus and timer input frequency depends on PCLK.

Any peripherals which arae connected on APB bus will get 15 MHz  
Input frequency of timer 0 and timer 1 is 15MHz.  

15 MHz means timer will get 15x10^6 clock pulses in 1 sec(15000000).  
If we tell the timer to start from 0 and more level as 15000000(max limit of counting clock).  
In every clock pulse; the register will count at 15MHz .Register will not overflow at register value of 1.Register will overflow maximum limit in register shold be <=15000000(15MHz).  

When counting 1 clock pulse; timer will overflow  

*start value "0" put in one register ,memory value or limit in one register,overflow in one register , to start and stop time one register ,**total 4 registers***  

1sec=15x10^6 pulse/sec  

# LPC2129 Timer register#  
Timer 0 -> T0TCR,T0TR,T0PC,T0TC  
Timer 1 -> T1TCR,T1TR,T1PC,T1TC  

# Memory Allocation#

if '1' is written at that address then peripheraal can use the data (here timer0).


