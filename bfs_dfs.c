#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
// Structure to represent a node in the graph
typedef struct Node{
    int data;
    struct Node* next;
}Node;
// Structure to represent the directed graph
typedef struct {
    int numNodes;
    Node* adjList[MAX_NODES];
    int visited[MAX_NODES];
}Graph;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the directed graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform Breadth-First Search (BFS)
void BFS(Graph* graph, int startNode) {
    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    graph->visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("Nodes reachable from node %d using BFS: ", startNode);

    while (front != rear) {
        // Dequeue a vertex from the queue
        int current = queue[front++];

        printf("%d ", current);

        // Traverse all adjacent vertices of the dequeued vertex
        Node* temp = graph->adjList[current];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (graph->visited[adjNode] == 0) {
                // Mark the adjacent node as visited and enqueue it
                graph->visited[adjNode] = 1;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void DFSUtil(Graph* graph, int node) {
    // Mark the current node as visited
    graph->visited[node] = 1;
    // Print the visited node
    printf("%d ", node);

    // Traverse all adjacent vertices of the current node
    Node* temp = graph->adjList[node];
    while (temp != NULL) {
        int adjNode = temp->data;
        if (graph->visited[adjNode] == 0) {
            DFSUtil(graph, adjNode);
        }
        temp = temp->next;
    }
}

// Function to check if the graph is connected using DFS
int isConnected(Graph* graph,int startNode) {
    // Perform DFS traversal from the first node
    DFSUtil(graph, startNode);

    // Check if all nodes are visited
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->visited[i] == 0) {
            return 0; // Graph is not connected
        }
    }

    return 1; // Graph is connected
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    printf("Enter 'B' for BFS \n 'D' for DFS\n");
    char ws ;
    scanf("%c",&ws);

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &graph->numNodes);

    // Initialize adjacency list and visited array
    for (int i = 0; i < graph->numNodes; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source node and destination node):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node : ");
    scanf("%d", &startNode);
    switch (ws)
    {
    case 'B':
        BFS(graph, startNode);  
        break;
    case 'D':
        printf("Nodes reachable from node %d using DFS: ", startNode);
        int connected = isConnected(graph,startNode);
        if (connected) {
            printf("\n\nThe graph is connected.\n");
            // DFSUtil(graph, startNode);
        } else {
            printf("The graph is not connected.\n");
        }
        break;
    
    default:
        printf("Enter 'B' for BFS \n 'D' for DFS\n");
        break;
    }


    return 0;
}
// output :
/*
Enter the number of nodes in the graph: 9
Enter the number of edges: 18
Enter the edges (source node and destination node):
1 2
1 3
1 4
3 2
4 3
2 5
4 7
6 3
5 3
3 7
5 6
7 6
8 5
6 8
7 8
8 9
7 9
9 6
*/

/*
1 3
1 4
1 5
3 6
4 7
5 8
*/