/*Program for Array ADT...
ADT full form is Abstract data type
Representation of array in the form of abstract data type
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of arrayADT
struct arrayADT
{
    int capacity;        //capacity of the array
    int lastIndex;       //represent the last index
    int *ptr;
};

//declaration of all functions
struct arrayADT* createArray(int capacity);
int getItem(struct arrayADT *arr, int index);
int setItem(struct arrayADT*, int index, int value);
int editItem(struct arrayADT*, int index, int newvalue);
int countItems(struct arrayADT*);
int removeItem(struct arrayADT*, int index);
int search(struct arrayADT*, int item);
void sort(struct arrayADT*);

//function to create Array
//Arguments: capacity of the array
struct arrayADT* createArray(int capacity)
{
    struct arrayADT *arr;
    arr=(struct arrayADT*)malloc(sizeof(struct arrayADT));       //using malloc() to create ADT dynamically
    arr->capacity=capacity;
    arr->lastIndex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*arr->capacity);          //using malloc() to create array dynamically
    return(arr);
}

//function to display the elements in the array
//Arguments: array and the index of elements
int getItem(struct arrayADT *arr, int index)
{
    if(arr->lastIndex<index || index<0)
    {
        printf("\nInvalid Index");
        return(-1);
    }
    else
    {
        return(arr->ptr[index]);
    }
}

//function to insert a number in the array
//Arguments: index in the array and the value which is to be inserted
int setItem(struct arrayADT* arr, int index, int value)
{
    int i;
    if(arr->lastIndex == arr->capacity-1)      //array is full....
    {
        printf("Overflow");
        return(0);
    }
    if(index<0 || index>arr->lastIndex+1)
    {
        printf("Invalid Index");
        return(0);
    }
    if(index<=arr->lastIndex)
    {
        arr->lastIndex=arr->lastIndex+1;
        i=arr->lastIndex;
        while(i!=index)
        {
            arr->ptr[i]=arr->ptr[i-1];
            i--;
        }
        arr->ptr[index]=value;
        return(1);
    }
    if(index==arr->lastIndex+1)
    {
        arr->lastIndex=arr->lastIndex+1;
        arr->ptr[arr->lastIndex]=value;
        return(1);
    }
}

//function to edit a number in the array
//Arguments: index in the array where number is to be edited and the new value is to placed at that location
int editItem(struct arrayADT* arr, int index, int newvalue)
{
    if(index<0 || index>arr->lastIndex)
    {
        printf("Invalid Index");
        return(0);
    }
    else
    {
        arr->ptr[index]=newvalue;
        return(1);
    }
}

//function to count the number of elements in the array
int countItems(struct arrayADT*arr)
{
    return(arr->lastIndex+1);
}

//function to delete a number from the array
//Arguments: index of that number which is to be deleted
int removeItem(struct arrayADT*arr, int index)
{
    if(index<0 || index>arr->lastIndex)
    {
        printf("Invalid Index");
        return(0);
    }
    if(index<arr->lastIndex)
    {
        int i;
        i=index;
        while(i<arr->lastIndex)
        {
            arr->ptr[i]=arr->ptr[i+1];
            i++;
        }
        arr->lastIndex=arr->lastIndex-1;
        return(1);
    }
    if(index==arr->lastIndex)
    {
        arr->lastIndex=arr->lastIndex-1;
        return(1);
    }
}

//function to search a particular number in the array
//Arguments: number which you want to search
int search(struct arrayADT* arr, int item)
{
    int i;
    if(arr->lastIndex==-1)
        return(-1);
    for(i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==item)
            return(i);
    return(-1);
}

//function to sort the array
void sort(struct arrayADT* arr)
{
    int r,n,i,t;
    n=arr->lastIndex+1;
    for(r=1;r<=n-1;r++)
    {
        for(i=0;i<=n-r-1;i++)
        {
            if(arr->ptr[i]>arr->ptr[i+1])
            {
               t=arr->ptr[i];
               arr->ptr[i]=arr->ptr[i+1];
               arr->ptr[i+1]=t;
            }
        }
    }
}

//main function
//driver program
void main()
{
    int i,choice,size,num,index,new_value;
    struct arrayADT *arr;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    arr = createArray(size);

    while(1)
    {
        system("cls");
        printf("\n1. Insert number");
        printf("\n2. Edit number");
        printf("\n3. Remove number");
        printf("\n4. Sort the Array");
        printf("\n5. Search a number");
        printf("\n6. Display the array");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&num);
            printf("\nEnter the index for item to be placed there: ");
            scanf("%d",&index);
            setItem(arr,index,num);
            break;
        case 2:
            printf("\nEnter the index where you want to edit a number: ");
            scanf("%d",&index);
            printf("\nEnter the new value for that location: ");
            scanf("%d",&new_value);
            editItem(arr,index,new_value);
            break;
        case 3:
            printf("\nEnter the index number where you want to delete a number: ");
            scanf("%d",&index);
            removeItem(arr,index);
            break;
        case 4:
            sort(arr);
            break;
        case 5:
            printf("\nEnter the number you want to search: ");
            scanf("%d",&num);
            i = search(arr,num);
            if(i==-1)
                printf("\nItem not found");
            else
                printf("\nItem found at index %d",i);
            break;
        case 6:
            for(i=0;i<countItems(arr);i++)
                printf("%d ",getItem(arr,i));
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
        } //end of the switch
    getch();
    }//end of the while loop
}//end of the main function
