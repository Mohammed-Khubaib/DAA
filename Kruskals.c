#include <stdio.h>
#include <stdlib.h>

int i,j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9]= {0};
int find(int);
int uni(int, int);

int main()
{
    // for (i = 0 ; i <9;i++){
        // printf("%d ",parent[i]);
    // }
    // printf("\n");
    // printf("Kruskal's algorithm in C\n");
    // printf("========================\n");
    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    // for (int j = 1 ; j <=6;j++){
        // printf("%d ",parent[j]);
    // }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

int find(int i)
{
    // printf("\n %d : \n",i);
    // for (int j = 1 ; j <=6;j++){
        // printf("%d ",parent[j]);
    // }
    // printf("\n");
    while (parent[i]){
        i = parent[i];
    }
    // printf("\ni=%d\n",i);
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}


/*Sample Output :

Kruskal's algorithm in C
========================
Enter the no. of vertices:
6

Enter the cost adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0 
The edges of Minimum Cost Spanning Tree are
1 edge (1,3) =1
2 edge (4,6) =2
3 edge (1,2) =3
4 edge (2,5) =3
5 edge (3,6) =4

Minimum cost = 13

*/