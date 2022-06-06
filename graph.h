//
// Created by pastu on 04.06.2022.
//

#ifndef PROJEKT2_GRAPH_H
#define PROJEKT2_GRAPH_H

#include <stdbool.h>

typedef struct node {
    struct node* next;
    int number;
} Node;

typedef struct graph {
    Node** adjacencyList;
    int verticesNo;
    int* iteration;
} Graph;

void Graph_Initialise(Graph* graph, int verticesNo);
void Graph_AddEdge(Graph* graph, int v1, int v2);
Node* Graph_GetNeighbours(Graph* graph, int v);
void Graph_Print(Graph* graph);
void Graph_Free(Graph* graph);

#endif //PROJEKT2_GRAPH_H
