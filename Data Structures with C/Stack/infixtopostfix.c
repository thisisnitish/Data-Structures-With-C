/*
Conversion of infix expression to postfix expression.....
Example:
Input: infix expression: a+b*(c^d-e)^(f+g*h)-i
Output: postfix expression: abcd^e-fgh*+^*+i-
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//representation of stack
struct ArrayStack
{
    int top;     //represent the index of array
    int capacity;   //represent the size of the array
    int *array;
};

//function to create stack
//Arguments: size of the array
struct ArrayStack* createStack(int capacity)
{
    struct ArrayStack *stack;

    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int)*stack->capacity);       //creating a dynamic array
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

//push function to insert an element into the stack
//Arguments: stack and item which is going to be pushed
void push(struct ArrayStack *stack,char item)
{
    if(!isFull(stack))       //if stack is not full then it will execute
    {
        stack->top++;
        stack->array[stack->top] = item;
    }
    else
        return;
}

//pop function to pop element from the stack
char pop(struct ArrayStack *stack)
{
    char data;
    if(!isEmpty(stack))      //if stack is not empty
    {
        data = stack->array[stack->top];
        stack->top--;
        return(data);
    }
    else
        return('\0');
}

//function to check the character is operand or not
//Arguments: character from infix expression
int is_operand(char ch)
{
    if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9'))
        return(1);
    else
        return(0);
}

//function to check the operator precedence
//Arguments: operator from infix expression
int operator_precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return(1);
    else if(ch == '*' || ch == '/')
        return(2);
    else if(ch == '^')
        return(3);
    else
        return(0);
}

//function to convert infix expression to postfix expression
//Arguments: infix expression, postfix array
char *infix_to_postfix(char* infix,char* postfix)
{
    struct ArrayStack* stack = createStack(strlen(infix));    //calling createStack function to create a stack
    int j = -1;
    char item;
    for(int i = 0;infix[i] != '\0';i++)
    {
        item = infix[i];
        if(is_operand(item))     //if character is operand
            postfix[++j] = item;
        else if(item == '(')      //if left parenthesis is encountered
                push(stack,item);
        else if(item == ')')      //if right parenthesis is encountered
        {
            while(!isEmpty(stack) && (stack->array[stack->top] != '('))
                    postfix[++j] = pop(stack);
                pop(stack);
        }
        else
        {
            //if operator is encountered
            while(!isEmpty(stack) && (operator_precedence(item) <= operator_precedence(stack->array[stack->top])))
                postfix[++j] = pop(stack);
            push(stack,item);
        }
    }   //end of for loop
    while(!isEmpty(stack))
        postfix[++j] = pop(stack);       //end of while loop
    postfix[++j] = '\0';
    //printf("%s",postfix);        //printing the postfix expression
    return(postfix);
}

//function to convert infix expression to prefix expresson
//Arguments: infix expression and prefix array
char *infix_to_prefix(char* infix,char* prefix)
{
    return(strrev(infix_to_postfix(strrev(infix),prefix)));
}

//main function
void main()
{
    int choice;
    char infix[100];
    char postfix[100];
    char prefix[100];
    printf("Enter the expression: ");
    gets(infix);
    while(1)
    {
        system("cls");
        printf("1. Convert expression from infix to postfix");
        printf("\n2. Convert expression from infix to prefix");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            //infix_to_postfix(infix,postfix);
            printf("\n%s",infix_to_postfix(infix,postfix));
            break;
        case 2:
            printf("\n%s",infix_to_prefix(infix,prefix));
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
        getch();
    }
}
