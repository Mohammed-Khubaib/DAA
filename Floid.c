#include <stdio.h>

#define INF  99999
#define V  4

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]){
    int dist[V][V];
    for(int i =0;i<V;i++)
        for(int j = 0 ; j<V;j++)
            dist[i][j] = graph[i][j];
    
    for(int k =0;k<V;k++){
        for(int i = 0;i <V;i++){
            for(int j = 0; j<V;j++){
                //D^k[i,j]=min(D^{k-1}[i,j],D^{k-1}[i,k]+D^{k-1}[k,j])
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}

void printSolution(int dist[][V]){
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}


int main() {
// Both the following graphs are tested :


//    int graph[V][V] = {
//         {0,9,-4,INF},
//         {6,0,INF,2},
//         {INF,5,0,INF},
//         {INF,INF,1,0}
//    };

   int graph[V][V] = {
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
   };


    floydWarshall(graph);
   return 0;
}