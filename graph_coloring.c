#include <stdio.h>

#define MAX_NODES 50

int n, m, count = 0;
int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];

void nextColor(int vertex);
void graphColoring(int vertex);

int main() {
    printf("Graph Coloring Problem\n");

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Possible Solutions are:\n");
    for (m = 1; m <= n; m++) {
        if (count > 0) {
            break;
        }
        graphColoring(1);
    }

    printf("The chromatic number is %d\n", m - 1);
    printf("The total number of solutions is %d\n", count);

    return 0;
}

void graphColoring(int vertex) {
    int i;

    while (1) {
        nextColor(vertex);

        if (colors[vertex] == 0) {
            return;
        }

        if (vertex == n) {
            for (i = 1; i <= n; i++) {
                printf("%d ", colors[i]);
            }
            printf("\n");
            count++;
        } else {
            graphColoring(vertex + 1);
        }
    }
}

void nextColor(int vertex) {
    int j;

    while (1) {
        colors[vertex] = (colors[vertex] + 1) % (m + 1);

        if (colors[vertex] == 0) {
            return;
        }

        for (j = 1; j <= n; j++) {
            if (graph[vertex][j] == 1 && colors[vertex] == colors[j]) {
                break;
            }
        }

        if (j == n + 1) {
            return;
        }
    }
}

// output :
/*
Graph Coloring Problem
Enter the number of nodes: 5
Enter Adjacency Matrix:
0 1 0 1 1
1 0 1 1 1
0 1 0 1 1
1 1 1 0 1
1 0 1 1 0
Possible Solutions are:
1 2 1 3 2 
1 3 1 2 3 
2 1 2 3 1 
2 3 2 1 3 
3 1 3 2 1 
3 2 3 1 2 
The chromatic number is 3
The total number of solutions is 6
*/