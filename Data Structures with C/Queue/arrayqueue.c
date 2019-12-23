//Array implementation of queue.....
//insertion and deletion in queue...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of the queue ADT
struct ArrayQueue
{
    int front, rear;           //represent front and rear for insertion and deletion
    int capacity;         //capacity of the queue
    int *array;       //represents the array
};

//function to create the queue
//Arguments: capacity of the queue
struct ArrayQueue* createQueue(int capacity)
{
    //creating the queue ADT dynamically
    struct ArrayQueue *Q = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
    if(!Q)    //if memory will not allocate the space for Q then it will return the NULL
        return(NULL);
    Q->capacity = capacity;
    Q->front = Q->rear = -1;          //initially the front and rear value is -1
    Q->array = (int *)malloc(Q->capacity*sizeof(int));        //creating the array dynamically
    if(!Q->array)       //if array will not get the memeory then it returns NULL
        return(NULL);
    return(Q);
}

//function to check the queue is empty or not
//Arguments: Q
int isEmptyQueue(struct ArrayQueue *Q)
{
    //if front is equal to -1 then queue is empty and it returns 1
    return(Q->front == -1);
}

//function to check the queue is full or not
//Arguments:Q
int isFullQueue(struct ArrayQueue *Q)
{
    //if the queue will be full then it will return 1
    return((Q->rear+1)%Q->capacity == Q->front);
}

//function to insert an elements
//Arguments: Q, data value which is to be inserted
void enQueue(struct ArrayQueue *Q, int data)
{
    //if the queue will full
    if(isFullQueue(Q))
        printf("Overflow");
    else   //if queue will not full
    {
        Q->rear = (Q->rear+1) % Q->capacity;           //increasing the value of rear by 1
        Q->array[Q->rear] = data;              //inserting an element in the array
        if(Q->front == -1)     //check if front = -1 then increase its value
            Q->front = Q->rear;
    }
}

//function to delete an elements from the queue
//Arguments: Q
int deQueue(struct ArrayQueue *Q)
{
    int data;
    if(isEmptyQueue(Q))         //if the queue will be empty
        printf("Queue is Empty");
    else           //if the queue will not be empty
    {
        data = Q->array[Q->front];    //take the value at the front variable and assign it to data
        if(Q->front == Q->rear)   //check if there was only one element in the queue
            Q->front = Q->rear = -1;    //assigning the front and rear value to -1
        else
            Q->front = (Q->front+1) % Q->capacity;             //increasing the front value by 1
    }
    return(data);
}

//function to display the queue elements
//Arguments: Q
void displayQueue(struct ArrayQueue *Q)
{
    int i;
    //if queue will be empty
    if(isEmptyQueue(Q))
        printf("\nQueue is empty");
    else           //if queue will not be empty
    {
        printf("\nQueue is: ");
        i = Q->front;
        while(i <= Q->rear)
        {
            printf("%d ",Q->array[i]);
            i++;
        }
    }
}

//main function
void main()
{
    int choice,item,size;
    struct ArrayQueue *Q;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    Q=createQueue(size);
    while(1)
    {
        system("cls");
        printf("\n1. Insert an element in Queue");
        printf("\n2. Delete element from Queue");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&item);
            enQueue(Q,item);
            break;
        case 2:
            deQueue(Q);
            break;
        case 3:
            displayQueue(Q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\ninvalid choice");
            break;
        }  //end of switch
getch();
    }  //end of while loop
}
