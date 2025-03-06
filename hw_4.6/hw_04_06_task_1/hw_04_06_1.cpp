// Задача 1. Наивная хэш-функция для строки

#include <iostream>
#include <string>

using namespace std;

int simple_string_hash(string string)
{
    int hash_sum{};
    char ch{};

    for (int i{0}; i < string.size(); ++i)
    {
        ch = string[i];
        hash_sum += static_cast<int>(ch);
    }

    return hash_sum;
}

int main()
{
    string value{};
    do
    {
        cout << "Введите строку: ";
        cin >> value;
        cout << "Наивный хэш строки " << value << " = " << simple_string_hash(value);
        cout << endl;
    } while (value != "exit");

    return 0;
}
