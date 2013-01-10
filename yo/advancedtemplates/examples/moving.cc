#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

class Foreign
{
    public:
        Foreign() = default;
        Foreign(string const &) noexcept
        {}

        Foreign(Foreign const &other) noexcept
        {
            throw 1;
        }
};

class String
{
    public:
        String() = default;
        String(String &&tmp)
        {}
};

template <typename Type>
class MyClass
{
    Type d_f;
    public:
        MyClass() = default;
        MyClass(MyClass &&tmp)
        :
            d_f(move(tmp.d_f))
        {}
};

int main()
try
{
    cout << "TRAIT: " << is_nothrow_copy_constructible<Foreign>::value << '\n';
    MyClass<String> s1(move(MyClass<String>()));
    MyClass<Foreign> s2(move(MyClass<Foreign>()));
}
catch (...)
{
    cout << "Exception\n";
}
