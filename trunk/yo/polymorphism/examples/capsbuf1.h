#include <iostream>
#include <streambuf>
#include <ctype.h>

class CapsBuf: public std::streambuf
{
    int d_last;

    public:
        CapsBuf()
        :
            d_last(' ')
        {}

    protected:
        int overflow(int c)             // interface to the device.
        {
            std::cout.put(isspace(d_last) ? toupper(c) : c);
            return d_last = c;
        }
};
