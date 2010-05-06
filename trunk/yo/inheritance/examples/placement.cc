#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class String
{
    union Ptrs
    {
        void *vp;
        String *sp;
        size_t *np;
    };

    std::string d_str;

    public:
        String(std::string const &txt)
        :
            d_str(txt)
        {}
        ~String()
        {
            cout << "destructor: " << d_str << '\n';
        }
        static String *construct(istream &in, size_t n)
        {
            Ptrs p = {operator new(n * sizeof(String) + sizeof(size_t))};
            *p.np++ = n;

            string line;
            for (size_t idx = 0; idx != n; ++idx)
            {
                getline(in, line);
                new(p.sp + idx) String(line);
            }

            return p.sp;
        }
        static void destroy(String *sp)
        {
            Ptrs p = {sp};
            --p.np;
            for (size_t n = *p.np; n--; )
                sp++->~String();

            operator delete (p.vp);
        }
};

int main()
{
    String *sp = String::construct(cin, 5);

    String::destroy(sp);
}

/*
    After providing 5 lines containing, respectively
        alfa, bravo, charlie, delta, echo
    the program displays:
                destructor: alfa
                destructor: bravo
                destructor: charlie
                destructor: delta
                destructor: echo
*/
