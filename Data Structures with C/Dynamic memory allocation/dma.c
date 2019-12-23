//create an array by malloc...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int n,i,*ptr,sum=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    ptr=(int *)malloc(n*sizeof(int));

    if(ptr==NULL)
    {
        printf("\nMemory is not allocated...");
        exit(0);
    }
    else
    {
        printf("\nEnter elements: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&ptr[i]);
            sum+=ptr[i];
        }
    }
    printf("%d ",sum);
getch();
}
