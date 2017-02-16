#include <iostream>
#include <string>
#include <vector>
#include <bobcat/typetrait>

using namespace std;
using namespace FBB;

template <typename Type>
void show()
{
    cout << 
        "const: " << TypeTrait<Type>::isConst << "\n"
        "pointer: " << TypeTrait<Type>::isPointer << "\n"
        "lref: " << TypeTrait<Type>::isRef << "\n"
        "rref: " << TypeTrait<Type>::isR_Ref << "\n"
        "\n";
}

int &&rref();
int const &icref();

string const &text()
{
    static string txt = "text";
    return txt; 
}

struct Data
{
    int i_val;
    int *d_val;

    decltype(auto) fun() const
    {
        return d_val[0];
    }

};

int main()
{
    int value;

    show<decltype(value)>();            // plain value
    show<decltype((value))>();          // l ref

    show<decltype(3)>();                // plain value
    show<decltype((3))>();              // plain value

    show<decltype(rref())>();           // r ref
    show<decltype( (rref())) >();       // r ref

    int &iref = value;

    show<decltype(iref)>();             // lref
    show<decltype( (iref)) >();         // lref

    decltype( (iref) ) iref2 = value;   // same lref as iref

    int *ip = &value;
    show<decltype(  ip  ) >();          // pointer
    show<decltype( (ip) ) >();          // lref

    decltype( (ip) ) ipref = ip;        // lref to ip
    show<decltype( ipref )>();

    *ipref = 1;
    int *&ipref2 = ip;                  // reference to pointer

    cout << value << "\n\n";

    show<decltype(icref())>();

    auto str = text();      // text's plain type is string, so 
                            // string str, NOT string const str
                            // is defined
    str += "...";           // OK          

    cout << str << '\n';

    int *ip3= &value;
    auto ip4 = ip3; 
    *ip4 = 12;
    cout << value << '\n';

    string const &scr = str;
    show<decltype(scr)>();

    Data data;
    show<decltype(data.fun())>();

    int &fref = data.fun();    

//    cout << fref << '\n';

    int arr[20];
    show<decltype(arr[0])>();

    int const x = 10;

    show<decltype(x)>();

    auto y = x;
    show<decltype(y)>();

}





