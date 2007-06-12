#include <iostream>
#include <string>
#include <vector>

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
        BaseClass<0, Object>::Type(i),
        BaseClass<1, Object>::Type(s),
        BaseClass<2, Object>::Type(i2)
     {}
};

struct Vectors: public GenScat<TYPELIST_3(int, std::string, int), std::vector>
{
    Vectors()
    :
        BaseClass<0, Vectors>::Type(std::vector<int>(1)),
        BaseClass<1, Vectors>::Type(std::vector<std::string>(2)),
        BaseClass<2, Vectors>::Type(std::vector<int>(3))
     {}
};

using namespace std;

int main()
{
    string s("hello");

    GenScat<TYPELIST_2(int, int), Holder> gs;
    
    base<1>(gs).d_value = 12;
    cout << base<0>(gs).d_value << " " << base<1>(gs).d_value << endl;


    Object gen2(12345, s, 12);

    cout << base<0>(gen2).d_value << " " << base<1>(gen2).d_value << " " << 
            base<2>(gen2).d_value << endl;

    base<0>(gen2).d_value = 123;

    cout << base<0>(gen2).d_value << endl;

    Vectors vects;

    cout << base<0>(vects).size() << " " << base<1>(vects).size() << " " << 
            base<2>(vects).size() << endl;

}
