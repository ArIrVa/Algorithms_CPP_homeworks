// Задача 2. Настоящая хэш-функция для строки

#include <iostream>
#include <string>

using namespace std;

int real_string_hash(int *ptr_p, int *ptr_n, string s)
{
    int hash_sum=s[0];
    int p_power = *ptr_p;

    for (int i = 1; i < s.size(); ++i)
    {
        hash_sum += static_cast<int>(s[i]) * p_power;
        p_power = p_power * (*ptr_p);
       
    }
    return hash_sum % *ptr_n;
}

int main()
{
    int p{};
    int n{};
    int *ptr_p = &p;
    int *ptr_n = &n;
    string string{};

    cout << "Введите p: ";
    cin >> p;
    cout << "Введите n: ";
    cin >> n;

    while (string != "exit")
    {
        cout << "Введите строку: ";
        cin >> string;
        cout << "Хэш строки " << string << " = " << real_string_hash(ptr_p, ptr_n, string);
        cout << endl;
    }

    return 0;
}

// hash(s)=s[0]+P×s[1]+P^2×s[2]+...+P^[длина(s)-1)]×s^[длина(s)-1]

