//Program for insertion sort

#include<stdio.h>
#include<conio.h>

//declaration of a function
void insertion_sort(int *,int);

//function to sort the array by insertion sort
//Arguments: array and size of the array
void insertion_sort(int A[],int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp = A[i];
        for(j=i-1;j>=0 && temp < A[j];j--)
            A[j+1] = A[j];
        A[j+1] = temp;
    }
}

//main function
void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int A[size],i;
    for(i=0;i<size;i++)
    {
        printf("\nEnter the array element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    insertion_sort(A,size);            //calling the  function

    for(i=0;i<size;i++)       //print the sorted array
        printf("%d ",A[i]);
getch();
}
