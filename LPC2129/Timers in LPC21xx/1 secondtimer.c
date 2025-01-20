#include<LPC21xx.H>
main()
{
T0PR=15000000-1;  //for 1 second delay
T0PC=0;
T0TC=0;
T0TCR=1;
while(T0TC<1);  //waiting for timer 0 to overflow
T0TCR=0; //stop timer 0
}
