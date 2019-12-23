//Stack using Array....
//check stack is full....
//check stack is empty...
//push an element....
//pop an element....
//view stack element....

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of stack ADT
struct ArrayStack
{
    int top;       //top variable holds the index of the array
    int capacity;       //capacity variable holds the size of the array
    int *array;        //to access the array
};

//function to create stack
//Arguments: capacity of the array
struct ArrayStack* createStack(int cap)
{
    struct ArrayStack *stack;

    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));    //creating ADT dynamically
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int)*stack->capacity);    //creating the array dynamically

    return(stack);
}

//function to check the stack is full
int isFull(struct ArrayStack *stack)
{
    return(stack->top == stack->capacity-1);
}

//function to check the stack is empty
int isEmpty(struct ArrayStack *stack)
{
    return(stack->top == -1);
}

//function to push the value inside the stack
//Arguments: value which is to be pushed
void push(struct ArrayStack *stack,int item)
{
    if(!isFull(stack))     //check condition if stack is not full
    {
        stack->top++;
        stack->array[stack->top] = item;
    }
    else
        printf("\nOverflow");
}

//function to pop or delete the value from stack
int pop(struct ArrayStack *stack)
{
    int item;
    if(!isEmpty(stack))     //check if stack is empty or not
    {
        item = stack->array[stack->top];
        stack->top--;
        return(item);
    }
    return(-1);
}

//function to display the elements from the stack
void viewstack(struct ArrayStack *stack)
{
    int i;
    if(isEmpty(stack))  //if stack is empty
        printf("\nStack is empty!!!");
    else
    {
        for(i=0;i<=stack->top;i++)
        {
            printf("%d ",stack->array[i]);
        }
    }
}

//main function
void main()
{
    int choice,item,size;
    struct ArrayStack *stack;
    printf("\nEnter the size of the stack: ");
    scanf("%d",&size);
    stack=createStack(size);
    while(1)
    {
        system("cls");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. View Stack");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d",&item);
                push(stack,item);
                break;
            case 2:
                item = pop(stack);
                if(item == -1)
                    printf("\nStack is empty");
                else
                    printf("\nPopped Value is %d",item);
                break;
            case 3:
                viewstack(stack);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice");
        }
        getch();
    }
}
