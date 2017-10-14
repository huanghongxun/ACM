#include<stdio.h>  
int main(void) 
{ 
    int un[1505]={0}; 
    int m2=0,m3=0,m5=0,i,t; 
    un[0]=1; 
    for(i=1;i<1500;i++) 
    { 
        if(2*un[m2]>3*un[m3]) 
            t=un[m3]*3; 
        else 
            t=un[m2]*2; 
        if(t>un[m5]*5) 
            t=un[m5]*5; 
 
        if(t == 2*un[m2]) m2++; 
        if(t == 3*un[m3]) m3++; 
        if(t == 5*un[m5]) m5++; 
 
        un[i]=t; 
    } 
    printf("The 1500'th ugly number is %d.\n",un[1499]); 
    return 0; 
} 