#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Graph ADT
struct Graph
{
    int V;                 //vertices
    int E;                //edges
    int **Adj;            //2 dimensionally array
};

//function to create adjacent matrix
struct Graph* createAdjMatrix()
{
    int u,v,i;
    struct Graph *G;
    //creating the Graph structure dynamically
    G = (struct Graph*)malloc(sizeof(struct Graph));
    if(!G)           //if the memory for graph is not allocated
        printf("\nMemory error");
    printf("\nEnter the number of vertices: ");
    scanf("%d",&G->V);
    printf("\nEnter the number of edges: ");
    scanf("%d",&G->E);
    //creating the adjacency matrix array dynamically
    //G->Adj = (int **)malloc((G->V * G->V)*sizeof(int));
    G->Adj = (int**)malloc(G->V * sizeof(int*));
    for(i=0;i<G->V;i++)
        G->Adj[i] = (int*)malloc(G->V * sizeof(int));

    //by default we want to put all value is 0
    for(u=0;u<G->V;u++)
        for(v=0;v<G->V;v++)
            G->Adj[u][v] = 0;

    //inserting the value by 1 at the location where there exist a edge between two vertices
    for(i=0;i<G->E;i++)
    {
        printf("\nEnter the vertex number in pairs to show that there exist an edge between them: ");
        scanf("%d %d",&u,&v);
        printf("%d\n",i);
        //here we are inserting the values to those location where there exist an edge between them
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
return(G);
}

//function to display the adjacency matrix
void display_Adjmatrix(struct Graph *G)
{
    int i,j;
    printf("\nAdjacency matrix is:\n");
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++)
        {
            printf("%d ",G->Adj[i][j]);
        }
        printf("\n");
    }
}

//main function
void main()
{
    struct Graph *G = createAdjMatrix();
    display_Adjmatrix(G);
    getch();
}
