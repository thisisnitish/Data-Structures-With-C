//Everything about Queue as dynamic array or ADT.....

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct QueueADT
{
    int capacity;
    int front;
    int rear;
    int *arr;
};

struct QueueADT* createQueue(int cap);
int isEmptyQueue(struct QueueADT *Q);
int isFULLQueue(struct QueueADT *Q);
int queueCapacity(struct QueueADT *Q);
void doubleQueue(struct QueueADT *Q);
void halfQueue(struct QueueADT *Q);
void enQueue(struct QueueADT *Q, int value);
void deQueue(struct QueueADT *Q);
struct QueueADT* deleteQueue(struct QueueADT *Q);

struct QueueADT* deleteQueue(struct QueueADT *Q)
{
    free(Q->arr);
    free(Q);
    return(NULL);
}

void deQueue(struct QueueADT *Q)
{
    int i,size=0;
    if(isEmptyQueue(Q))
        printf("\nUnderflow");
    else if(Q->front==Q->rear)
        Q->front=Q->rear=-1;
    else if(Q->front==Q->capacity-1)
        Q->front=0;
    else
        Q->front=Q->front+1;

    if(Q->front>-1){
    for(i=Q->front;i!=Q->rear;)
    {
        size++;
        if(i==Q->capacity-1)
            i=0;
        else
            i++;
    }
    size++;
    if(size==Q->capacity/2)
        halfQueue(Q);
    }
}

void enQueue(struct QueueADT *Q, int value)
{
    if(Q->capacity<1)
        printf("Invalid capacity");
    else
    {
        if(isEmptyQueue(Q))
        {
            Q->arr[0]=value;
            Q->front=0;
            Q->rear=0;
        }
        else if(isFULLQueue(Q))
        {
            doubleQueue(Q);
            Q->rear=Q->rear+1;
            Q->arr[Q->rear]=value;
        }
        else
        {
            if(Q->rear==Q->capacity-1)
                Q->rear=0;
            else
                Q->rear=Q->rear+1;
            Q->arr[Q->rear]=value;
        }
    }
}

void halfQueue(struct QueueADT *Q)
{
    int *temp;
    int i,j,l;
    temp=(int *)malloc(sizeof(int)*(Q->capacity/2));
    l=Q->capacity/2;
    for(i=0,j=Q->front;i<l;i++){
        temp[i]=Q->arr[j];
        if(j==Q->capacity-1)
            j=0;
        else
            j++;
    }
    free(Q->arr);
    Q->arr=temp;
    Q->capacity=l;
    Q->front=0;
    Q->rear=l-1;
}

void doubleQueue(struct QueueADT *Q)
{
    int i,j;
    int *temp;
    Q->capacity=Q->capacity*2;
    temp=(int *)malloc(Q->capacity*sizeof(int));
    for(i=Q->front,j=0;i!=Q->rear;j++)
    {
        temp[j]=Q->arr[i];
        if(i==Q->capacity/2-1 && Q->rear!=i)
            i=0;
        else
            i++;
    }
    free(Q->arr);
    Q->arr=temp;
    Q->front=0;
    Q->rear=Q->capacity/2-1;
}

int queueCapacity(struct QueueADT *Q)
{
    return(Q->capacity);
}

int isFULLQueue(struct QueueADT *Q)
{
    if(Q->front==0 && Q->rear==Q->capacity-1)
        return(1);
    else if(Q->front==Q->rear+1)
        return(1);
    else
        return(0);
}

int isEmptyQueue(struct QueueADT *Q)
{
    if(Q->front==-1)
        return(1);
    else
        return(0);
}

struct QueueADT* createQueue(int cap)
{
    struct QueueADT *temp;
    temp=(struct QueueADT *)malloc(sizeof(struct QueueADT));
    temp->capacity=cap;
    temp->front=-1;
    temp->rear=-1;
    temp->arr=(int*)malloc(sizeof(int)*temp->capacity);
    return(temp);
}

int menu()
{
    int choice;
    system("cls");
    printf("\n1. see the status of Queue");
    printf("\n2. Insert a data in Queue");
    printf("\n3. Remove a data from Queue");
    printf("\n4. End Program");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    return(choice);
}

void main()
{
    struct QueueADT *Q;
    int value;
    Q=createQueue(4);
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("\nCapacity: %d",queueCapacity(Q));
            printf("\nFront: %d Rear: %d",Q->front,Q->rear);
            break;
        case 2:
            printf("\nEnter a number: ");
            scanf("%d",&value);
            enQueue(Q,value);
            break;
        case 3:
            deQueue(Q);
            break;
        case 4:
            Q=deleteQueue(Q);
            exit(0);
        default:
            printf("\nInvalid choice, retry");
        }
        getch();
    }
}
