#include <stdio.h>
#define MAX_VERTICES 10

void initializeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1; // Remove this line for directed graphs
}

void printMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    int matrix[MAX_VERTICES][MAX_VERTICES];
    
    initializeMatrix(matrix, vertices);
    
    addEdgeMatrix(matrix, 0, 1);
    addEdgeMatrix(matrix, 0, 2);
    addEdgeMatrix(matrix, 1, 2);
    addEdgeMatrix(matrix, 1, 3);
    addEdgeMatrix(matrix, 2, 4);

    printf("Adjacency Matrix:\n");
    printMatrix(matrix, vertices);

    return 0;
}
