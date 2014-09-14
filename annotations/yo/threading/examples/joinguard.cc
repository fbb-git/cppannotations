#include <iostream>
#include "joinguard.h"

void childActions();

void doSomeWork()
{
    throw std::runtime_error("doSomeWork throws");
}

void parent()
{
    JoinGuard{std::thread{childActions}};
    doSomeWork();
}

int main()
try
{
    parent();
}
catch (std::exception const &exc)
{
    std::cout << exc.what() << '\n';
}












