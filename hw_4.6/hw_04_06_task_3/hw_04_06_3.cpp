// Задача 3. Упрощённый алгоритм Рабина-Карпа

#include <iostream>
#include <string>

using namespace std;

u_int _hash(string str, u_int l)
{
    char ch{};
    u_int hash_sum{};

    for (u_int i = 0; i < l; ++i)
    {
        ch = str[i];
        hash_sum += static_cast<int>(ch);
    }
    return hash_sum;
}

int find_substring_light_rabin_karp(string s, string p)
{
    u_int n = s.length(); // длина текстовой строки s
    u_int k = p.length(); // длина шаблона p
    u_int p_hash{};       // хеш шаблона p
    int symbols_hash{};   // хеш символов

    p_hash = _hash(p, k);

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            symbols_hash = _hash(s, k);
        }
        else
        {
            symbols_hash -= static_cast<int>(s[i - 1]);
            symbols_hash += static_cast<int>(s[i + k - 1]);
        }
        if (symbols_hash != p_hash)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < k; ++j)
            {
                if (s[i + j] != p[j])
                {
                    continue;
                }
                else
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main()
{
    string str{};
    string substr{};
    int result{};

    cout << "Введите строку, в которой будет осуществляться поиск: ";
    cin >> str;

    while (substr != "exit")
    {
        cout << "Введите подстроку, которую нужно найти: ";
        cin >> substr;
        result = find_substring_light_rabin_karp(str, substr);
        if (result == -1)
        {
            cout << "Подстрока " << substr << " не найдена\n";
        }
        else
        {
            cout << "Подстрока " << substr << " найдена по индексу " << result;
            cout << endl;
        }
    }

    return 0;
}
