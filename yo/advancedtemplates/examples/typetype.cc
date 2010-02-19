#include <iostream>
#include <string>
#include "typetype.h"

template <typename Return, typename Argument>
Return chop(Argument const &arg, TypeType<Argument> )
{
    return Return(arg);
}

template <typename Argument>
std::string chop(Argument const &arg, TypeType<std::string> )
{
    return std::string(arg, 1);
}

template <typename Result, typename Arg>
Result chop(Arg txt)
{
    return chop(std::string(txt), TypeType<Result>());
}

using namespace std;

int main()
{
    cout << chop<string>("hello world") << endl;
}
