// Задача 2. Добавление в изменяемый динамический массив

#include <iostream>

using namespace std;

int *append_to_dynamic_array(int *arr, int *logical_size, int *actual_size, int value)
{
    // если логический размер массива меньше фактического, то добавить новый элемент в
    // запас существующего массива и увеличить его логический размер на 1
    if (*logical_size < *actual_size)
    {
        arr[*logical_size] = value;
        (*logical_size)++;
        return arr;
    }
    else
    {
        *actual_size *= 2;
        int *new_arr = new int[*actual_size];
        // копируем данные в новый массив
        for (int i = 0; i < *actual_size; i++)
        {
            if (i < *logical_size)
            {
                new_arr[i] = arr[i];
            }
            else if (i == *logical_size)
            {
                new_arr[i] = value;
            }
            else
            {
                new_arr[i] = 0;
            }
        }
        (*logical_size)++;
        // удаляем старый массив
        delete[] arr;

        return new_arr;
    }
}

void print_dynamic_array(int *arr, int logical_size, int actual_size)
{
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
    int new_number{1};

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

        while (true)
        {
            cout << "Динамический массив: ";
            print_dynamic_array(user_arr, size_l, size_f);
            cout << "Введите элемент для добавления: ";
            cin >> new_number;
            if (!new_number)
                break;
            user_arr = append_to_dynamic_array(user_arr, &size_l, &size_f, new_number);
        }
        cout << "Спасибо! Ваш массив: ";
        print_dynamic_array(user_arr, size_l, size_f);

        delete[] user_arr;
        user_arr = nullptr;
    }
    catch (exception)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
    }

    return 0;
}