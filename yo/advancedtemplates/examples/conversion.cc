#include <iostream>
#include <fstream>
#include <string>
#include "conversion.h"

using namespace std;

int main()
{
//CONVERSION
    cout <<
        LconvertibleToR<ofstream, ostream>::yes << " " <<
        LconvertibleToR<ostream, ofstream>::yes << " " <<
        LconvertibleToR<int, double>::yes << " " <<
        LconvertibleToR<int, string>::yes <<
        "\n";
//=

    cout << "\n" <<
        LconvertibleToR<int, int>::sameType << " " <<
        LconvertibleToR<int, string>::sameType <<
        "\n";

//INHERITANCE
    cout << "\n" <<
        "1: " << LBaseRDerived<ofstream, ostream>::yes << ",  " <<
        "2: " << LBaseRDerived<ostream, ofstream>::yes << ",  " <<
        "3: " << LBaseRDerived<void, ofstream>::yes << ",  " <<
        "4: " << LBaseRDerived<ostream, ostream>::yes << ",  " <<
        "5: " << LBaseRtrulyDerived<ostream, ostream>::yes <<
        "\n";
//=
}
