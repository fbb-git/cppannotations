#include <iostream>
#include <typeinfo>

#include "erase.h"
#include "typeat.h"

using namespace std;

int main()
{
//ERASE
    cout << Erase<int, TypeList<int, double, int>>::List::size << '\n' <<
            Erase<char, TypeList<int, double, int>>::List::size << '\n' <<
            Erase<int, TypeList<>>::List::size << "\n";
//=

//ERASEIDX
    if 
    (
        typeid(TypeAt<2, 
                EraseIdx<1, 
                   TypeList<int, char, size_t, double, int>>::List
                >::Type
        )
        == typeid(double)
    )
        cout << "the third type is now a double\n";
//=


//ERASEIDX
// <<
//        ListSize<
//            EraseDuplicates<
//                TYPELIST_5(int, double, int, double, int)
//            >::Result
//        >::size << "\n";
}
