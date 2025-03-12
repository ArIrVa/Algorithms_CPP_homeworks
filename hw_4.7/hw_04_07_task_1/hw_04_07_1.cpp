// Задача 1. Обход в глубину

#include <iostream>
#include <fstream>

void vertexTraversal(int **graph, int &vcount, int &vertex, int *visited)
{ // отметить вершину, перейти к смежной вершине
    std::cout << vertex + 1 << " ";
    visited[vertex] = 1;

    for (int s = 0; s < vcount; s++)
    {
        if (graph[vertex][s] && !visited[s])
        {
            vertexTraversal(graph, vcount, s, visited);
        }
    }
}

void graphTraversal(int **graph, int &vcount)
{                           // обход всего графа
    int visited[vcount]{0}; // будет запоминать посещение вершины
    for (int v = 0; v < vcount; v++)
    {
        if (!visited[v])
        {
            vertexTraversal(graph, vcount, v, visited);
        }
    }
}

int main()
{
    int vertCount;
    int rows;
    int cols;

    std::ifstream fin("input.txt"); // открываем файл на чтение

    if (fin.is_open())
    {
        fin >> vertCount;
        rows = cols = vertCount;

        int **graph = new int *[vertCount];

        for (int i = 0; i < rows; i++)
        {
            graph[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                fin >> graph[i][j];
            }
        }

        graphTraversal(graph, vertCount); // запускаем обход графа по вершинам
        std::cout << std::endl;

        for (int i = 0; i < rows; i++)
        {
            delete[] graph[i];
        }

        delete[] graph;
    }
    else
    {
        std::cout << "Не удалось открыть файл!" << std::endl;
    }

    fin.close(); // закрываем файл
    return 0;
}
