#include <stdio.h>
#define INF 999
#define N 6
int main() {
   int arr[N][N] = {INF,50,45,10,INF,INF,
                    INF,INF,10,15,INF,INF,
                    INF,INF,INF,INF,30,INF,
                    10,INF,INF,INF,15,INF,
                    INF,20,35,INF,INF,INF,
                    INF,INF,INF,INF,3,INF};
   int i , j , k , l ;
   printf("Adjacency Matrix of cost of edges : \n");
   for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
   }
   for(k=0;k<N;k++){
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if(arr[i][k]+arr[k][j]<arr[i][j]){
                arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
   }
   printf("\n Adjecency Matrix of Lowest cost between the vertices :\n");

   for(i=0;i<1;i++){
    for(j=1;j<N;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
   }
   return 0;
}
/*
Adjacency Matrix of cost of edges : 
INF,50,45,10,INF,INF,
INF,INF,10,15,INF,INF,
INF,INF,INF,INF,30,INF,
10,INF,INF,INF,15,INF,
INF,20,35,INF,INF,INF,
INF,INF,INF,INF,3,INF

Adjecency Matrix of Lowest cost between the vertices :
45      45      10      25      999
*/