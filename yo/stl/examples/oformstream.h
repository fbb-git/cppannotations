    #include <ostream>
    #include <iostream>
    #include <memory>
    #include <stdarg.h>

    class oformstream: public std::ostream              // 6
    {
    public:

        oformstream(std::streambuf *buf)                // 10
        :
            std::ostream(buf)
        {}

        oformstream &
        form(char const *fmt, ...)                      // 16
        {
            va_list list;
            va_start(list, fmt);
            return vform(fmt, list);
        }

        oformstream &
        vform(char const *fmt, va_list list)            // 24
        {
            unsigned size = 128;                        // 26

            while (true)                                // 28
            {
                std::auto_ptr<char> buf(new char[size]);// 30
                va_list vlist = list;
                int n =                                 // 32
                    vsnprintf (buf.get(), size, fmt, vlist);

                if (n > -1 && n < size)                 // 35
                {
                    write(buf.get(), n);
                    return *this;
                }

                if ((size <<= 1) == 0)                  // 41
                {
                    std::cerr << "vform() buffer maximum reached\n";
                    exit(1);
                }
            }
        }
    };
