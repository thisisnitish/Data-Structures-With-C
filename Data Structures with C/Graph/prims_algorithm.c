//Program for prims algorithm

#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 20
//declaration of global variables
//int MAX = 20;     //to give the size of the variable
//int INFINITY = 9999;      //to specify the infinity value
int G[MAX][MAX],spanning[MAX][MAX];   //graph matrix and spanning tree matrix
int n;               //represent the number of vertices

int prims()
{
    int cost[MAX][MAX];
    int visited[MAX],distance[MAX],from[MAX];
    int u,v,i,j,min_distance,no_of_edges,min_cost;

    //creating the cost[][] matrix and spanning[][] matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j] == 0)      //if the element is 0 in the adjacency matrix assign that position by infinity in cost matrix
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
                spanning[i][j] = 0;          //inserting 0 to every value in the spanning matrix
        }

    //initialize visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;
    for(i=1;i<n;i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    min_cost = 0;        //cost of spanning matrix
    no_of_edges = n-1;   //number of edges to be added

    while(no_of_edges>0)
    {
        //find the vertex at minimum distance from tree
        min_distance = INFINITY;
        for(i=1;i<n;i++)
            if(visited[1] == 0 && (distance[i] < min_distance))
            {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];

        //inserting the edge in the spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;

        //update the distance array
        for(i=1;i<n;i++)
            if(visited[i] == 0 && (cost[i][v] < distance[i]))
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        min_cost = min_cost+cost[u][v];
    }
return(min_cost);
}

void main()
{
    int i,j,total_cost;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    total_cost = prims();
    printf("\nSpanning tree matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%2d",spanning[i][j]);
    }
    printf("\nTotal cost of the spanning tree is: %d",total_cost);
    getch();
}
