#include <iostream>
#include <thread>

//code
void thrower()
{
    throw std::exception();
}

int main()
try
{
   std::thread subThread(thrower);
}
catch (...)
{
    std::cerr << "Caught exception\n";
}
//=
