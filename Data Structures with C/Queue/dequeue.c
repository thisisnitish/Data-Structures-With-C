//Program for doubly ended queue(dequeue)...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of queue...
struct dequeue
{
    int front;
    int rear;
    int capacity;
    int *array;
};

//creating a queue...
struct dequeue* createdequeue(int cap)
{
    struct dequeue *temp;
    temp = (struct dequeue *)malloc(sizeof(struct dequeue));
    temp->capacity = cap;
    temp->front = -1;
    temp->rear = -1;
    temp->array = malloc(sizeof(int)*temp->capacity);
    return(temp);
}

//function to check the dequeue is empty or not
int isEmptydequeue(struct dequeue *temp)
{
    if(temp->front==-1)
        return(1);
    else
        return(0);
}

//function to check the dequeue is full or not
int isFULLdequeue(struct dequeue *temp)
{
    if((temp->front==0 && temp->rear==temp->capacity-1) || (temp->front==temp->rear+1))
        return(1);
    else
        return(0);
}

//function to insert an element from the right side of the dequeue
void insert_right(struct dequeue *temp, int data)
{
    if(isFULLdequeue(temp))          //check weather the dequeue is full or not
        printf("\nDequeue Overflow...");

    if(temp->front == -1)
    {
        temp->front = 0;
        temp->rear = 0;
    }
    else if(temp->rear == temp->capacity-1)
        temp->rear = 0;
    else
        temp->rear = temp->rear+1;
    temp->array[temp->rear] = data;
}

//function to insert an element from the left side of the dequeue
void insert_left(struct dequeue *temp, int data)
{
    if(isFULLdequeue(temp))             //check weather the dequeue is full or not
        printf("\nDequeue Overflow...");

    if(temp->front == -1)
    {
        temp->front = 0;
        temp->rear = 0;
    }
    else if(temp->front == 0)
        temp->front = temp->capacity-1;
    else
        temp->front = temp->front-1;
    temp->array[temp->front] = data;
}

//function to delete an element from right side of the dequeue
void delete_right(struct dequeue *temp)
{
    int item = -1;   //initializing a variable name item = -1

    if(isEmptydequeue(temp))         //check weather the dequeue is empty or not
        printf("\nDequeue Underflow");

    item = temp->array[temp->rear];
    printf("\nDeleted item is: %d",item);
    if(temp->front == temp->rear)
    {
        temp->front = -1;
        temp->rear = -1;
    }
    else if(temp->rear == 0)
        temp->rear = temp->capacity-1;
    else
        temp->rear = temp->rear-1;
}

//function to delete an element from right side of the dequeue
void delete_left(struct dequeue *temp)
{
    int item=-1;        //initializing a variable name item = -1

    if(isEmptydequeue(temp))           //check weather the dequeue is empty or not
        printf("\nDequeue Underflow");

    item = temp->array[temp->front];
    printf("\nDeleted item is: %d",item);
    if(temp->front == temp->rear)
    {
        temp->front = -1;
        temp->rear = -1;
    }
    else if(temp->front == temp->capacity-1)
        temp->front = 0;
    else
        temp->front = temp->front+1;
}

//function to display the elements from dequeue
void display_dequeue(struct dequeue *temp)
{
    int front_pos,rear_pos;         //initializing variables

    front_pos = temp->front;
    rear_pos = temp->rear;

    if(isEmptydequeue(temp))           //check weather the dequeue is empty or not
        printf("\nDequeue Underflow");
    else
    {
        if(front_pos <= rear_pos)
        {
            while(front_pos <= rear_pos)
            {
                printf("%d ",temp->array[front_pos]);
                front_pos++;
            }
        }
        else
        {
            while(front_pos <= temp->capacity-1)
            {
                printf("%d ",temp->array[front_pos]);
                front_pos++;
            }
            front_pos = 0;
            while(front_pos <= rear_pos)
            {
                printf("%d ",temp->array[front_pos]);
                front_pos++;
            }
        }
        printf("\n");
    }
}

//driver function for input restricted dequeue....
void input_dequeue()
{
    int choice,size,item;
    struct dequeue *temp;
    printf("\nEnter the size of dequeue: ");
    scanf("%d",&size);
    temp = createdequeue(size);

    while(1)
    {
        system("cls");
        printf("\n1. Insert at right");
        printf("\n2. Delete from left");
        printf("\n3. Delete from right");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&item);
            insert_right(temp, item);
            break;
        case 2:
            delete_left(temp);
            break;
        case 3:
            delete_right(temp);
            break;
        case 4:
            display_dequeue(temp);
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong choice");
        }
    getch();
    }
}

//driver function for output restricted dequeue....
void output_dequeue()
{
    int choice,size,item;
    struct dequeue *temp;
    printf("\nEnter the size of dequeue: ");
    scanf("%d",&size);
    temp = createdequeue(size);

    while(1)
    {
        system("cls");
        printf("\n1. Insert at right");
        printf("\n2. Insert at left");
        printf("\n3. Delete from left");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&item);
            insert_right(temp, item);
            break;
        case 2:
            printf("\nEnter the number: ");
            scanf("%d",&item);
            insert_left(temp, item);
            break;
        case 3:
            delete_left(temp);
            break;
        case 4:
            display_dequeue(temp);
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong choice");
        }
    getch();
    }
}

//driver main function to call input restricted queue or output restricted queue
void main()
{
    int choice;
    system("cls");
    printf("\n1.Input restricted dequeue");
    printf("\n2.Output restricted dequeue");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        input_dequeue();
        break;
    case 2:
        output_dequeue();
        break;
    default:
        printf("\nWrong Choice");
    }
}
