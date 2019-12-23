/*Sorted linked list
Some of the functions used in this program is taken from linkedlst.c
Path:-  C:\Users\Dell\Documents\DataStructureswithC\Linked list\linkedlst.c
if you want to access this program uncomment the main function
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"linkedlst.c"

void insertNode()
{
    int status = 0;
    struct node *temp,*t,*r;
    temp = createNode();
    printf("Enter a number: ");
    scanf("%d",&temp->info);

    temp->link = NULL;
    if(START == NULL)       //if the list is empty
    {
        START = temp;
    }
    else if(START->info > temp->info)   //if the coming node is smallest among the existing node
    {
        temp->link = START;
        START = temp;
    }
    else                       //if you want to insert node somewhere in the middle
    {
        t = START;
        r = START;
        while(temp->info > t->info)
        {
            if(t->link == NULL)     //if the inserted node is bigger than all other existing nodes
            {
                status = 1;
                break;
            }
            r = t;
            t = t->link;
        }
        if(status == 0)
        {
            temp->link = t;
            r->link = temp;
        }
        else
        {
            t->link = temp;
        }
    }   //end of else
}
/*
void main()
{
    int choice;

    while(1)
    {
        system("cls");
        printf("\n1.Insert element");
        printf("\n2.Delete first value");
        printf("\n3.Delete last value");
        printf("\n4.Delete after a position");
        printf("\n5.View List");
        printf("\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteAfter();
            break;
        case 3:
            deleteLastNode();
            break;
        case 4:
            deleteAfter();
            break;
        case 5:
            viewList();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
        }   //end of switch
    getch();
    }    // end of while
}
*/
