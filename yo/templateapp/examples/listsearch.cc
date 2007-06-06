#include <iostream>
#include "listsearch.h"

int main()
{
    std::cout << 
        ListSearch<char, TYPELIST_3(int, char, bool)>::index << "\n" <<
        ListSearch<float, TYPELIST_3(int, char, bool)>::index << "\n";
}

