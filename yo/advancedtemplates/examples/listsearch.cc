#include <iostream>
#include "listsearch.h"

int main()
{
//EXAMPLE
    std::cout <<
        ListSearch<char, TypeList<int, char, bool>>::index << "\n" <<
        ListSearch<float, TypeList<int, char, bool>>::index << "\n";
//=
}
