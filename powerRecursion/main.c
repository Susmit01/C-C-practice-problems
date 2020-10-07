#include <stdio.h>
#include <stdlib.h>
//recursion
int power(int m, int n)
{
    if (n==0)
        return 1;
    return power(m, n-1)*m;
}
//more effective
int ipower(int m, int n)
{
    if (n==0)
        return 1;
    if (n%2==0)
        return ipower(m*m, n/2);
    return m*ipower(m*m, (n-1)/2);
}
int main()
{
    int r;
    r= power (2,4);
    printf("%d", r);
    r= ipower(2,4);
    printf("\n%d",r);
    return 0;
}
