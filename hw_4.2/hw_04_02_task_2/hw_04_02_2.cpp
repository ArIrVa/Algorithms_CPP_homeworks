// Задача 2. Ускоряем Фибоначчи

#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long> arr_fibo = {0, 1};

size_t fibo(size_t n)
{
    if (n < 2)
    {
        return n;
    }
    else if (arr_fibo.size() > n)
    {
        return arr_fibo[n];
    }
    else
    {
        arr_fibo.push_back(fibo(n - 1) + fibo(n - 2));
        return arr_fibo[arr_fibo.size() - 1];
    }
}

int main()
{
    size_t num{};
    cout << "Введите номер числа: ";
    cin >> num;
    cout << "Число Фибоначчи: " << to_string(fibo(num)) << '\n';

    return 0;
}