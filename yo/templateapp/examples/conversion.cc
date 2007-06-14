#include <iostream>
#include <fstream>
#include <string>
#include "conversion.h"

using namespace std;

int main()
{
//CONVERSION
    cout <<
        Conversion<ofstream, ostream>::exists << " " <<
        Conversion<ostream, ofstream>::exists << " " <<
        Conversion<int, double>::exists << " " <<
        Conversion<int, string>::exists << " " <<
        endl;
//=

    cout << "\n" <<
        Conversion<int, int>::sameType << " " <<
        Conversion<int, string>::sameType << " " <<
        endl;

//INHERITANCE
    cout << "\n" <<
        "1: " << BASE_1st_DERIVED_2nd(ofstream, ostream) << ",  " <<
        "2: " << BASE_1st_DERIVED_2nd(ostream, ofstream) << ",  " <<
        "3: " << BASE_1st_DERIVED_2nd(void, ofstream) << ",  " <<
        "4: " << BASE_1st_DERIVED_2nd(ostream, ostream) << ",  " <<
        "5: " << BASE_1st_DERIVED_2nd_STRICT(ostream, ostream) << " " <<
        endl;
//=
}
