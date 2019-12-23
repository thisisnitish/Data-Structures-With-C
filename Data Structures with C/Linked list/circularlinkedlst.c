//Circular linked list.....
//Insertion at beginning...
//Insertion at end...
//Insertion after a position...
//Deletion of element...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of a node
struct node
{
    int data;                       // data variable will store the data
    struct node *next;             // next pointer will store the address of next node
};

//declaration of all functions
struct node* createList(struct node *last);
void display(struct node *last);
struct node* add_to_empty(struct node *last,int value);
struct node* add_at_beginning(struct node *last,int value);
struct node* add_at_end(struct node *last,int value);
struct node* add_after(struct node *last,int value,int item);
struct node* delete_node(struct node *last,int value);

//display function to display the list
void display(struct node *last)
{
    struct node *t;
    if(last == NULL)
        printf("\nList is empty");
    else
    {
        t = last->next;
        do
        {
            printf("%d ",t->data);
            t = t->next;
        }while(t != last->next);
    }
}

//function to insert node at beginning
//Arguments: a node and data which you want to insert
struct node* add_at_beginning(struct node *last,int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));   // creating a node dynamically with the help of malloc
    n->data = value;
    n->next = last->next;
    last->next = n;
    return(last);
}

//function to insert node at empty list
//Arguments: node and value which is to be inserted
struct node* add_to_empty(struct node *last,int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));          // creating a node dynamically with the help of malloc
    n->data = value;
    last = n;
    last->next = last;
    return(last);
}

//function to insert node at end
//Arguments: node and a value which is to be inserted at the end of list
struct node* add_at_end(struct node *last,int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));                // creating a node dynamically with the help of malloc
    n->data = value;
    n->next = last->next;
    last->next = n;
    last = n;
    return(last);
}

//function to insert node after specific position
//Arguments: node and value which is to be inserted and after the item value
struct node* add_after(struct node *last, int value,int item)
{
    struct node *t,*n;
    t = last->next;

    do
    {
        if(t->data == item)
        {
            n = (struct node *)malloc(sizeof(struct node));         // creating a node dynamically with the help of malloc
            n->data = value;
            n->next = t->next;
            t->next = n;

            if(t == last)
                last = n;
            return(last);
        }
        t = t->next;
    }while(t != last->next);
    printf("\n%d is not in the list",item);
    return(last);
}

//function to delete node
//Arguments: node and a value which is to be deleted
struct node* delete_node(struct node *last,int value)
{
    struct node *t,*p;
    if(last == NULL)        //check if the list is empty
    {
        printf("\nList is empty");
        return(last);
    }
    if(last == last->next && last->data == value)
    {
        t=last;
        last == NULL;
        free(t);
        return(last);
    }
    if(last->next->data == value)
    {
        t = last->next;
        last->next = t->next;
        free(t);
        return(last);
    }
    p = last->next;
    while(p->next != last)
    {
        if(p->next->data == value)
        {
            t = p->next;
            p->next = t->next;
            free(t);
            return(last);
        }
        p = p->next;
    }
    if(last->data == value)
    {
        t = last;
        p->next = last->next;
        last = p;
        free(t);
        return(last);
    }
    printf("\n%d is not found",value);
    return(value);
}

//function to create list
struct node* createList(struct node *last)
{
    int i,n,value;
    printf("How many values you want to enter: ");
    scanf("%d",&n);
    printf("\nEnter first data for the list: ");
    scanf("%d",&value);
    last = add_to_empty(last,value);

    for(i = 2;i <= n;i++)
    {
        printf("\nEnter data for the list: ");
        scanf("%d",&value);
        last = add_at_end(last,value);
    }
    return(last);
}

//main function with driver program
void main()
{
    int choice,value,item;
    struct node *last = NULL;

    while(1)
    {
        system("cls");
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Add to empty list");
        printf("\n4. Add at beginning");
        printf("\n5. Add at end");
        printf("\n6. Add after");
        printf("\n7. Delete an element from the list");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            last = createList(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("\nEnter a number for the list: ");
            scanf("%d",&value);
            last = add_to_empty(last,value);
            break;
        case 4:
            printf("\nEnter a number for the list: ");
            scanf("%d",&value);
            last = add_at_beginning(last,value);
            break;
        case 5:
            printf("\nEnter a number for the list: ");
            scanf("%d",&value);
            last = add_at_end(last,value);
            break;
        case 6:
            printf("\nEnter a number for the list: ");
            scanf("%d",&value);
            printf("\nEnter item value after new value to be inserted: ");
            scanf("%d",&item);
            last = add_after(last,value,item);
            break;
        case 7:
            printf("\nEnter value of element to be deleted: ");
            scanf("%d",&value);
            last = delete_node(last,value);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }//end of switch
        getch();
    }//end of for loop
}
//end of main function
