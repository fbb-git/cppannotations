#include <iostream>

template<typename Ret, typename ...Params>
Ret insert(Params &&...params)
{
    return Ret{} + ... + params;
}
//
//template <typename ...Params>
//Params sum(Params &&...params)
//{
//    return Params{}; // + ... + params;
//}
//
int main()
{
}


