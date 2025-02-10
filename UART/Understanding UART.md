Uart is devided into 3 sections transmitting section , receiving section , Baudrate section.   
 
## Tx Buffer:
In case UART is SFR Tx buffer size is 1 byte it is a part of protocol.  
This standard will never change.  
This is place we put transmitter data.
if we want to send we have data into Tx buffer  As soon as write into Tx buffer will transmitting serially .  
As soon as write into it,transmitting section will immediately serially parallel input and output is serial.   
We have to put 1 byte to transfer  automatically data get transmitted bit by bit.  
As soon as we weite dta into tx buff then flag becomes '0'  
then automaticallytransmitting section creates dtaa frame  
When tx section transmitting the data frame that time flag will be '0'
as soon as stop bit is transmitted the flag became 1.
