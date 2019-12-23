//c code to reverse the linked list
//this program is only made for reversing the list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of the node
struct node
{
    int data;          //contains data
    struct node *next;
};

//START pointer will points to the head node
struct node *START = NULL;

//function to create the node
struct node* createnode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));    //node is creating dynamically
    return(n);
}

//function to insert node
void insert_node()
{
    struct node *temp,*t;
    temp = createnode();   //calling the createnode() function to create the node
    printf("\nEnter the number: ");
    scanf("%d",&temp->data);
    temp->next = NULL;

    if(START == NULL)        //if the list is empty
        START = temp;
    else            //if the list is not empty
    {
        t = START;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

//function to display list
void display_list()
{
    struct node *t;
    if(START == NULL)
        printf("\nList is empty");
    else
    {
        t = START;
        while (t != NULL)
        {
            printf("%d ",t->data);
            t = t->next;
        }
    }
}

//function to reverse the list
void reverse_list()
{
    struct node *t1,*t2;
    if(START == NULL)             //if the list is empty
        printf("\nList is empty");
    else
    {
        t1 = t2 = NULL;        //initially both the pointers have NULL
        while(START != NULL){
        t2 = START->next;
        START->next = t1;
        t1 = START;
        START = t2;
        }
        START = t1;
    }
}

//main function
void main()
{
    int choice;
    while(1){
    system("cls");
    printf("\n1. Insert an element in the list");
    printf("\n2. View list");
    printf("\n3. Reverse list");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        insert_node();
        break;
    case 2:
        display_list();
        break;
    case 3:
        reverse_list();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\nInvalid Choice");
        break;
    }// end of the switch
    getch();
    }// end of the while loop
}
