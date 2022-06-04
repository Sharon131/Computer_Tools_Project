#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

#define MAX_LINE_LENGTH     8


void DFS_recursive()
{

}

void DFS()
{

}

int _GetSingleParameter(FILE* file)
{
    char buffer[MAX_LINE_LENGTH];
    if (!fgets(buffer, MAX_LINE_LENGTH, file))
    {
        printf("Empty file\r\n");
        exit(3);
    }

    char *p = strtok(buffer, " ");
    p = strtok(NULL, " ");

    return atoi(p);
}

int main(int argc, char* argv[]) {

    if (argc < 2)
    {
        printf("File containing graph was not given\r\n");
        return 1;
    }

    printf("Opening file: %s\r\n", argv[1]);

    FILE* file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Opening file did not succeed. Exiting\r\n");
        return 2;
    }


    int V = _GetSingleParameter(file);
    int E = _GetSingleParameter(file);
    printf("Number of vertices read: %d\r\n", V);
    printf("Number of edges read: %d\r\n", E);

    Graph graph;
    Graph_Initialise(&graph, V);

    char buffer[MAX_LINE_LENGTH];
    for (int i=0;i<E;i++)
    {
        if (fgets(buffer, MAX_LINE_LENGTH, file))
        {
            char *p = strtok(buffer, " ");
            int v1 = atoi(p) - 1;
            p = strtok(NULL, " ");
            int v2 = atoi(p) - 1;
            Graph_AddEdge(&graph, v1, v2);
            Graph_AddEdge(&graph, v2, v1);
        }
        else
        {
            printf("Number of edges in file is lesser that declared\r\n");
            exit(4);
        }
    }

    fclose(file);

    Graph_Print(&graph);

    // perform algorithm



    return 0;
}
