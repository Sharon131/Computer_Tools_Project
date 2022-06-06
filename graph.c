//
// Created by pastu on 04.06.2022.
//

#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void Graph_Initialise(Graph* graph, int verticesNo)
{
    graph->verticesNo = verticesNo;
    graph->adjacencyList = calloc( verticesNo, sizeof(Node*) );
    graph->isRed = calloc( verticesNo, sizeof(bool) );
    graph->iteration = calloc( verticesNo, sizeof(int) );
}

void Graph_MarkVertexAsRed(Graph* graph, int v)
{
    graph->isRed[v] = true;
}

void Graph_AddEdge(Graph* graph, int v1, int v2)
{
    if (graph->adjacencyList[v1] == NULL){
        graph->adjacencyList[v1] = calloc(1, sizeof(Node));
        graph->adjacencyList[v1]->number = v2;
        graph->adjacencyList[v1]->next = NULL;
    }
    else
    {
        Node* neighbour = graph->adjacencyList[v1];
        while( neighbour->next != NULL)
        {
            neighbour = neighbour->next;
        }

        neighbour->next = calloc(1, sizeof(Node));
        neighbour->next->next = NULL;
        neighbour->next->number = v2;
    }
}

Node* Graph_GetNeighbours(Graph* graph, int v)
{
    return graph->adjacencyList[v];
}

void Graph_Print(Graph* graph)
{
    for(int i=0;i<graph->verticesNo;i++)
    {
        printf("Vertex: %d, iter: %d\r\n", i + 1, graph->iteration[i]);

        Node* node = graph->adjacencyList[i];

        while(node != NULL)
        {
            printf("\t%d", node->number + 1);
            node = node->next;
        }
        printf("\r\n");
    }
}

void Graph_Free(Graph* graph)
{
    for (int i=0;i<graph->verticesNo;i++)
    {
        Node* node = graph->adjacencyList[i];
        while (node != NULL)
        {
            Node* next = node->next;
            free(node);
            node = next;
        }
    }


    free(graph->adjacencyList);
}
