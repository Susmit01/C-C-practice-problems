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
//dosplay
void display (struct array arr)
{
    int i;
    for (i=0; i<arr.len;i++)
        printf("%d ",arr.a[i]);
}
//insert
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
//delete
int delete(struct array *arr, int index)
{
    int i, x=0;
    if (index >0 && index <arr->len)
    {
        x= arr->a[index];
        for (i=index; i<arr->len-1;i++)
            arr->a[i]= arr->a[i+1];
        arr->len--;
        return x;
    }
    return 0;
}
//swap
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y= temp;
}
//linear search
int linearSearch(struct array *arr,int key)
{
    int i;
    for (i=0; i< arr->len; i++)
    {
        if (key== arr->a[i])
            {
                swap(&arr->a[i], &arr->a[i-1]);
                return i;
            }
    }
    return -1;
}
//binary search
//iterative
int binarySearch(struct array arr, int key)
{
    int l, mid, h;
    l=0;
    h= arr.len-1;
    while (l<=h)
    {
        mid= (l+h)/2;
        if (key== arr.a[mid])
            return mid;
        else if (key <arr.a[mid])
            h=mid-1;
        else l= mid+1;
    }
    return -1;
}
int main()
{
    struct array arr={{2, 3, 4,5, 6}, 10, 5};
    //append(&arr, 10);
    //insert(&arr, 4, 4);
    //printf("%d\n", delete(&arr, 2));
    //printf("%d\n", linearSearch(&arr, 4));
    printf("%d\n", binarySearch(arr,5));
    display(arr);
    return 0;
}
