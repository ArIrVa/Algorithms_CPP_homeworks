// Задача 4*. Поиск компонентов связности

#include <iostream>
#include <fstream>

void vertexComponents(int **graph, int &vcount, int &vertex, int *cids, int cid)
{ // отметить компоненту связности для вершины, перейти к смежной вершине и повторить
    cids[vertex] = cid;

    for (int s = 0; s < vcount; s++)
    {
        if (graph[vertex][s] && !cids[s])
        {
            vertexComponents(graph, vcount, s, cids, cid);
        }
    }
}

int graphComponents(int **graph, int &vcount)
{                           // обход всего графа
    int compids[vcount]{0}; // будем хранить номера компонентов связности для каждой вершины
    int compid = 1;         // зададим начальный номер компонеты связности

    for (int v = 0; v < vcount; v++)
    {
        if (!compids[v])
        {
            vertexComponents(graph, vcount, v, compids, compid);
            compid += 1;
        }
        std::cout << v + 1 << " - " << compids[v] << std::endl; //
    }
    return compid - 1;
}

int main()
{
    int vertCount;
    int rows;
    int cols;
    int compCount;

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

        std::cout << "Принадлежность вершин компонентам связности:" << std::endl;
        compCount = graphComponents(graph, vertCount); // запускаем обход графа по вершинам
        std::cout << "Количество компонентов связности в графе: " << compCount << std::endl;

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
