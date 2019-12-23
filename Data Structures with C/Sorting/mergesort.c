//Program to sort an array by merge sort

#include<stdio.h>
#include<conio.h>

void merge(int A[],int size1,int index1,int B[],int size2,int index2,int C[],int index)
{
    while(size1 && size2)       //comparing the size of the two individual arrays
    {
        if(A[index1] < B[index2])        //comparing each elements and assigning them to another sub-arrays
        {
            C[index] = A[index1];
            index++;                       //increase index of C[] array for the next element
            index1++;                        //increase index of A[] array for the next element
            size1--;                        //decreasing the size of the A[] array
        }
        else
        {             //similar procedure with B[] array
            C[index] = B[index2];
            index++;
            index2++;
            size2--;
        }
    }// end of the while
    while(size1)
    {
        C[index] = A[index1];
        index++;
        index1++;
        size1--;
    }
    while(size2)
    {
        C[index] = B[index2];
        index++;
        index2--;
        size2--;
    }
}

//function for merge pass
void mergepass(int A[], int size, int L, int B[])
{
    int j,LB;
    int Q,S,R;
    Q = size/(2*L);    //Q is total pair of sub-arrays to be merged
    S = 2*L*Q;      //S is total number of elements, in total pair of sub-arrays
    R =  size-S;       //R is residual elements which is not in pairing with element with any sub-array

    for(j=0;j<Q;j++)
    {
        LB = (2*j)*L;     //lower bound (index) of first array which is going to be merged
        merge(A,L,LB,A,L,LB+L,B,LB);        //merging two sub arrays and storing them into another array
    }
    if(R <= L)     //if only one sub-array left
    {
        for(j=0;j<R;j++)
            B[S+j] = A[S+j];         //copy last array to B
    }
    else          //if last pair of arrays are of unequal size
    {
        merge(A,L,S,A,R-L,S+L,B,S);
    }
}

//function to sort the array
void merge_sort(int A[],int size)
{
    int L = 1, B[size];      //L is number of elements in a sub-array
    while(L < size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L = 4*L;
    }
}

//main function
void main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);

    int A[size],i;
    printf("\nEnter the array elements: ");;
    for(i=0;i<size;i++)
        scanf("%d",&A[i]);

    merge_sort(A, size);
    printf("\nSorted Array is: ");
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
getch();
}
