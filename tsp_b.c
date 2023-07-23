#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 10
#define INF 999

int cost[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int n, minCost = INF;
int optimalPath[MAX_CITIES];
int currentPath[MAX_CITIES];

void tsp_bruteforce(int currentCity, int depth, int totalCost) {
    printf("\n\ncc= %d , d = %d , tc = %d \n\n",currentCity,depth,totalCost);
    if (depth == n - 1) { 
        if (cost[currentCity][0] != 0) { 
            totalCost += cost[currentCity][0]; // Complete the cycle
            if (totalCost < minCost) {
                minCost = totalCost; 
                // Store the current path as the optimal path
                for (int i = 0; i < n; i++) {
                    optimalPath[i] = currentPath[i];
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && cost[currentCity][i] != 0) { 
            // cc = 0 i = 1
            // cc = 1 i = 2
            visited[i] = 1; 
            currentPath[depth + 1] = i; // Store the current city in the path
            tsp_bruteforce(i, depth + 1, totalCost + cost[currentCity][i]);
            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    printf("Enter Total Number of Cities:\t");
    scanf("%d", &n);

    printf("\nEnter Cost Matrix\n");
    for (int i = 0; i < n; i++) {
        printf("Enter %d Elements in Row[%d]\n", n, i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize the visited array with all 0's, except for the starting city
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;

    // Store the starting city in the path
    currentPath[0] = 0;

    tsp_bruteforce(0, 0, 0);

    printf("\nMinimum Cost: %d\n", minCost);

    // Print the optimal path
    printf("Optimal Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", optimalPath[i] + 1);
    }
    printf("1\n"); // Complete the cycle to return to the starting city

    return 0;
}

/*
Enter Total Number of Cities:   5

Enter Cost Matrix
Enter 5 Elements in Row[1]
0 2 5 8 1
Enter 5 Elements in Row[2]
6 0 3 9 2
Enter 5 Elements in Row[3]
8 7 0 4 8 
Enter 5 Elements in Row[4]
13 4 7 0 5
Enter 5 Elements in Row[5]
1 3 2 8 0

Minimum Cost: 15
*/