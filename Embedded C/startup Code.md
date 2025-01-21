## Start UP Code
It is overhead code in the hex file.  
It is added in the hex file when we write embedded c or embedded cpp code.  
startup code is added by cross compiler.   

If hex file is generated and if you dump code into microcontroller.It is stored in flash memory the startup memory that the startup code is stored.  

## Startup process of embedded system  
After reset -> startup code -> main function -> other user defined function  

## Startup code role
It initializes the microcontroller syatem before executing the main function  
Startup code initializes  
- memory
- clock
- stack
- vetor table
- execute a code which initailize the global variables.
- select user mode
- give control to main function.


Startup code make the data section to zero '0' thats why global ,extern,static all become zero after reset.  
startup code will set address of each stack and ending of each stack.  
procesor interupted -> vector table -> ISR addresses

if any global variables are declared with initialization then that the startup code would be executed  first that the global variable initialization one initialized has created on global variable initialization code that then the startup code after execution gives control to the global user initialization code then that initailization code would be giving control to the main(this would make the overall execution speed slower)

After reset -> statupcode -> global variable initialization -> main() ->other userdefned function

In case no global variable initailized  
After reset -> startupcode -> main() -> other user defined functions
