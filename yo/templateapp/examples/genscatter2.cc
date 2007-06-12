#include <iostream>
#include <string>

#include "genscatter.h"


template <typename Type>
struct Holder
{
    Type d_value;

    Holder(Type v = Type())
    :
        d_value(v)
    {}
};

    
struct Object: public GenScat<TYPELIST_3(int, std::string &, int), Holder>
{
    Object(int i, std::string &s, int i2)
    :
        BaseClass<0, Object>::Init(i),
        BaseClass<1, Object>::Init(s),
        BaseClass<2, Object>::Init(i2)
     {}
};

using namespace std;

int main()
{
    string s("hello");

    Object gen2(12345, s, 12);

    cout << base<0>(gen2).d_value << " " << base<1>(gen2).d_value << " " << 
            base<2>(gen2).d_value << endl;
}


