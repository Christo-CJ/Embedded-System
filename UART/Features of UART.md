- UART was designed by an American Engineer named `Gordan Bell`
- Two wired communciation protocol
    - Txd(transmit data)
    - Rxd(Receive data)
- UART is Fullduplex,Asynchronous Serial Communication Protocol
- Short and long distance communcation is possible we can set baudrate accordingly
- UART is designed for peer to peer communication.
- Maximum Baudrate of UART is upto 1Mbps and min 110bps
- Data transfer direction is from LSB to MSB always
- UART is designed to send only 1 byte in 1 dataframe
  Note:min 5 bits maximum 8 bits data can be send.
- Data frame is called data packet
- Parity checking is error detection method used in UART protocol.

Even parity:  
In data the number of ones are even then parity flag is transmitted as '1'  
  
Odd parity:  
In data number of ones are odd then parity flag is transmitted as '0'  

Each bit by bit tranmission due to some noise assume that first bit corrupted and remaining not corrupted receive data number of ones would be odd and parity would be even then error detected.  
If two bits are corrupted receiver cannot understand where is there is error or not.  
