// Задача 2. «Путешествие» по пирамиде

#include <iostream>
#include <vector>

using namespace std;

enum class Command
{
    up,
    left,
    right,
    exit
};

vector<string> com_list = {"up", "left", "right", "exit"};

class ErrMoveUp : public exception
{
public:
    const char *what() const noexcept override { return "Отсутствует родитель"; };
};

class ErrMoveRight : public exception
{
public:
    const char *what() const noexcept override { return "Отсутствует правый потомок"; };
};

class ErrMoveLeft : public exception
{
public:
    const char *what() const noexcept override { return "Отсутствует левый потомок"; };
};

int parent_index(int child_index)
{
    return (child_index - 1) / 2;
}

int left_index(int parent_index)
{
    return 2 * parent_index + 1;
}

int right_index(int parent_index)
{
    return 2 * parent_index + 2;
}

int level(int index)
{
    if (!index)
    {
        return 0;
    }
    else
    {
        return level(parent_index(index)) + 1;
    }
}

void print_str(int level, int parent, int child, bool left)
{
    if (!level)
    {
        cout << level << " root " << parent << endl;
    }
    else if (left)
    {
        cout << level << " left (" << parent << ") " << child << endl;
    }
    else
    {
        cout << level << " right (" << parent << ") " << child << endl;
    }
}

void move(int *arr, int &size, int &i, int &move_index, int &parent, int &child, bool &left, Command command)
{
    try
    {
        switch (command)
        {
        case Command::up:
            if (!i)
            {
                throw ErrMoveUp();
            }
            else
            {
                move_index = parent_index(i);
                parent = arr[parent_index(move_index)];
                child = arr[move_index];
                left = static_cast<bool>(move_index % 2);
            };
            break;
        case Command::left:
            if (left_index(i) >= size)
            {
                throw ErrMoveLeft();
            }
            else
            {
                move_index = left_index(i);
                parent = arr[i];
                child = arr[move_index];
                left = true;
            };
            break;
        case Command::right:
            if (right_index(i) >= size)
            {
                throw ErrMoveRight();
            }
            else
            {
                move_index = right_index(i);
                parent = arr[i];
                child = arr[move_index];
                left = false;
            };
            break;
        default:
            break;
        }
        i = move_index;
        cout << "Ок" << endl;
    }
    catch (ErrMoveUp &err)
    {
        cout << "Ошибка! " << err.what() << endl;
    }
    catch (ErrMoveRight &err)
    {
        cout << "Ошибка! " << err.what() << endl;
    }
    catch (ErrMoveLeft &err)
    {
        cout << "Ошибка! " << err.what() << endl;
    }
}

void print_pyramid(int *arr, int &size)
{
    bool left{true};
    for (int i = 0; i < size; i++)
    {
        if (i % 2)
        {
            left = true;
        }
        else
        {
            left = false;
        }
        print_str(level(i), arr[parent_index(i)], arr[i], left);
    }
}

bool isCommand(string com)
{
    bool result{false};
    for (int i = 0; i < com_list.size(); i++)
    {
        if (com == com_list[i])
        {
            result = true;
            break;
        }
    }
    return result;
}

Command getCommand(string com)
{
    Command result{Command::exit};
    for (int i = 0; i < com_list.size(); i++)
    {
        if (com == com_list[i])
        {
            result = static_cast<Command>(i);
            break;
        }
    }
    return result;
}

int main()
{

    string ans;  // ответ пользователя
    Command com; // команда
    int index{0}, move_index{0}, parent{0}, child{0};
    bool left{false};

    // int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    // int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};

    int arr[] = {1, 3, 6, 5, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Пирамида:" << endl;
    print_pyramid(arr, size);

    cout << "Вы находитесь здесь: ";
    print_str(level(0), arr[0], arr[0], false);

    while (true)
    {
        cout << "Введите команду: ";
        cin >> ans;
        if (isCommand(ans))
        {
            com = getCommand(ans);
            if (com == Command::exit)
            {
                break;
            }
            else
            {
                move(arr, size, index, move_index, parent, child, left, com);
                cout << "Вы находитесь здесь: ";
                print_str(level(move_index), parent, child, left);
            }
        }
        else
        {
            cout << "Неверная команда. Попробуйте снова." << endl;
        }
    }
    return 0;
}