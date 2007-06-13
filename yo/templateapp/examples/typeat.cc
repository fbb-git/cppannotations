#include <iostream>
#include "typeat.h"
#include "listsearch.h"

// compile with, e.g., -DIDX=3, specify another number to test another index
// value 

#ifndef IDX
#define IDX 2
#endif

int main()
{
    typedef TYPELIST_3(int, char, bool) list3;

    if (ListSearch<TypeAt<IDX, list3>::Type, list3>::index == -1)
        std::cout << "Index " << IDX << 
                     " is *not* a valid index in TYPELIST_3\n";
    else
        std::cout << "Index " << IDX << 
                     " is a valid index in TYPELIST_3\n";
}



