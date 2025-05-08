/******************************************************************************
 
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <stdio.h>
 
int main()
{
   double x;
   
   scanf("%lf", &x);
   printf("%.lf ", x);
    while(x>1)
    {
        long long j=x;
            
        if(j%2==0) {
       
        x=x/2;
           printf("%.lf ", x);
        }
            else 
        {
                x=(x*3) + 1;
                printf("%.lf ", x);
            
        }
    }
 
    return 0;
}
