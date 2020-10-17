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
//recursion
int rBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if (l<=h)
    {
        mid=(l+h)/2;
        if (key==a[mid])
            return mid;
        else if (key < a[mid])
            return rBinarySearch(a, l, mid-1, key);
        else return rBinarySearch(a, mid+1, h, key);
    }
    return -1;
}
//get function
int get(struct array arr, int index)
{
    if (index >=0 && index <arr.len)
    {
        return arr.a[index];
    }
    return -1;
}
void set(struct array *arr, int index, int val)
{
    if (index >=0 && index <arr->len)
    {
        arr->a[index]=val;
    }
}
int max(struct array arr)
{
    int max=arr.a[0];
    int i=0;
    while (i<arr.len)
    {
        if (arr.a[i]>max)
           {
                max = arr.a[i];
           }
        i++;
    }
    return max;
}
int sum(struct array arr)
{
    int sum=0;
    int i=0;
    for(;i<arr.len;i++)
    {
        sum+=arr.a[i];
    }
    return sum;
}
int average(struct array arr)
{
    int s;
    s=sum(arr);
    return s/arr.len;
}
//reverse
void reverse (struct array *arr)
{
    //aux array
    int *b;
    int i, j;
    b = (int *)malloc(arr->len*sizeof(int));
    for (i=arr->len-1, j=0;i>=0; i--, j++)
    {
        b[j]= arr->a[i];
    }
    for (i=0; i< arr->len;i++)
    {
        arr->a[i]=b[i];
    }
}
//reverse using swap function
void reverse2(struct array *arr)
{
    int i,j;
    for(i=0, j=arr->len-1; i<j;i++,j--)
    {
        swap(&arr->a[i], &arr->a[j]);
    }
    for (i=0; i< arr->len; i++)
        printf("%d ", arr->a[i]);
}
//inserting elements in sorted array
void insertsort(struct array *arr, int x)
{
    int i= arr->len-1;
    if(arr->len == arr ->size)
    return;
    while (i>=0 && arr->a[i]>x)
    {
        arr->a[i+1]= arr->a[i];
        i--;
    }
    arr->a[i+1]=x;
    arr->len++;
}
//checck if sorted
int isSorted (struct array arr)
{
    int i;
    for (i=0; i <arr.len-1; i++)
    {
        if (arr.a[i]>arr.a[i+1])
            return 0;
    }
    return 1;
}
//rearrange positive and negative numbers
void rearrange( struct array *arr)
{
    int i, j;
    i=0;
    j= arr->len-1;
    while (i<j)
    {
        while(arr->a[i]<0)
            i++;
        while(arr->a[i]>=0)
            j--;
        if (i<j)
            swap(&arr->a[i], &arr->a[j]);
    }
}
//union and merge same
struct array* Union (struct array *arr1, struct array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct array *arr3= (struct array *)malloc (sizeof(struct array));
    while (i<arr1->len && j<arr2->len)
    {
       if(arr1->a[i]< arr2 ->a[j])
            arr3->a[k++]= arr1->a[i++];
       else if (arr2->a[j]<arr1->a[i])
                arr3->a[k++]= arr2->a[j++];
            else
               {
                    arr3->a[k++]=arr1->a[i++];
                    j++;

               }
    }
    for(;i<arr1->len;i++)
        arr3->a[k++]= arr1->a[i];
     for(;j<arr2->len;j++)
        arr3->a[k++]= arr2->a[j];
    arr3->len= k;
    arr3->size=10;
    return arr3;
}
//intersection
struct array* intersection(struct array *arr1, struct array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct array *arr3= (struct array *)malloc (sizeof(struct array));
    while (i<arr1->len && j<arr2->len)
    {
       if(arr1->a[i] < arr2 ->a[j])
            i++;
       else if (arr2->a[j] < arr1->a[i])
                j++;
            else if(arr1->a[i]==arr2->a[j])
               {
                    arr3->a[k++]=arr1->a[i++];
                    j++;
               }
    }

    arr3->len= k;
    arr3->size=10;
    return arr3;
}
//difference
struct array* difference (struct array *arr1, struct array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct array *arr3= (struct array *)malloc (sizeof(struct array));
    while (i<arr1->len && j<arr2->len)
    {
       if(arr1->a[i]< arr2 ->a[j])
            arr3->a[k++]= arr1->a[i++];
       else if (arr2->a[j]<arr1->a[i])
                j++;
            else
               {
                    i++;
                    j++;
               }
    }
    for(;i<arr1->len;i++)
        arr3->a[k++]= arr1->a[i];

    arr3->len= k;
    arr3->size=10;
    return arr3;
}

int main()
{
    struct array arr1;
    int ch, x, index;
    printf("Enter the size of the array \n");
    scanf("%d", &arr1.size);
    arr1.a=(int *)malloc(arr1.size*sizeof(int));

    printf("Menu \n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Search\n");
    printf("4. Sum \n");
    printf("5. Reverse \n");
    printf("6. exit \n");
    printf("Enter your choice number \n");
    scanf("%d", &ch);
    do{
    switch(ch)
    {
    case 1:
        printf("Enter element and choice \n");
        scanf("%d%d",&x, &index);
        insert(&arr1, index, x);
        break;
    case 2:
        printf("Enter index \n");
        scanf("%d", &x);
        x= delete(&arr1, index);
        printf("Deleted element is %d\n", x);
        break;
    case 3:
        printf("Enter element to search");
        scanf("%d", &x);
        index = linearSearch(&arr1, x);
        printf("Enter index %d", index);
        break;
    case 4:
        printf("The sum of the array is\n", sum(arr1));
        break;
    case 5:
        printf("The reversed array  is \n");
        reverse(&arr1);
    default: printf("Choose again");
    }
    }while(ch <6);
    display(arr1);
    //append(&arr, 10);
    //insert(&arr, 4, 4);
    //printf("%d\n", delete(&arr, 2));
    //printf("%d\n", linearSearch(&arr, 4));
    //printf("%d\n", binarySearch(arr,5));
    //printf("%d\n", rBinarySearch(arr.a,0, arr.len, 3));
    //printf("%d\n",get(arr, 2));
    //set(&arr, 2,11);
    //printf("%d\n", max(arr));
    //printf("%d\n", sum(arr));
    //printf("%d\n",average(arr));
    //reverse(&arr);
    //reverse2(&arr);
    //insertsort(&arr, 7);
    //printf("%d\n", isSorted(arr));
    //rearrange(&arr);
    //arr3= Union(&arr, &arr2);
    //arr3= intersection(&arr, &arr2);
    return 0;
}
