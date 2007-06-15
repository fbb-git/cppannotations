#include <iostream>
#include "append.h"
#include "listsize.h"

int main()
{
    std::cout <<
        ListSize<Append<NullType, NullType>::TList>::size << "\n" <<
        ListSize<Append<NullType, int>::TList>::size << "\n" <<
        ListSize<Append<TYPELIST_1(int), NullType>::TList>::size << "\n" <<
        ListSize<Append<TYPELIST_1(int), int>::TList>::size << "\n";
}
