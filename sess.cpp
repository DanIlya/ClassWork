#include <map>
#include <vector>

class SessionManager
{
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд,
    // считать его при этом нужно один раз.
    void login(string username)
    {
        Users[username] = 1;
    }

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд,
    // падать при этом не нужно.
    void logout(string username)
    {
        if (Users.count(username) > 0)
            Users[username] = 0;
    }

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers()
    {
        int N = 0;
        for (map<string, bool>::iterator it = Users.begin(); it != Users.end(); it++)
            {
                if (it->second == 1)
                    N++;
            }
        return N;
    }
protected:
    map<string, bool> Users;
};
