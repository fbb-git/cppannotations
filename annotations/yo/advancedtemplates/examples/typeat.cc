#include <iostream>
#include <typeinfo>

#include "typeat.h"

using namespace std;

int main()
{
//EXAMPLE
    typedef TypeList<int, char, bool> list3;

//    TypeAt<3, list3>::Type invalid;
    TypeAt<0, list3>::Type intVariable = 13;
    TypeAt<2, list3>::Type boolVariable = true;

    cout << "The size of the first type is " <<
                sizeof(TypeAt<0, list3>::Type) << ", "
            "the size of the third type is " <<
                sizeof(TypeAt<2, list3>::Type) << "\n";

    if (typeid(TypeAt<1, list3>::Type) == typeid(char))
        cout << "The typelist's 2nd type is char\n";

    if (typeid(TypeAt<2, list3>::Type) != typeid(char))
        cout << "The typelist's 3nd type is not char\n";
//=
}
