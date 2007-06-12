#include <iostream>

#include "erase.h"
#include "listsize.h"

    // change Erase to EraseAll to erase all `int' types below
#define ERASE Erase

int main()
{
    std::cout <<
        ListSize<
            ERASE<TYPELIST_3(int, double, int), int>::Result
        >::size << "\n" <<
        ListSize<
            EraseDuplicates<
                TYPELIST_5(int, double, int, double, int)
            >::Result
        >::size << "\n";
}
