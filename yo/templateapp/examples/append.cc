#include <iostream>
#include "append.h"
#include "listsize.h"

int main()
{
    std::cout << 
        ListSize<Append<NullType, NullType>::Result>::size << "\n" <<
        ListSize<Append<NullType, int>::Result>::size << "\n" <<
        ListSize<Append<TYPELIST_1(int), NullType>::Result>::size << "\n" <<
        ListSize<Append<TYPELIST_1(int), int>::Result>::size << "\n";
}
