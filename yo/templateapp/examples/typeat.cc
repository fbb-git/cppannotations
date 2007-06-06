#include <iostream>
#include "typeat.h"
#include "listsearch.h"

// compile with, e.g., -DIDX=3, specify another number to test another index
// value 

int main()
{
    typedef TYPELIST_3(int, char, bool) list3;

    std::cout << 
        (ListSearch<TypeAt<IDX, list3>::result, list3>::index == -1 ?
            "Illegal Index\n"
        :
            "Index represents a valid type\n");
}
