# Universal Asynchronous Receiver and Transmitter  

This is a very old protocol.   
Exchange data with computer and external UART devices. 
  
What is protocol?    
Set of standards.   
 
What is UART?  
The UART is on-chip peripheral of microcontroller.UART is serial in parallel out and parallel in serial out peripheral.   
  
*Note*:While transmitting data UART act as parallel in serial out while receiving data uart act as serial in parallel out peripheral.    

Why UART is used in Embedded system?  
UART is designed for Asynchronous Serial Communication.    

`Serial Communication` is a process of sending one bit at a time    
`parallel communication` is a process of sending multiple bits ata time .parallel increases hardware size and increases cost.Now a days all companies are moving towards serial communication.      
 
`Serial communication light weight communication` 

## UART Applications/Projects

- Bluetooth modem based projects
- GPS based projects
- Biometric sensor based projects
- RFID based projects

## Type of serial communication

- Synchronous serial communication
- Asynchronous serial communication

- **Synchronous Serial Communication:**   
In Synchronous serial communication common clock line is used between transmitter and receiver.  
In master and slave only master can generate clock pulses thats why direction of clockline is towards slave.   
Clock line is used for synchronisation.  
Data line is used for exchange data.  
Using data line master can write into slave and read from slave.   
For every bit new clock pulse is required for one clock pulse detected master has given one data bit.  
Multiple datas cannot be send using one clock pulses.  
Master will not generate clock pulse slave will not read dataline.  
When new clock pulse detected only then slave will read the dataline.  
For every clock pulse one data read from dataline.  
`If master has to send 8 bit master has to generate 8 clock pulse`  
Maximum speed slave comes with predefined or default speed.  
If slave speed is 400kbps then master speed must be set at max speed <=400kbps.But not more than 400kbps and not less than 1kbps.  
 
- **Asynchronous serial Communication:**
A common clock line is not used between common receiver and transmitter.
Speed is major parameter used in synchronization.
Transmitter speed and receiver speed must be same in asynchronous serial communication.
Assume asynchronous communication is speed 1Mbps so receive and transmit 1 Mb per second.
Master has to transmit 1 bit in 1 Ms (microsecond)
Device must know when master has started.
Start bit gives to slave that information thats master has started.then after each Ms slave will read dataline.  After sending master will give stop bit these are not data bit this are just information bit.
`Data information = Data frame`
Speed is change time per bit will also change.
Start bitt,stop bit,sped all are used for synchronization.
Master write each bit in a 1Ms gap each Ms each bit written in dataline from each Ms slave will read the dataline so that speed must be same.
