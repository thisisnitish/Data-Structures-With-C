//Program for linear search

#include<stdio.h>
#include<conio.h>

//linear search function
void linear_search(int a[],int size)
{
    int i,item,flag=0;
    printf("\nEnter the element you want to search: ");
    scanf("%d",&item);
    for(i=0;i<size;i++)
    {
        if(a[i] == item)
            flag = 1;
    }
    if(flag == 1)
        printf("\nSearch Successful");
    else
        printf("\nSearch Unsuccessful");
}

void main()
{
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int a[size];
    printf("\nEnter the array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    linear_search(a,size);       //calling the function
    //for(i=0;i<size;i++)
    //    printf("%d ",a[i]);
getch();
}
