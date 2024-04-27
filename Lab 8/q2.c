#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1001
#define MAX_EDGES 2000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];
int distances[MAX_NODES];
bool visited[MAX_NODES];
int queue[MAX_NODES];

void initializeGraph(int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        distances[i] = -1;
        graph[i] = NULL;
    }
}

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}

void bfs(int n, int start) {
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;
    distances[start] = 0;

    while (front < rear) {
        int node = queue[front++];
        for (Node* current = graph[node]; current != NULL; current = current->next) {
            int neighbor = current->vertex;
            if (!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = true;
                distances[neighbor] = distances[node] + 2;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    initializeGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start_node;
    scanf("%d", &start_node);

    bfs(n, start_node);

    printf("BFS Traversal: ");
    for (int i = 1; i <= n; i++) {
        if (distances[i] != -1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Distance: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");

    return 0;
}
