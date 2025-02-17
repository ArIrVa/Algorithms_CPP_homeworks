// Задача 2. Поиск в массиве
// Вывести количество элементов в массиве, которые больше, чем переданное целое число

#include <iostream>

using namespace std;

int count_elem(int *arr, int size, int val)
{

    int count{0};
    int left{0}, right{size - 1};
    int midle = (left + right) / 2;
    while (left < right)
    {
        if (val < arr[midle])
        {
            right = midle;
        }
        else
        {
            left = midle + 1;
        }
        midle = (left + right) / 2;
    }
    return size - left;
}

int main()
{
    const int size{9};
    int arr_base[size] = {14, 16, 19, 32, 32, 32, 56, 69, 72}; // заданный отсортированный массив
    int user_val{}, result{};
    cout << "Введите точку отсчёта: ";
    cin >> user_val;
    result = count_elem(arr_base, size, user_val);
    cout << "Количество элементов в массиве больших, чем " << user_val << ": " << result << endl;

    return 0;
}
