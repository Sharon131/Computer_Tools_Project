//
// Created by pastu on 04.06.2022.
//

#include "dfs.h"
#include <stdlib.h>

void DFS_recursive(Graph* graph, bool* visited, int currentNode, int iteration)
{
    graph->iteration[currentNode] = iteration;
    visited[currentNode] = true;
    Node* neighbours = Graph_GetNeighbours(graph, currentNode);

    while (neighbours != NULL)
    {
        if (!visited[neighbours->number])
        {
            DFS_recursive(graph, visited, neighbours->number, iteration + 1);
        }
        neighbours = neighbours->next;
    }
}

void DFS(Graph* graph, int startingNode)
{
    bool* visited = calloc( graph->verticesNo, sizeof(bool) );

    DFS_recursive(graph, visited, startingNode, 0);
}
