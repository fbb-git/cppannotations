#include <iostream>
#include "listsize.h"

int main()
{
    std::cout << ListSize<TYPELIST_3(int, char, bool)>::size << "\n";
}
