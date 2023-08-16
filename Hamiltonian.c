#include <stdio.h>

#define V 5 // Number of vertices

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

void printSolution() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Print the starting vertex to complete the cycle
}

int isSafe(int v, int pos, int path[V]) {
    if (graph[path[pos - 1]][v] == 0) // Check if there's an edge from the previous vertex
        return 0;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) // Check if the vertex is already included in the path
            return 0;
    }

    return 1;
}

int hamiltonianCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) // Check if there's an edge from the last to the first vertex
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(pos + 1))
                return 1;
            path[pos] = -1; // Backtrack
        }
    }

    return 0;
}

void hamiltonianCycle() {
    for (int i = 0; i < V; i++) {
        path[i] = -1; // Initialize path with -1
    }
    path[0] = 0; // Start from vertex 0

    if (hamiltonianCycleUtil(1)) {
        printSolution();
    } else {
        printf("No Hamiltonian Cycle exists.\n");
    }
}

int main() {
    printf("Hamiltonian Cycle Problem\n");
    hamiltonianCycle();
    return 0;
}
