#include <stdio.h>
#include "headers.h"
#define ERR_BIT 0
#define RANGE_BIT 1
void check(int nNumber);
/** 
 *@brief function to validate bits of a number  
 *@param function parameters include an integer number   
*/
int sum(int a, int b){
    if(a < 0 || b < 0){
        return 0;
    }
    return a+b;
}
int diff(int a , int b)
{
    return a-b ;
}
void check(int nNumber){
     if(nNumber & (1<<ERR_BIT))        //checking the first bit of the byte
        printf("ERR FLAG \n");
     else if(nNumber & (1<<RANGE_BIT))  //checking the second bit of the byte
        printf("OUT OF range\n");
     else 
        printf("Valid Value");
}