//
// Created by pastu on 04.06.2022.
//

#include "dfs.h"
#include <stdlib.h>

bool DFS_recursive(Graph* graph, bool* visited, int currentNode, int iteration, bool wasRedVertex)
{
    if (graph->isRed[currentNode] && wasRedVertex)
    {
        return true;
    }
    graph->iteration[currentNode] = iteration;
    visited[currentNode] = true;
    Node* neighbours = Graph_GetNeighbours(graph, currentNode);

    while (neighbours != NULL)
    {
        if (!visited[neighbours->number])
        {
            if (DFS_recursive(graph, visited, neighbours->number, iteration + 1, wasRedVertex | graph->isRed[currentNode]))
            {
                return true;
            }
        }
        neighbours = neighbours->next;
    }
    return false;
}

bool DFS(Graph* graph, int startingNode)
{
    bool* visited = calloc( graph->verticesNo, sizeof(bool) );

    return DFS_recursive(graph, visited, startingNode, 0, false);
}
