# GPIO Programming General Purpose Input Output Programming 

There are 46 gpio pins in LPC2129  

In any gpio pins only two operations possible 
- IO write operation
- IO Read operation

In ARM one pin has more than one functionality.  
When read IO pin get value 1/0.
When `0` it will be `off`  write `1` it will be `on` using SFRs we can do the IO Read/Write.Only this way is there to communication with the hardware.  

## GPIO SFRs
- IODIR (to set dir of IO pin)
- IOSET (to set IO pin)
- IOCLR (to CLEAR IO pin)
- IOPIN (to READ IO pin)

## IODIR GPIO port Direction control Register

This register is used to set direction of any IO pin.The direction of IO pin can be `input or output` direction.  
When we want to write `IO write` the direction must be `output` direction.  
When we want to Read `IO Read` the direction must be `input` direction.  
At same time cannot use both functionality.   
It depends upon external device connected.  
example LED needs output from microcontroller so IO write
        switches need input to microcontroller IO Read  

Output direction devices  LED,LCD,Motor,RELAY,Dot matrix  
Input direction devices   Switch,digital servos  

IODIR is 32 bits  
- IODIR0 /IO0DIR (port 0)
- IODIR1 /IO1DIR (port 1)

## IODIR 0
size of register is 4 byte (32bits)  
reset value of register is 0.  
0 to 31  p0.0  to p0.31  

bit number = pin number 
using 0 th bit -> setting of bit
if we set 0th bit  -> 1 -> po.0 -> output direction  
                      0 -> po.0 -> Input direction  

Reset value is 0 thats why upon reset all GPIO pins are Input direction pins.  
if you want to set any pin output direction 
```bash 
IODIR0 = 1;
```
when assign '1' to register 0 th bit become 1 and it will be in output direction.  
p0.0 - p0.7 output direction then we have to set first 8 bits of register. 
IODIR = 255;  
IODIR = 0xFF;   

set 3rd pin as 1  
IODIR0 = 8;  
IODIR0 = (1<<3);

## GPIO Port Output Set Register  
This register is used to SET IOPin  
By writing `1` to this register we can `set` IO pin and writting `0` has `no effect`  
IOSET is 32 bits.  
- IOSET0/IO0SET (port0)  
- IOSET1/IO1SET (port1)

IOSET0
Design is a same as IODIR0.  
- Oth bit
    - 1 -> set
    - 0 -> no effect

IOSET0 = 1;  This wil set po.0
IOSET0 = 2;  This will set po.1  
IOSET0 = 0xE; set po.0 - po.3
IOSET0 = (1<<5); set po.5 
Till clearing a possition the values added previously will not be changing.  

## GPIO Port Output Clear register. 
This register is used to clear IO pin . Writing 1 to this register will clear IO pin writing `0` has `no effect`  

IOCLR is 32 bits  
IOCLR0/IO0CLR (port 0)  
IOCLR1/IO1CLR (port 1)  

IOSET0=1;
IOCLR0=1;   clear that 1 position  

IOSET0=4;
IOCLR0=4;  clear po.3  

if we write 1 to IOCLR0 
then register is clear at that position then po.1 is clear.likewise the set operations.    

When we write 1 in clear first IOSET0 becomes 0 first then that 0 to po.0 (0)  
defult IOSET0 is 0 when set '1' . 1 then pass to po.0   
IOSET  -> 0xE0028004  (address of IOSET RAM address)  
Every bit of IOSET is internally mapped to IOPINS 0 -> po.0 ,1 -> p0.1 ,2 -> po.2 ....   
This concept is called `memory mapped IO Pins`

```c
#include<LPC21xx.h>
main()
{
IODIR0=0x1;
IOSET0=0x1;
IOCLR0=0x1;
}
```
