// Задача 1. Вывод изменяемого динамического массива

#include <iostream>

using namespace std;

void print_dynamic_array(int *arr, int logical_size, int actual_size)
{
    cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size)
        {
            cout << arr[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main()
{
    int size_f{0};
    int size_l{0};

    try
    {
        cout << "Введите фактичеcкий размер массива: ";
        cin >> size_f;
        cout << "Введите логический размер массива: ";
        cin >> size_l;

        if (size_l > size_f)
        {
            throw exception();
        }

        int *user_arr = new int[size_f];

        for (int i = 0; i < size_l; i++)
        {
            cout << "Введите arr[" << i << "]: ";
            cin >> user_arr[i];
        }

        print_dynamic_array(user_arr, size_l, size_f);
        delete[] user_arr;
    }
    catch (exception)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
    }

    return 0;
}