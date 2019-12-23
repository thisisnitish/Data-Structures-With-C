//Program for binary search

#include<stdio.h>
#include<conio.h>

void swap(int*,int*);
void Bubble_Sort(int A[],int N);
void binary_search(int a[],int size);

void binary_search(int a[],int size)
{
    int item,low=0,upper=size-1,mid;
    printf("\nEnter the item to be searched: ");
    scanf("%d",&item);

    while(low <= upper)
    {
        mid = (low+upper)/2;
        if(item == a[mid]){
            printf("Search Successful");
            return;
            }
        else if(item > a[mid])
            low = mid+1;
        else
            upper = mid-1;
    }
    printf("\nSearch Unsuccessful");
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


void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int a[size];
    printf("\nEnter the array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    Bubble_Sort(a,size);
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);

    binary_search(a,size);
getch();
}
