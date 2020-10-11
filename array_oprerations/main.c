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

int main()
{
    struct array arr={{2, 3, 4,5, 6}, 10, 5};
    append(&arr, 10);
    display(arr);
    return 0;
}
