#include <iostream>
#include <string>
#include <vector>

#include "genscatter.h"

//FIELD
    template <typename Type>
    struct Field
    {
        Type field;
    
        Field(Type v = Type())
        :
            field(v)
        {}
    };
//=
   
//MYSTRUCT 
    struct MyStruct: public 
                        GenScat<TYPELIST_3(int, std::string &, int), Field>
    {
        MyStruct(int i, std::string &text, int i2)
        :
            BaseClass<0, MyStruct>::Type(i),
            BaseClass<1, MyStruct>::Type(text),
            BaseClass<2, MyStruct>::Type(i2)
         {}
    };
//=

//VECTORS
struct Vectors: public GenScat<TYPELIST_3(int, std::string, int), std::vector>
{
    Vectors()
    :
        BaseClass<0, Vectors>::Type(std::vector<int>(1)),
        BaseClass<1, Vectors>::Type(std::vector<std::string>(2)),
        BaseClass<2, Vectors>::Type(std::vector<int>(3))
     {}
};
//=

using namespace std;

int main()
{
    GenScat<TYPELIST_2(int, int), Field> gs;
    
    base<1>(gs).field = 12;
    cout << base<0>(gs).field << " " << base<1>(gs).field << endl;

    string text("hello");
    MyStruct myStruct(12345, text, 12);

    cout << base<0>(myStruct).field << " " << 
            base<1>(myStruct).field << " " << 
            base<2>(myStruct).field << endl;

    base<0>(myStruct).field = 123;
    base<1>(myStruct).field = "new text";

    cout << base<0>(myStruct).field << "\n" <<
            "`text' now contains: " << text << endl;

    Vectors vects;

    cout << base<0>(vects).size() << " " << base<1>(vects).size() << " " << 
            base<2>(vects).size() << endl;
}


