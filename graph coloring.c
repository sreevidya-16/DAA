#include <stdio.h>
#include <stdbool.h>

#define V 4
int i;
void printSolution(int color[])
{
    printf("Vertex colors:\n");
    for ( i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for ( i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
int c;
    if (v == V)
        return true;

    for ( c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
    int color[V];

    for ( i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(color);
    return true;
}

int main()
{
    bool graph[V][V] = {{1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1}};

    int m = 3;

    graphColoring(graph, m);

    return 0;
}

