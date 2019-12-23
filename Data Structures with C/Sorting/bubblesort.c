//Program for bubble sort to sort the element in ascending order

#include<stdio.h>
#include<conio.h>

//declaration of functions
void Bubble_Sort(int* ,int);
void swap(int*,int*);

//main function
void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int A[size],i;
    for(i=0;i<size;i++){
        printf("\nEnter the array elements %d:",i+1);
        scanf("%d",&A[i]);
    }

    Bubble_Sort(A,size);       //calling the bubble sort function

    for(i=0;i<size;i++)
        printf("%d ",A[i]);
getch();
}

//Bubble_Sort function
void Bubble_Sort(int A[],int N)
{
    int round,i,temp,flag;
    for(round=1;round<=N-1;round++)
    {
        flag = 0;
        for(i=0;i<=N-1-round;i++){
            if(A[i] > A[i+1]){
                flag = 1;
                swap(&A[i],&A[i+1]);   //calling of swap function
                }
        }
        if(flag == 0)
        {
            //printf("Round %d\n",round);    //to count the number of pass after every comparison
            return;
        }
    }
}

//swap function to swap the values after comparison
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
