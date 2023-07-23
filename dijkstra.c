#include <stdio.h>
#define INF 999
int main() {
   int arr[4][4];
   int cost[4][4] = {7,5,0,0,7,0,0,2,0,3,0,0,4,0,1,0};
   int i , j , k , l , n = 4;
   for(i = 0 ; i < n;i++){
    for(j=0;j<n;j++){
        if(cost[i][j]==0){
            arr[i][j]=INF;
        }
        else{
            arr[i][j] = cost[i][j];
        }
    }
   }

   printf("Adjacency Matrix of cost of edges : \n");
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
   }
   for(k=0;k<n;k++){
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(arr[i][j]>arr[i][k]+arr[k][j]){
                arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
   }
   printf("\n Adjecency Matrix of Lowest cost between the vertices :\n");
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
   }
   return 0;
}
/*
Adjacency Matrix of cost of edges : 
7       5       999     999
7       999     999     2
999     3       999     999
4       999     1       999

 Adjecency Matrix of Lowest cost between the vertices :
7       5       8       7
6       6       3       2
9       3       6       5
4       4       1       6
*/