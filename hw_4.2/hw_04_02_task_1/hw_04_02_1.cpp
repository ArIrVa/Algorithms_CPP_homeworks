// Задача 1. Снова числа Фибоначчи

#include <iostream>

using namespace std;

size_t fibo(size_t n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
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