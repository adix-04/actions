#include <stdio.h>
#define ERR_BIT 0
#define RANGE_BIT 1
void check(int nNumber);
/*
 @brief function to validate bits of a number  
 @param function parameters include an integer number   
*/
int main (){
    int nNumber;
    printf("enter number :");
    scanf("%d",&nNumber);
    if(nNumber <= 0){
        return 1;
    } else {
        check(nNumber);
    }
}
void check(int nNumber){
     if(nNumber & (1<<ERR_BIT))        //checking the first bit of the byte
        printf("ERR FLAG \n");
     else if(nNumber & (1<<RANGE_BIT))  //checking the second bit of the byte
        printf("OUT OF range\n");
     else 
        printf("Valid Value");
}