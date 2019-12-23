//C code for Krushkal's Algorithm

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 30
//int MAX = 30;

//representation of edge
struct edge
{
    int u,v,weight;                       //source, destination and weight
};

//representation of edge list
struct edgelist
{
    struct edge data[MAX];
    int n;
};
struct edgelist edge_list;

int G[MAX][MAX],n;
struct edgelist spanlist;

//declaration of all the functions
void krushkal();
int find(int belongs[], int vertexno);
void union1(int belongs[], int c1, int c2);
void sort();
void display();

//main function
void main()
{
    int i,j,total_cost;

    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&G[i][j]);

    krushkal();          //calling krushkal function
    display();               //calling display function

    getch();
}

//function to follow the krushkal's algorithm
void krushkal()
{
    int belongs[MAX],i,j,cno1,cno2;
    edge_list.n = 0;

    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j] != 0)
            {
                edge_list.data[edge_list.n].u = i;
                edge_list.data[edge_list.n].v = j;
                edge_list.data[edge_list.n].weight = G[i][j];
                edge_list.n++;
            }
        }
        sort();

        for(i=0;i<n;i++)
            belongs[i] = i;

        spanlist.n = 0;

        for(i=0;i<edge_list.n;i++)
        {
            cno1 = find(belongs, edge_list.data[i].u);
            cno2 = find(belongs, edge_list.data[i].v);

            if(cno1 != cno2)
            {
                spanlist.data[spanlist.n] = edge_list.data[i];
                spanlist.n = spanlist.n + 1;
                union1(belongs, cno1, cno2);
            }
        }
}

int find(int belongs[], int vertexno)
{
    return(belongs[vertexno]);
}

void union1(int belongs[], int c1, int c2)
{
    int i;
    for(i=0;i<n;i++)
        if(belongs[i] == c2)
            belongs[i] = c1;
}

//function to sort the edges according to their weights
void sort()
{
    int i,j;
    struct edge temp;

    for(i=0;i<edge_list.n;i++)
        for(j=0;j<edge_list.n-1;j++)
            if(edge_list.data[j].weight > edge_list.data[j+1].weight)
            {
                temp = edge_list.data[j];
                edge_list.data[j] = edge_list.data[j+1];
                edge_list.data[j+1] = temp;
            }
}

//function to display the minimum spanning cost
void display()
{
    int i, cost=0;
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d %2d %2d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].weight);
        cost = cost+spanlist.data[i].weight;
    }
    printf("\nCost of Spanning Tree: %d",cost);
}
