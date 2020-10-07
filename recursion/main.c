#include <stdio.h>
#include <stdlib.h>
//factorial
int fact (int n)
{
    if (n==0)
        return 1;
    return fact(n-1)*n;
}
//iteration
int ifact(int n)
{
    int i, f=1;
    for (i=1; i<=n; i++){
        f=f*i;
    }
    return f;
}
int main()
{
    int r;
    r= fact(5);
    printf("%d",r);
    r= ifact(4);
    printf("\n%d", r);
    return 0;
}
