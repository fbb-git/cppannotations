#include <iostream>
#include <streambuf>
#include <ctype.h>

class capsbuf: public std::streambuf
{
    public:
        capsbuf()
        :
            last(' ')
        {
            char
                dummy;
            setp(&dummy, &dummy);
        }

    protected:
        int overflow(int c)             // interface to the device.
        {
            std::cout.put(isspace(last) ? toupper(c) : c);
            last = c;
            return c;
        }
    private:
        int last;
};
