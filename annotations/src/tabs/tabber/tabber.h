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
        void run(char const *inName, char const *outName);

    private:
        void detab();
        void entab();
        bool tabColumn();
        void outSpaces();


        void space();
        void tab();
};
        
#endif




