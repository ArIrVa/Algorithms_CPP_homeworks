// Задача 3*. Удаление первого элемента из изменяемого динамического массива

#include <iostream>

using namespace std;

class ErrorArrDelItem : public exception
{
public:
    const char *what() const noexcept override { return "Невозможно удалить первый элемент, так как массив пустой. До свидания!"; };
};

int *remove_dynamic_array_head(int *arr, int *logical_size, int *actual_size)
{
    int size_third{0};
    int size_logical{0};

    size_logical = (*logical_size) - 1;
    if (size_logical > 0)
    {
        size_third = static_cast<int>((*actual_size) * 1 / 3.0);
    }
    else
    {
        size_third = 1;
    }

    if (size_logical > size_third)
    {
        // сдвигаем массив на 1 эл. влево
        for (int i = 0; i < *logical_size; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[(*logical_size) - 1] = 0;
        (*logical_size)--;
        return arr;
    }
    else
    {
        *actual_size = size_third;
        int *new_arr = new int[size_third];
        // копируем данные в новый массив
        for (int i = 0; i < size_logical; i++)
        {
            new_arr[i] = arr[i + 1];
        }
        arr[size_logical] = 0;
        (*logical_size)--;
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
    std::string ans = "да";

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
            cout << "Удалить первый элемент? ";
            cin >> ans;
            if (ans != "да")
                break;
            if (size_l > 0)
            {
                user_arr = remove_dynamic_array_head(user_arr, &size_l, &size_f);
            }
            else
            {
                throw ErrorArrDelItem();
            }
        }
        cout << "Спасибо! Ваш динамический массив: ";
        print_dynamic_array(user_arr, size_l, size_f);

        delete[] user_arr;
        user_arr = nullptr;
    }

    catch (ErrorArrDelItem &er)
    {
        cout << er.what() << endl;
    }
    catch (exception &er)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
    }

    return 0;
}