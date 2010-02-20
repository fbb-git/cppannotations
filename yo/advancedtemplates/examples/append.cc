#include <iostream>
#include "append.h"

int main()
{
    std::cout <<
        Append<TypeList<int>, int>::List::size << '\n' <<
        Prefix<char, TypeList<>>::List::size << '\n';
}
