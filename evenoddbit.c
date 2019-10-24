#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    /*
       It's Known That The Rigth Most Bit In The The Binary Representation ( Least Significant Bit LSB ) 
       Carry 1 or 0 and Its Value Is Multiplied To (2^0 or 1 ) Which Leads To Having a 1 will make it ODD
       As All The Other Bits Left to It are Multiplied to 2,4,8,... Depending On Position
       Value * ( 2 ^ position ) Hence Position Starting From 0 to Length-1 
    */
    
    /*
       &1 Means Make Bitwise Anding With The 0001, Which will Give Us 1 or 0 based on The LSB in The x number
       and The Zeros Anding With Anything Will Result Zeros so The Output Will be One Thing 0001 or 0000
    */
    
    if(x&1) 
        printf("%d is ODD\n", x);
    else
        printf("%d is EVEN\n", x);
    return 0;
}
