//Program for selection sort

#include<stdio.h>
#include<conio.h>

//void Selection_Sort(int *, int);
void swap(int*,int*);
int min(int *, int, int);

//function to find the minimum value from the array
int min(int A[],int k,int size)
{
    int location,MIN;        //location of a number and Minimum value in the array respectively
    MIN = A[k];
    location = k;

    for(int j=k+1;j<size;j++)
        if(MIN > A[j])
        {
            MIN = A[j];
            location = j;
        }
    return(location);
}

//swap function
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//main function
void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int location,A[size],i,k,temp;
    for(i=0;i<size;i++)
    {
        printf("\nEnter the array elements %d:",i+1);
        scanf("%d",&A[i]);
    }
    for(k=0;k<size-1;k++)
    {
        location = min(A,k,size);
        swap(&A[k],&A[location]);
    }
    for(k=0;k<size;k++)
        printf("%d ",A[k]);
getch();
}
