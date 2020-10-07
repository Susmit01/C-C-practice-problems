#include <stdio.h>
#include <stdlib.h>
//recursion
int power(int m, int n)
{
    if (n==0)
    {
        return 1;
    }
    return power(m, n-1)*m;
}
int main()
{
    int r;
    r= power (2,4);
    printf("%d", r);
    return 0;
}
