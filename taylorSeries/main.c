#include <stdio.h>
#include <stdlib.h>
//recursion
double e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if (n==0)
        return 1;
    r = e(x, n-1);
    p=p*x;
    f=f*n;
    return r + p/f;

}
//horner's rule
double eHorner(int x, int n)
{
    static double s;
    if (n==0)
        return s;
    s= 1 + x*s/n;
    return eHorner(x, n-1);
}
//iteratiom
double eloop(int x, int n)
{
    double s=1;
    int i;
    double num=1;
    double den=1;
    for (i=1; i<=n;i++)
    {
        num*= x;
        den*= i;
        s+=num/den;
    }
    return s ;
}
int main()
{
    printf("%lf \n", e(1,10));
    printf("%lf \n", eHorner(1, 10));
    printf("%lf \n", eloop(1, 10));
    return 0;
}
