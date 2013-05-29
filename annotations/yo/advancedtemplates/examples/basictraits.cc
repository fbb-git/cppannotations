#include <iostream>

#include "basictraits.h"

using namespace std;

int main()
{
//MAIN
     cout <<
      "int: plain type? "     << BasicTraits<int>::isPlainType << "\n"
      "int: ptr? "            << BasicTraits<int>::isPointerType << "\n"
      "int: const? "          << BasicTraits<int>::isConst << "\n"
      "int *: ptr? "          << BasicTraits<int *>::isPointerType << "\n"
      "int const *: ptr? "    << BasicTraits<int const *>::isPointerType <<
                                                                      "\n"
      "int const: const? "    << BasicTraits<int const>::isConst << "\n"
      "int: reference? "      << BasicTraits<int>::isReferenceType << "\n"
      "int &: reference? "    << BasicTraits<int &>::isReferenceType << "\n"
      "int const &: ref ? "   << BasicTraits<int const &>::isReferenceType <<
                                                                        "\n"
      "int const &: const ? " << BasicTraits<int const &>::isConst << "\n"
      "int &&: r-reference? " << BasicTraits<int &&>::isRvalueReferenceType <<
                                                                        "\n"
      "int &&: const? " << BasicTraits<int &&>::isConst << "\n"
      "int const &&: r-ref ? "<< BasicTraits<int const &&>::
                                                isRvalueReferenceType << "\n"
      "int const &&: const ? "<< BasicTraits<int const &&>::isConst << "\n"
        "\n";

     BasicTraits<int *>::ValueType           value = 12;
     BasicTraits<int const *>::RvalueRefType rvalue = int(10);
     BasicTraits<int const &&>::PtrType      ptr = new int(14);
     cout << value << ' ' << rvalue << ' ' << *ptr << '\n';
//=
}
