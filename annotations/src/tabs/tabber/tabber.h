#ifndef INCLUDED_TABBER_
#define INCLUDED_TABBER_

#include <istream>
#include <ostream>

class Tabber
{
    std::istream d_in;
    std::ostream d_out;

    size_t d_nSpaces = 0;
    size_t d_column = 0;

    public:
        Tabber();

        void run();
        
    private:
        void entab();
        void space();
        void tab();
};
        
#endif

