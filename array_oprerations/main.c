#include <stdio.h>
#include <stdlib.h>

struct array
{
    int a[10];
    int size;
    int len;
};
void append( struct array *arr, int x)
{
    if (arr -> len < arr-> size)
        arr->a[ arr->len++] = x;

}
void display (struct array arr)
{
    int i;
    for (i=0; i<arr.len;i++)
        printf(" %d ",arr.a[i]);
}
void insert (struct array *arr, int index, int x)
{
    int i;
    if (index>=0 && index<= arr->len)
    {
        for( i=arr->len; i>index;i--)
            arr->a[i]=arr->a[i-1];
        arr->a[index]=x;
        arr->len++;
    }
}
int main()
{
    struct array arr={{2, 3, 4,5, 6}, 10, 5};
    //append(&arr, 10);
    insert(&arr, 5, 4);
    display(arr);
    return 0;
}
