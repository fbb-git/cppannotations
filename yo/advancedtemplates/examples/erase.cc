#include <iostream>
#include <typeinfo>

#include "erase.h"
#include "typeat.h"

using namespace std;

int main()
{
//ERASE
    cout << 
            Erase<int, TypeList<char, double, int>>::List::size << '\n' <<
            Erase<char, TypeList<int>>::List::size << '\n' <<
            Erase<int, TypeList<int>>::List::size << '\n' <<
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

//ERASEALL
    cout << 
        "After erasing size_t from "
            "TypeList<char, int, size_t, double, size_t>\n"
            "it contains " << 
                EraseAll<size_t, 
                         TypeList<char, int, size_t, double, size_t>
                >::List::size << " types\n";
//=

//ERASEDUP
    cout << 
        "After erasing duplicates from " 
             "TypeList<double, char, int, size_t, int, double, size_t>\n"
        "it contains " << 
        EraseDup<
            TypeList<double, char, int, size_t, int, double, size_t>
        >::List::size << " types\n";
//=

}




