#include <stdio.h>
#include <stdlib.h>
//operations on array
struct array
{
    int *a;
    int size;
    int len;
};
//display
void display(struct array arr){
int i;
printf("Elements are \n");
for (i=0; i<arr.len; i++)
    printf("%d", arr.a[i]);
}
int main()
{
    struct array arr;
    int n,i;
    printf("Enter size of array \n");
    scanf("%d", &arr.size);
    arr.a = (int*)malloc(arr.size*sizeof(int));
    arr.len=0;
    printf("Enter how many numbers \n");
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", &arr.a[i]);
    arr.len=n;
display(arr);
    return 0;
}
