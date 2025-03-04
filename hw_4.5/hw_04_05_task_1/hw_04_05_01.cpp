// Задача 1. Вывод пирамиды на массиве

#include <iostream>

using namespace std;

int parent_index(int child_index)
{
    return (child_index - 1) / 2;
}

int left_index(int parent_index)
{
    return 2 * parent_index + 1;
}

int right_index(int parent_index)
{
    return 2 * parent_index + 2;
}

int level(int index)
{
    if (!index)
    {
        return 0;
    }
    else
    {
        return level(parent_index(index)) + 1;
    }
}

void print_str(int level, int parent, int child, bool left)
{
    if (!level)
    {
        cout << level << " root " << parent << endl;
    }
    else if (left)
    {
        cout << level << " left (" << parent << ") " << child << endl;
    }
    else
    {
        cout << level << " right (" << parent << ") " << child << endl;
    }
}

void print_pyramid(int *arr, int &size)
{
    bool left{true};
    for (int i = 0; i < size; i++)
    {
        if (i % 2)
        {
            left = true;
        }
        else
        {
            left = false;
        }
        print_str(level(i), arr[parent_index(i)], arr[i], left);
    }
};

int main()
{

    int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Пирамида:" << endl;
    print_pyramid(arr, size);

    return 0;
}