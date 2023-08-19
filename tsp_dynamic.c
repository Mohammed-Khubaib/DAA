#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

int cost[N][N] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

int all_sets = (1 << N) - 1; // Set all_sets to 1111 (binary representation) : Used to track all cities visited
int memo[N][(1 << N)]; // Memoization array
int optimal_path[N][N]; // To store the optimal path

int tsp(int mask, int pos) {
    if (mask == all_sets) {
        optimal_path[pos][mask] = 0;
        return cost[pos][0];  // Return to the starting city
    }

    if (memo[pos][mask] != -1) {
        return memo[pos][mask]; // If the result is already computed, return it
    }

    int min_cost = INT_MAX;
    int best_city = -1; // Track the best next city

    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) { //if the current city is already visited then don't visit it again .
            int new_cost = cost[pos][city] + tsp(mask | (1 << city), city);
            if (new_cost < min_cost) {
                min_cost = new_cost;
                best_city = city;
            }
        }
    }

    optimal_path[pos][mask] = best_city; // Store the best next city

    return memo[pos][mask] = min_cost; // Store the computed result
}

int main() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            memo[i][j] = -1; // Initialize memoization array with -1
        }
    }

    int min_cost = tsp(1, 0); // Start from city 0

    printf("Optimal path: 0 -> ");
    int current_city = 0;
    int mask = 1;
    while (mask != all_sets) {
        int next_city = optimal_path[current_city][mask];
        printf("%d -> ", next_city);
        mask |= (1 << next_city);
        current_city = next_city;
    }
    printf("0\n");  // Print the last city

    printf("Minimum cost of the tour: %d\n", min_cost);

    return 0;
}
