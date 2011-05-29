#include <algorithm>
#include <string>

/*
class MyClass
{
    public:
        typedef int value_type;         // value_type MUST be defined

        void push_back(value_type i)    // int or value_type: both ok
        {
            cerr << "Inserting " << i << '\n';
        }
};
*/

template <typename Type>
class MyClass
{
    public:
        typedef Type value_type;         // value_type MUST be defined

        void push_back(value_type const & i)    // int or value_type: both ok
        {
            cerr << "Inserting " << i << '\n';
        }
};

int main(int argc, char **argv)
{
    int
        x [] = {1, 2, 4, 8, 16};

    MyClass<int>
        mc;

    copy(x, x + 5, back_inserter(mc));

    string
        s [] = {"opa", "en", "oma", "op", "de", "bank"};

    MyClass<string>
        ms;

    copy(s, s + sizeof(s) / sizeof(string), back_inserter(ms));
}
