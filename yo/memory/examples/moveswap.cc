#include <iostream>
using namespace std;

// The assembler code (g++ -S moveswap.cc writes the assembler code on
// moveswap.S) of the Pointers and Refs constructors are identical: `behind
// the scenes' references are (const) pointers, with the compiler doing the
// derefencing for us

struct Pointers
{   
    std::ostream *d_ptr1;
    std::ostream *d_ptr2;

    Pointers(std::ostream *ptr1, std::ostream *ptr);
};

Pointers::Pointers(std::ostream *ptr1, std::ostream *ptr)
:
    d_ptr1(ptr1),
    d_ptr2(ptr)
{}

struct Refs
{   
    std::ostream &d_ref;
    std::ostream *d_ptr;

    Refs(std::ostream &ref, std::ostream *ptr);
};

Refs::Refs(std::ostream &ref, std::ostream *ptr)
:
    d_ref(ref),
    d_ptr(ptr)
{}

