// Задача 2.
// Быстрая сортировка

#include <iostream>

using namespace std;

void swap(int *arr, int il, int ir)
{
    int tmp{0};
    tmp = arr[il];
    arr[il] = arr[ir];
    arr[ir] = tmp;
}

int pivoting(int *arr, int pi, int il, int ir)
{
    int pivot = arr[pi];
    while (true)
    {
        while (arr[il] < pivot)
        {
            il++;
        }
        while (arr[ir] > pivot)
        {
            ir--;
        }
        if (il >= ir)
        {
            return ir;
        }
        swap(arr, il, ir);
        il++;
        ir--;
    }
}

void sort(int *arr, int left, int right)
{
    if (left == right)
    {
        return;
    }
    else
    {
        int piv = (left + right) / 2;
        int border = pivoting(arr, piv, left, right);
        sort(arr, left, border);
        sort(arr, border + 1, right);
    }
}

void quick_sort(int *arr, int size)
{
    sort(arr, 0, size - 1);
}

int main()
{
    // int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    // int arr[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    const int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Исходный массив: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    quick_sort(arr, size);
    cout << "Отсортированный массив: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}