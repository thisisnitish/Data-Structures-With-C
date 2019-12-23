//C code to sort an array with the help of heap sort

#include<conio.h>
#include<stdio.h>
int arr[20];
//int n;
//Function to display the elements in the array
void display(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}/*End of display()*/

//Function to insert an element to the heap
void insert(int num,int loc)
{
    int par;
    while(loc>0)
    {
        par = (loc-1)/2;
        if (num<=arr[par])
        {
            arr[loc]=num;
            return;
        }
        arr[loc]=arr[par];
        loc=par;
}/*End of while*/
arr[0]=num;
}/*End of insert()*/

//This function to create a heap
void create_heap(int n)
{
    int i;
    for(i=0;i<n;i++)
    insert(arr[i],i);
}/*End of create_heap()*/

//Function to delete the root node of the tree
void del_root(int last)
{
    int left,right,i,temp;
    i=0; /*Since every time we have to replace root with last*/
    /*Exchange last element with the root */
    temp=arr[i];
    arr[i]=arr[last];
    arr[last]=temp;
    left=2*i+1; /*left child of root*/
    right=2*i+2;/*right child of root*/
    while( right < last)
    {
        if ( arr[i]>=arr[left] && arr[i]>=arr[right] )
        return;
        if ( arr[right]<=arr[left] )
        {
            temp=arr[i];
            arr[i]=arr[left];
            arr[left]=temp;
            i=left;
        }
        else
        {
            temp=arr[i];
            arr[i]=arr[right];
            arr[right]=temp;
            i=right;
        }
        left=2*i+1;
        right=2*i+2;
}/*End of while*/

if(left == last - 1 && arr[i]<arr[left])/*right==last*/
{
    temp=arr[i];
    arr[i]=arr[left];
    arr[left]=temp;
}
}/*End of del_root*/

//Function to sort an element in the heap
void heap_sort(int n)
{
    int last;
    for(last = n-1;last>0;last--)
        del_root(last);
}/*End of del_root*/

void main()
{
    int i,n;
    printf ("\nEnter number of elements : ");
    scanf ("%d",&n);
    for(i=0;i<n;i++)
    {
        printf ("\nEnter element %d : ",i+1);
        scanf ("%d",&arr[i]);
    }
    printf ("\nEntered list is : ");
    display(n);
    create_heap(n);
    printf ("\nHeap is : ");
    display(n);
    heap_sort(n);
    printf ("\nSorted list is : ");
    display(n);
    getch();
}/*End of main()*/
