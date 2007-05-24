#include <iostream>

#include "genscatter.h"
#include "field.h"

using namespace std;

template <typename Type>
struct Holder
{
    Type d_value;
};
    

int main()
{
    GenScatter<TYPELIST_2(int, double), Holder> gen2;

    field<0>(gen2) = 12;

    cout << field<0>(gen2) << endl;
}
