//C code to sort the array by counting sort

#include<stdio.h>
#include<conio.h>

void counting_sort(int *,int *,int);

//counting sort function
void counting_sort(int a[], int b[], int size)
{
    int c[10],i,j;

    //initially c[] array will have all the elements 0
    for(i=0;i<10;i++)
        c[i] = 0;

    //c[] array will contain the frequency of the elements in the array
    for(j=0; j<size; j++)
        c[a[j]] = c[a[j]] + 1;

    //finding the cumulative frequency in the c[] array
    for(i=1; i<10; i++)
        c[i] = c[i] + c[i-1];

    for(j=size-1; j>=0; j--)
    {
        b[c[a[j]]-1] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }

}

//main function
void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int a[size],b[size],i;
    printf("\nEnter the array elements: ");
    for(i=0; i<size; i++)
        scanf("%d",&a[i]);

    counting_sort(a,b,size);               //calling the counting sort function
    printf("\nSorted array is: ");
    for(i=0; i<size; i++)
        printf("%d ",b[i]);

    getch();
}
