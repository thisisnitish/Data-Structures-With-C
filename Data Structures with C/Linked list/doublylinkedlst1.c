//Everything about doubly linked list...
//Insertion at beginning...
//Insertion at end...
//Insertion at Specific position...
//Deletion at beginning...
//Deletion at end...
//Deletion at specific position...
//Traversing of list...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of a node in doubly linked list
struct node
{
    struct node *prev;     // prev pointer point to the previous node
    int info;
    struct node *next;     // next pointer point to the next node
};

//declaration of all functions
void insertStart(struct node **s, int data);
void insertLast(struct node **s, int data);
void insertAfter(struct node **s, struct node *ptr, int data);
struct node* find(struct node **s, int data);
int deleteFirst(struct node **s);
int deleteLast(struct node **s);
int deleteIntermediate(struct node **s, struct node *ptr);
void viewList(struct node **s);
int getFirst(struct node **s);
int getLast(struct node **s);

//main function
void main()
{
    struct node *ptr;
    struct node *start = NULL;
    int choice,num,n;

    while(1)
    {
        system("cls");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at last");
        printf("\n3. Insert after a node");
        printf("\n4. Delete at beginning");
        printf("\n5. Delete at last");
        printf("\n6. Delete at specific position");
        printf("\n7. View List");
        printf("\n8. Get the first element");
        printf("\n9. Get the last element");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&num);
            insertStart(&start,num);
            break;
        case 2:
            printf("\nEnter the number: ");
            scanf("%d",&num);
            insertLast(&start,num);
            break;
        case 3:
            printf("\nEnter the number from list after which the value is to be inserted: ");
            scanf("%d",&n);
            ptr = find(&start,n);
            printf("\nEnter the number: ");
            scanf("%d",&num);
            insertAfter(&start,ptr,num);
            break;
        case 4:
            deleteFirst(&start);
            break;
        case 5:
            deleteLast(&start);
            break;
        case 6:
            printf("\nEnter the number from the list which is to be deleted: ");
            scanf("%d",&num);
            deleteIntermediate(&start,find(&start,num));
            break;
        case 7:
            viewList(&start);
            break;
        case 8:
            printf("%d",getFirst(&start));
            break;
        case 9:
            printf("%d",getLast(&start));
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        } //end of switch
    getch();
    } //end of while loop
}

//insertion at beginning
//Arguments: node and a data which is to be inserted
void insertStart(struct node **s, int data)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));   //creating a node
    p->info = data;
    p->prev = NULL;
    p->next = *s;
    *s = p;
}

//insertion at last
//Arguments: node and a data which is to be inserted
void insertLast(struct node **s, int data)
{
    struct node *p,*t;
    p = (struct node*)malloc(sizeof(struct node));     //creating a node
    p->info = data;
    p->next = NULL;

    if(*s == NULL)             //when list is empty
    {
        p->prev = NULL;
        *s = p;
    }
    else                        //when list is not empty
    {
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        p->prev=t;
        t->next=p;
    }
}

//insertion at a specific position
//Arguments: node and a data which is to be inserted and a position
void insertAfter(struct node **s, struct node *ptr, int data)
{
    struct node *p;
    if(ptr == NULL)
        printf("Invalid Insertion");
    else
    {
        p = (struct node*)malloc(sizeof(struct node));     //creating a node
        p->info = data;
        p->prev = ptr;
        p->next = ptr->next;
        if(ptr->next != NULL)
            ptr->next->prev = p;
        ptr->next = p;

    }
}

//searching a particular node
struct node* find(struct node **s, int data)
{
    struct node *t;
    if(*s == NULL)
        return(NULL);
    else
    {
        t = *s;
        while(t != NULL)
        {
            if(t->info == data)
                return(t);
            t = t->next;
        }
        return(NULL);
    }
}

//deletion at first
int deleteFirst(struct node **s)
{
    struct node *t;
    if(*s == NULL)       //if the list is empty
        return(0);
    else                  //if the list is not empty
    {
        t = *s;
        *s = (*s)->next;
        (*s)->prev = NULL;
        free(t);
        return(1);
    }
}

//deletion at last
int deleteLast(struct node **s)
{
    struct node *t;
    if(*s == NULL)              //check the list is empty or not
        return(0);
    t = *s;
    while(t->next != NULL)
        t = t->next;
    if((*s)->next == NULL)
        *s = NULL;
    else
        t->prev->next == NULL;
    free(t);
    return(1);
}

//deletion at specific position
int deleteIntermediate(struct node **s, struct node *ptr)
{
    if(*s == NULL)
        return(0);
    if(ptr->prev == NULL)
    {
        *s = ptr->next;
        free(ptr);
        return(1);
    }
    if(ptr->next == NULL)
    {
        ptr->prev->next == ptr->next;
        free(ptr);
        return(1);
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return(1);
}

//traversing a list
void viewList(struct node **s)
{
    struct node *t;
    if(*s == NULL)
        printf("List is empty");
    else
    {
        t = *s;
        while(t != NULL)
        {
            printf("%d ",t->info);
            t = t->next;
        }
    }
}

//get the value of first node
int getFirst(struct node **s)
{
    if(*s == NULL)
    {
        printf("List is empty ");
        return(-1);
    }
    else
    {
        return((*s)->info);
    }
}

//get the value of last node
int getLast(struct node **s)
{
    struct node *t;
    if(*s == NULL)
    {
        printf("List is empty ");
        return(-1);
    }
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;
        return(t->info);
    }
}
