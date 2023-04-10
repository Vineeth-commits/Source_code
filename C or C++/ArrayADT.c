#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void input(struct Array *arr)
{
    printf("Enter all the elements\n");
    for(int i = 0;i<arr->length;i++)
    {
        scanf("%d",&arr->A[i]);
    }
}

void display(struct Array *arr)
{
    printf("The elements in the array are:\n");
    for (int i = 0;i<arr->length;i++)
    {
        printf("%d\n",arr->A[i]);
    }
}

void append(struct Array *arr)
{
    int x;
    printf("Enter the element to append\n");
    scanf("%d",&x);
    arr->A[arr->length] = x;
    arr->length++;
}

void insert(struct Array *arr)
{
    int index,num;
    printf("Enter the index\n");
    scanf("%d",&index);
    printf("Enter the number\n");
    scanf("%d",&num);
    for(int i = arr->length;i<index;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = num;
    arr->length++;
}

void delete(struct Array *arr)
{
    int index,num;
    printf("Enter the index of the element to be deleted\n");
    scanf("%d",&index);
    for(int i = index;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void linear(struct Array *arr)
{
    int key;
    printf("Enter the element to be searched");
    scanf("%d",&key);
    for(int i =0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            printf("Element found in index %d",i);
            return;
        }
    }
    printf("Element not found");
}

void binary(struct Array *arr)
{
    int low = 0;
    int high = arr->length-1;
    int mid = (low+high)/2;
    int key;
    printf("Enter the element to be searched");
    scanf("%d",&key);
    while(low<=high)
    {
        if(key==arr->A[mid])
        {
            printf("Element found in position %d",mid);
            break;
        }
        else if(key<arr->A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low+high)/2;
    }
}

void reverse(struct Array *arr)
{
    int temp;
    for(int i = 0,j=arr->length-1;i<j;i++,j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void insertSort(struct Array *arr)
{
    printf("Enter the element to be inserted in sorted order");
    int key;
    scanf("%d",&key);
    int i = arr->length -1;
    while(arr->A[i]>key)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = key;
}

void isSorted(struct Array *arr)
{
    for(int i = 0;i<arr->length-1;i++)
    {
        if(arr->A[i]>arr->A[i+1])
        {
            printf("Isnt sorted");
            return;
        }
    }
    printf("Sorted");
}

void negativeLeft(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    int temp;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0)j++;
        if(i<j)
        {
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

void merge()
{
    int A[] = {3,4,1,6,2};
    int B[] = {6,7,8,5,5,9};
    int m = 5;
    int n = 6;
    int C[m+n];
    int i = 0,j = 0, k = 0;
    while(i<m&&j<n)
    {
        if(A[i]<A[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while(i<m)
    {
        C[k++] = A[i++];
    }
    while(j<n)
    {
        C[k++] = B[j++];
    }
}

int main() 
{
    struct Array arr;
    menu:
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    printf("Enter the number of elements in an array\n");
    scanf("%d",&arr.length);
    if(arr.length<=arr.size)
    {
        input(&arr);
    }else{
        printf("The number of elements exceeds the size of the array\n");
        goto menu;
    }
    int choice;
    Return :
    printf("Enter the options below\n");
    printf("Press 0 to display the elements of an array\n");
    printf("Press 1 to append an element in an array\n");
    printf("Press 2 to insert an element in an array\n");
    printf("Press 3 to delete an element\n");
    printf("Press 4 to do linear search");
    printf("Press 5 to do binary search");
    printf("Press 6 to reverse an array");
    printf("Press 7 to insert an element sorted");
    printf("Press 8 to check if the array is sorted");
    printf("Press 9 to put all negative elements to the left");
    printf("Press 10 to merge two arrays sorted");
    printf("Press -1 to exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case -1: break;
        case 0: display(&arr);
                goto Return;
        case 1: if((arr.size-arr.length)>=1)
                    append(&arr);
                else
                    printf("Cant add element as the size of the array is full\n");
                goto Return;
        case 2: if((arr.size-arr.length)>=1)
                    insert(&arr);
                else
                    printf("Cant add element as the size of the array is full\n");
                goto Return;
        case 3: delete(&arr);
                goto Return;
        case 4: linear(&arr);
                goto Return;
        case 5: binary(&arr);
                goto Return;
        case 6: reverse(&arr);
                goto Return;
        case 7: insertSort(&arr);
                goto Return;
        case 8: isSorted(&arr);
                goto Return;
        case 9: negativeLeft(&arr);
                goto Return;
        case 10: merge();
                 goto Return;
    }
}
