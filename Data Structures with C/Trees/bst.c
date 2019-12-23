//Basic implementation of binary search tree using linked list by recursion

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//representation of node for binary tree by linked implementation
struct bstnode
{
    struct bstnode *left;    //points to the left child node
    int data;
    struct bstnode *right;   //points to the right child node
};

//global declaration of a variable root which is pointing to the first node
struct bstnode *root = NULL;

//function to create a node
struct bstnode* createnode(int data)
{
    struct bstnode *n = (struct bstnode *)malloc(sizeof(struct bstnode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
};

//find node function to check the element is present or not
int find_node(struct bstnode* root, int data)
{
    if(root == NULL)
        return(0);
    else if(data < root->data)
        find_node(root->left,data);
    else if(data > root->data)
        find_node(root->right,data);
return(1);
}

//insertion in a binary tree
struct bstnode* insert_node(struct bstnode* root,int data)
{
    if(root == NULL)
        root = createnode(data);
    else if(data < root->data)
        root->left = insert_node(root->left,data);
    else                                                          //if(data > root->data)
        root->right = insert_node(root->right,data);
return(root);
}

//function to find the maximum value present in the tree
struct bstnode* find_max(struct bstnode *root)
{
    if(root->right == NULL)
        return(root);
    find_max(root->right);
    //return(find_max(root->right));
}

//function to find the minimum value present in the tree
struct bstnode* find_min(struct bstnode *root)
{
    if(root->left == NULL)
        return(root);
    find_min(root->left);
    //return(find_min(root->left));
}

//deletion of node
//Arguments: root and the value which is to be deleted
struct bstnode* delete_node(struct bstnode *root, int value)
{
    struct bstnode *temp;
    if(root == NULL)
        printf("\nNo such element is exists");
    else if(value < root->data)    //the value which is to be deleted is less than the root data
        root->left = delete_node(root->left,value);
    else if(value > root->data)    //the value which is to be deleted is more than the root data
        root->right = delete_node(root->right,value);
    else
    {         //when the element will found then delete operation will start
        if(root->left && root->right)     //when there will be two children of a node
        {
            temp = find_max(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left,root->data);
        }
        else
        {       //when there will be only one or no child
            temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }//end of else
    return(root);
}

//inorder traversal
//Argument: root
void inorder_traversal(struct bstnode *t)
{
    if(root == NULL)
        printf("\nList is empty");
    if(t != NULL)
    {
        inorder_traversal(t->left);
        printf("%d ",t->data);
        inorder_traversal(t->right);
    }
}

//preorder traversal
//Argument: root
void preorder_traversal(struct bstnode *t)
{
    if(root == NULL)
        printf("\nList is empty");
    if(t != NULL)
    {
        printf("%d ",t->data);
        preorder_traversal(t->left);
        preorder_traversal(t->right);
    }
}

//postorder traversal
//Argument: root
void postorder_traversal(struct bstnode *t)
{
    if(root == NULL)
        printf("\nList is empty");
    if(t != NULL)
    {
        postorder_traversal(t->left);
        postorder_traversal(t->right);
        printf("%d ",t->data);
    }
}

//driver function
void main()
{
    int choice,data,num;
    struct bstnode *r,*t;
    while(1)
    {
        system("cls");
        printf("\n1. Insert data");
        printf("\n2. Delete");
        printf("\n3. In order Traversal");
        printf("\n4. Pre order Traversal");
        printf("\n5. Post Traversal");
        printf("\n6. Maximum Value");
        printf("\n7. Minimum Value");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d",&num);
            root = insert_node(root,num);
            break;
        case 2:
            printf("\nEnter the number to be deleted: ");
            scanf("%d",&data);
            root = delete_node(root,data);
            break;
        case 3:
            inorder_traversal(root);
            break;
        case 4:
            preorder_traversal(root);
            break;
        case 5:
            postorder_traversal(root);
            break;
        case 6:
            r = find_max(root);
            printf("\nMaximum Value is: %d",r->data);
            break;
        case 7:
            t = find_min(root);
            printf("\nMinimum Value is: %d",t->data);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }//end of switch
        getch();
    } //end of while loop
}  //end of main function
