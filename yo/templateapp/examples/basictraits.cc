#include <iostream>

#include "basictraits.h"

using namespace std;

int main()
{
//MAIN
    cout << BasicTraits<int>::isPointerType << " " <<
            BasicTraits<int *>::isPointerType << " " <<
            BasicTraits<int>::isConst << " " <<
            BasicTraits<int>::isReferenceType << " " <<
            BasicTraits<int &>::isReferenceType << " " <<
            BasicTraits<int const>::isConst << " " <<
            BasicTraits<int const *>::isPointerType << " " <<
            BasicTraits<int const *>::isConst << " " <<
            endl;

    BasicTraits<int *>::ValueType value = 12;
    int *otherValue = &value;
    cout << *otherValue << endl;
//=
}

