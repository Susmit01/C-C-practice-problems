#include <stdio.h>
#include <stdlib.h> //for malloc

//static-a[]
//dynamic- p[]
int main()
{
    int a[5]={2, 4, 6, 8 ,10};
    int *p, i;
    p= malloc (5* sizeof(int)); //allocate memory in heap
    p[0]= 1;
    p[1]= 3;
    p[2]= 5;
    p[3]= 7;
    p[4]= 9;
    for(i=0; i<5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i=0; i<5; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}
