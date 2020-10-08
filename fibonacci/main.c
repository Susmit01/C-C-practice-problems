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
int main()
{
    printf("%d \n", fib(10));
    return 0;
}
