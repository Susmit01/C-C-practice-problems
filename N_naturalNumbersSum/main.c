#include <stdio.h>
#include <stdlib.h>
//recursion
int sum(int n)
{
    if (n==0)
        return 0;
    return sum(n-1)+n;
}
//iteration
int Isum(int n)
{
    int i, sum=0;
    for (i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    return sum;
}
int main()
{
    int r, ir;
    r= sum(5);
    printf("%d \n", r);
    r= Isum(4);
    printf("%d", r);
    return 0;
}
