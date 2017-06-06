#include <utility>
#include <iostream>
using namespace std;

struct Class
{
    Class() = default;
    Class(Class &&tmp);
    Class(Class const &other);
    Class &operator=(Class &&tmp);
    Class &operator=(Class const &other);
};

Class::Class(Class &&tmp)
{
    cout << "Move CC\n";
}

Class::Class(Class const &other)
{
    cout << "Copy cons\n";
}

Class &Class::operator=(Class &&tmp)
{
    cout << "Move assignemnt\n";
    return *this;
}

Class &Class::operator=(Class const &other)
{
    cout << "Overloaded assignment\n";
    Class tmp{ other };
    return *this = std::move(tmp);
}


int main()
{
    Class a;
    Class b;

    a = b;
}
