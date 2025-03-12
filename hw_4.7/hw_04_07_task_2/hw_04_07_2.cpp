// Задача 2*. Обход в ширину

#include <iostream>
#include <fstream>
#include <queue>

void graphTraversal(int **graph, int &vcount, int &number)
{
    bool visited[vcount]{false}; // будет запоминать посещение вершины
    std::queue<int> queueV;      // очередь для обхода вершин
    int elemQue;
    int vNum;
    for (int v = 0; v < vcount; v++)
    {
        vNum = (v + (number - 1)) % vcount; // определим номер вершины для обхода
        if (!visited[vNum])
        {
            queueV.push(vNum);
            visited[vNum] = true;
            while (!queueV.empty())
            {
                elemQue = queueV.front();
                std::cout << elemQue + 1 << " ";
                queueV.pop();
                for (int s = 0; s < vcount; s++)
                {
                    if (graph[elemQue][s] && !visited[s])
                    {
                        visited[s] = true;
                        queueV.push(s);
                    }
                }
            }
        }
    }
}

int main()
{
    int vertCount = 0;
    int vertNumber = 0;
    int rows = 0;
    int cols = 0;

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

        std::cout << "В графе " << vertCount << " вершин. ";
        std::cout << "Введите номер вершины, с которой начнётся обход: ";
        std::cin >> vertNumber;

        if (1 <= vertNumber && vertNumber <= vertCount)
        {
            graphTraversal(graph, vertCount, vertNumber); // запускаем обход графа по вершинам
        }
        else
        {
            std::cout << "Номер вершины указан неверно.";
        }

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
