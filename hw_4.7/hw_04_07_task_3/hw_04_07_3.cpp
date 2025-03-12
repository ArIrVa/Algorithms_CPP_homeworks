// Задача 3*. Поиск циклов

#include <iostream>
#include <fstream>

void VisitedVertex(int **graph, int &vcount, int &vertex, bool *visited, bool &isCycle, int prev = 0)
{ // отметить вершину, перейти к смежной вершине
    if (!visited[vertex])
    {
        visited[vertex] = 1;
    }

    for (int s = 0; s < vcount; s++)
    {
        if (isCycle)
            break; // завершить все переборы, если поймали цикл
        if (graph[vertex][s])
        {
            if (!visited[s])
            {
                VisitedVertex(graph, vcount, s, visited, isCycle, vertex);
            }
            else if (s != prev)
            {
                isCycle = true;
                break;
            }
        }
    }
}

bool isCyclicGraph(int **graph, int &vcount)
{                                // обход всего графа
    bool visited[vcount]{false}; // будет запоминать посещение вершины
    bool isCycle = false;
    if (vcount > 2)
    {
        for (int v = 0; v < vcount; v++)
        {
            if (isCycle)
                break;
            if (!visited[v])
            {
                VisitedVertex(graph, vcount, v, visited, isCycle);
            }
        }
        return isCycle;
    }
    else
    {
        return isCycle;
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

        if (isCyclicGraph(graph, vertCount))
        {
            std::cout << "В графе есть цикл!" << std::endl;
        }
        else
        {
            std::cout << "В графе нет циклов" << std::endl;
        }

        // - > чистим память
        for (int i = 0; i < rows; i++)
        {
            delete[] graph[i];
        }
        delete[] graph;
        // < - чистим память
    }
    else
    {
        std::cout << "Не удалось открыть файл!" << std::endl;
    }
    fin.close(); // закрываем файл
    return 0;
}
