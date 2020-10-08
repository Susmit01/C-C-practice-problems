#include <stdio.h>
#include <stdlib.h>
//nth term using itteration
int fib(int n)
{
    int first=0, second=1, sum=0, i;
    if (n<=1)
        return n;
    for (i=2; i<=n; i++)
    {
        sum= first+ second;
        first= second;
        second= sum;
    }
    return sum;
}
//recursion
int rfib(int n){
if (n<=1){
    return n;
}
return rfib(n-1)+ rfib(n-2);
}
int main()
{
    printf("%d \n", fib(5));
    printf("%d \n", rfib(5));
    return 0;
}
