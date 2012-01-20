#include <iostream>

    template <typename Type1, typename Type2>
    class Wrapper;

    template <typename Type>
    class PtrVector
    {
        template <typename Type1, typename Type2>
        friend
            PtrVector<Type> Wrapper<Type1, Type2>::begin(Type1 const &t1, Type2 const &t2);

        void fun()
        {}

        double d_d;
    };
    using namespace std;

    int main(int argc, char **argv)
    {

    }
