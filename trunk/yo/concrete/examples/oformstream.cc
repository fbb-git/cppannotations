    #include "oformstream.h"
    #include <memory>
    #include <stdarg.h>

    std::ostream &oformstream::form(char const *fmt, ...)   // 1
    {
        va_list list;
        va_start(list, fmt);

        size_t n = vsnprintf(0, 0, fmt, list);            // 2
        std::auto_ptr<char> buf(new char[n + 1]);           // 3
        vsprintf(buf.get(), fmt, list);                     // 4

        return *this << buf.get();                          // 5
    }

    using namespace std;

    int main()
    {
        oformstream
            of(cout);

        of << "Hello world\n";
        cout << "Ok, ";
        of << "That's all, folks\n";

        of.form("%s\n", "Hello world of C++") << endl;
    };

/*
    Generated output:

    Hello world
    Ok, That's all, folks
    Hello world of C++
*/
