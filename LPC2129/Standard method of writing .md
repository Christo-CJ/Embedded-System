## Standard method of writing embedded c code  
 
Application shouldnot communicate directly with the hardware(microcontroller)   
Application means hardware independent code.     
Driver is a hardware dependent code.   
C is a portable language can be used without any hardware but embedded c is partially portable.    
That the register assigned to use ARM written program there would be problem that it doesnot work for other controller that the register names should be charged.  

Agenda:Application must be hardware independent,doesnot have register in that code.  

usage of registers make the code partially portable due to different controllers different register names.  

C code in the user space communicate with driver in kernel space then kernel space to hardware.  
what ever execute in user space is `application.`  
what ever execute in kernel space is `driver.`    
Application and driver combine mbedded c.
mixing c language and registers when changing processor only driver layer need to be changed.  
 
