#include "binary.ih"

Binary::~Binary()
{
    delete d_ip;
//    cout << "destructor of object " << d_nr << ':' << d_copy << '\n';
}
