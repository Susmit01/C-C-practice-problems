#include <stdio.h>
#include <stdlib.h>
//using factorial
int fact(int n)
{
    if (n<=1)
        return n;
    return fact(n-1)*n;
}
int ncr(int n, int r)
{
    int num, den;
    num= fact(n);
    den= fact(r)* fact(n-r);
    return (num/den);
}

int main()
{
    printf("%d \n", ncr(5,1));
    return 0;
}
