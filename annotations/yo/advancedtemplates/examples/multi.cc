#include <string>
#include <iostream>

#include "multi.h"

using namespace std;

//POLICY
    template <typename Type>
    struct Policy
    {
        Type d_type;
        Policy(Type &&type)
        :
            d_type(std::forward<Type>(type))
        {}
    };
//=

int main()
{
//ONE
    Multi<Policy, string> ms{ Policy<string>{ "hello" } };
    Multi<Policy, string, string> ms2s{ Policy<string>{ "hello" },
                                       Policy<string>{ "world" } };


     typedef Multi<Policy, string, int> MPSI;
     MPSI mpsi{ string{ "hello" }, 4 };
//=

//TWO
    cout << "There are " << MPSI::size << " types in MPSI\n"
            "There are " << mpsi.size << " types in mpsi\n";
//=

//THREE
    plainTypeAt<0, MPSI>::Type sx = "String type";
    plainTypeAt<1, MPSI>::Type ix = 12;
//=

//FIVE
    cout << static_cast<Policy<string> &>(mpsi).d_type << '\n' <<
            static_cast<Policy<int> &>(mpsi).d_type << '\n';
//=

//SIX
    typedef Multi<Policy, int, int> MPII;
    MPII mpii{ 4, 18 };

    cout << get<0>(mpii).d_type << ' ' << get<1>(mpii).d_type << '\n';
//=

    get<0>(mpii).d_type  =  get<1>(mpii).d_type;
    cout << get<0>(mpii).d_type << ' ' << get<1>(mpii).d_type << '\n';

//SEVEN
    typedef Multi<Vector, int, double> MVID;
    MVID mi{ {1, 2, 3}, {1.2, 3.4, 5.6, 7.8} };
//=

//EIGHT
    typeAt<0, Multi<Vector, int>>::Type vi = {1, 2, 3};
//=

//NINE
    cout << get<0>(mi)[2] << '\n';
    get<1>(mi)[3] = get<0>(mi)[0];
    cout << get<1>(mi)[3] << '\n';
//=

//    cout << "Using get<0>(mpsi): " << get<0>(mpsi).d_type << '\n';
//    cout << "Using get<1>(mpsi): " << get<1>(mpsi).d_type << '\n';
//    Policy<int> pi = get<1>(mpsi);

//    cout << static_cast<Vector<int> &>(mi)[2] << '\n';
//    static_cast<Vector<int> &>(mi)[2]  = 18;
//    cout << static_cast<Vector<int> &>(mi)[2] << '\n';

}
