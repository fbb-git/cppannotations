#include <iostream>

using namespace std;

class Class
{
    public:
    Class()
    {};
    void fun(Class const &other)
    {
        cout << "fun: Class const &\n";
        gun(other);
    }
    void fun(Class &other)
    {
        cout << "fun: Class &\n";
        gun(other);
    }
    void fun(Class &&tmp)
    {
        cout << "fun: Class &&\n";
        gun(tmp);
    }
    void gun(Class const &other)
    {
        cout << "gun: Class const &\n";
    }
    void gun(Class &other)
    {
        cout << "gun: Class &\n";
    }
    void gun(Class &&tmp)
    {
        cout << "gun: Class &&\n";
    }
};

int main()
{
    Class c1;

    c1.fun(c1);
    c1.fun(Class());

    Class const c0;
    c1.fun(c0);
}
