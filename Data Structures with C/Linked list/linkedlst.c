//Basic implementation of linked list...
//insertion at the last....
//insertion at the beginning....
//insertion at specific position....
//Deletion at beginning......
//Deletion at last....
//Deletion at specific position...
//Traversing of the list.....

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of a node in linked list
struct node
{
    int info;
    struct node *link;
};

struct node *START = NULL;    //declaration and initializing of START pointer of node type

//function to create a node
struct node* createNode()
{
    struct node *n;   //pointer variable that will store the address of the node
    n = (struct node *)malloc(sizeof(struct node));
    return(n);
}

//insert an element at end in the linked list
void insertNodeatEnd()
{
    struct node *temp,*t;
    temp = createNode();
    printf("Enter a number: ");
    scanf("%d",&temp->info);

    temp->link = NULL;

    if(START == NULL)      //when list is empty
        START = temp;
    else
    {
        t = START;

        while(t->link != NULL)
        {
            t = t->link;
        }

        t->link = temp;
    }
}

//insert an element at beginning in the linked list
void insertNodeatBeg()
{
    struct node *temp;
    temp = createNode();
    printf("Enter the number: ");
    scanf("%d",&temp->info);

    if(START == NULL)
        temp->link = NULL;
    else
        temp->link = START;
    START = temp;
}

//insert an element after any specific position in the linked list
void insertAtSpecificPosition()
{
    struct node *temp, *t;
    int pos,i;
    t = START;
    printf("Enter the location to add the number: ");
    scanf("%d",&pos);

    for(i=0;i<pos-1;i++)
    {
        t = t->link;
        if(t == NULL)
            printf("Invalid location");
    }
    temp = createNode();
    printf("Enter the number: ");
    scanf("%d",&temp->info);
    temp->link = t->link;
    t->link = temp;
}

//deletion of first node
void deleteFirstNode()
{
    struct node *r;
    if(START == NULL)
        printf("\nList is empty");
    else
    {
        r = START;
        START = START->link;
        free(r);
    }
}

//deletion of last node
void deleteLastNode()
{
    struct node *r, *second_last_node;
    if(START == NULL)
        printf("\nList is empty");
    else
    {
        r = START;
        second_last_node = START;
        while(r->link != NULL)
        {
            second_last_node = r;
            r = r->link;
        }
        if(r == START)       //if there will be only one node
            START = NULL;
        else
            second_last_node->link = NULL;

        free(r);
    }
}

//deletion at specific position
void deleteAtSpecificPosition()
{
    struct node *r,*t;
    int pos,i;
    if(START == NULL)
        printf("\nList is empty");
    else
    {
        r=START;
        printf("\nEnter a position value to delete that node: ");
        scanf("%d",&pos);

        for(i=0;i<pos-1;i++)
        {
            r = r->link;
            if(r == NULL)
                printf("\nInvalid Location");
        }
        t = r->link;
        r->link = t->link;
        free(t);
    }
}

//Traversing the whole list
void viewList()
{
    struct node *t;
    if(START == NULL)
        printf("List is empty");
    else
    {
        t = START;
        while(t != NULL)
        {
            printf("%d ",t->info);
            t = t->link;
        }
    }
}

//driver function to handle all the operations
int menu()
{
    int ch;
    printf("\n1.Add value to the end.");
    printf("\n2.Add value to the beginning");
    printf("\n3.Add value after a position");
    printf("\n4.Delete first value");
    printf("\n5.Delete last value");
    printf("\n6.Delete after a position");
    printf("\n7.View List");
    printf("\n8.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    return(ch);
}

//main function
void main()
{
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            insertNodeatEnd();
            break;
        case 2:
            insertNodeatBeg();
            break;
        case 3:
            insertAtSpecificPosition();
            break;
        case 4:
            deleteFirstNode();
            break;
        case 5:
            deleteLastNode();
            break;
        case 6:
            deleteAtSpecificPosition();
            break;
        case 7:
            viewList();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid input");
        } //end of switch
    getch();
    } //end of while
}
