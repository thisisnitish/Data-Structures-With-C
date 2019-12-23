//Program for dijkstra's algorithm

#include<stdio.h>
#include<conio.h>

//declaration of global variable
int INFINITY = 9999;
int MAX = 10;

//declaration of dijkstra function
//void dijkstra(int**,int,int);

void dijkstra(int G[MAX][MAX],int n,int source_node)
{
    int cost[MAX][MAX],distance[MAX],visited[MAX],predecessor[MAX];
    int i,j,nextnode,count,min_distance;

    //nextnode will keep the node value which is visited recently
    //count simply count the number of nodes seen so far
    //predecessor[] array will stores the predecessor of each node...i.e.parent
    //creating the cost matrix from adjacency matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j] == 0)      //if G[i][j] = 0...assign infinity in place of that
                cost[i][j] = INFINITY;
            else                          //else assign the values
                cost[i][j] = G[i][j];


    //initializing the distance[],visited[] and predecessor[] array
    for(i=0;i<n;i++)
    {
        distance[i] = cost[source_node][i];
        predecessor[i] = source_node;
        visited[i] = 0;
    }

    distance[source_node] = 0;      //for the source node distance from source node to source node will be 0
    visited[source_node] = 1;       //visited for source node to source node will be 1 because we have been visited a node
    count = 1;                      //count will increase by 1

    //loop will execute until all the nodes have not visited...if every nodes will be visited..then loop will stop
    while(count < n-1)
    {
        min_distance = INFINITY;

        //go for next node and it will give the node at minimum distance
        for(i=1;i<n;i++)   //visit each node from source node
            if((distance[i] < min_distance) && !visited[i])
            {
                min_distance = distance[i];
                nextnode = i;
            }

        //check if better path exists through nextnode
        visited[nextnode] = 1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(min_distance+cost[nextnode][i] < distance[i])
                {
                    distance[i] = min_distance + cost[nextnode][i];
                    predecessor[i] = nextnode;
                }
        count++;
    }

    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i != source_node)
        {
            printf("\nDistance of node %d = %d",i,distance[i]);
            printf("\nPath = %d",i);

            j=i;
            do
            {
                j = predecessor[j];
                printf("<-- %d",j);
            }while(j != source_node);
        }
}

//main function
void main()
{
    int G[MAX][MAX],n,i,j,source_node;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    //inputs for adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    //inputs for source to start in a way to find the shortest path from source to any vertex
    printf("\nEnter the source node from where you want to find the shortest path: ");
    scanf("%d",&source_node);

    //calling the dijkstra function
    dijkstra(G,n,source_node);

getch();
}
