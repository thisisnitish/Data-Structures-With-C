//C code to sort an array with the help quick sort

#include<stdio.h>
#include<conio.h>

void quicksort(int *, int, int);

void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int a[size],i;
    printf("\nEnter the array elements: ");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);

    quicksort(a,0,size-1);

    printf("\nSorted array is: ");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);

    getch();
}

void quicksort(int a[],int low, int upper)
{
    int i,j,pivot,temp;

    if(low < upper)
    {
        pivot = low;                    //selecting the index for the pivot element
        i = low;
        j = upper;

        while(i < j)    //repeating the procedure
        {
            //if the element  is less than the pivot element, increase the value of i by 1 until i is less than upper
            while(a[i] <= a[pivot] && i <= upper)
                i++;
            //if the element  is more than the pivot element, decrease the value of j by 1 until j is more than low
            while(a[j] > a[pivot] && j>= low)
                j--;

            //if i < j swap the elements
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        // when i >= j that means j is the correct position of the pivot element,
        //now swap the pivot element with the element at j-th position
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;

        //repeat the quick sort for the two sub-arrays, one for the left of j and another for the right of j
        quicksort(a, low, j-1);
        quicksort(a, j+1, upper);
    }
}
