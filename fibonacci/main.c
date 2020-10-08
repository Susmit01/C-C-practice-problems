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
//memoization
int f[10];
int mfib (int n)
{
    if (n<=1)
    {
        f[n]=n;
        return n;
    }
    else
    {
        if (f[n-2]==-1)
            f[n-2]= mfib(n-2);
        if (f[n-1] == -1)
        {
            f[n-1]= mfib(n-1);
        }
        return f[n-2] + f[n-1];
    }

}
int main()
{
    int i;
    for (i=0; i<10; i++)
        f[i]= -1;
    printf("%d \n", fib(5));
    printf("%d \n", rfib(5));
    printf("%d", mfib(5));
    return 0;
}
