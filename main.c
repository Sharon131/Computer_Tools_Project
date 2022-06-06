#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "dfs.h"

#define MAX_LINE_LENGTH     8

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
    int R = _GetSingleParameter(file);
    printf("Number of vertices read: %d\r\n", V);
    printf("Number of edges read: %d\r\n", E);
    printf("Number of red vertices: %d\r\n", R);

    Graph graph;
    Graph_Initialise(&graph, V);

    char buffer[MAX_LINE_LENGTH];
    /* Get red vertices */
    for (int i=0;i<R;i++)
    {
        if (!fgets(buffer, MAX_LINE_LENGTH, file))
        {
            printf("");
            exit(5);
        }

        int v = atoi(buffer) - 1;
        Graph_MarkVertexAsRed(&graph, v);
    }

    bool red1 = graph.isRed[1];
    bool red2 = graph.isRed[4];
    bool red3 = graph.isRed[7];
    printf("Red vertices read\r\n");

    for (int i=0;i<E;i++)
    {
        memset(buffer, 0, MAX_LINE_LENGTH);
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

    if (DFS(&graph, 0))
    {
        printf("Given tree contains more than one red vertex on the same path. Unfortunately\r\n");
    }
    else
    {
        printf("Given tree does not contain more than one red vertex on the same path. Success!\r\n");
    }

    Graph_Print(&graph);

    return 0;
}
