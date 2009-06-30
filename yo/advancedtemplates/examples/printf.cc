#include <stdexcept>
#include <iostream>

    template<typename ... Params> 
    void xprintf(std::string const &strFormat, Params ... parameters);
 
    void xprintf(char const *s)
    {
        while (*s)
        {
            if (*s == '%' && *(++s) != '%')
                throw std::runtime_error(
                            "invalid format string: missing arguments");
            std::cout << *s++;
        }
    }
 
    template<typename T, typename ... Args>                 // 1      
    void xprintf(const char* s, T value, Args ... args)      // 2
    {
        while (*s)
        {
            if (*s == '%' && *(++s) != '%')                 // 6
            {
                std::cout << value;                         // 8
                xprintf(*s ? ++s : s, args...);              // 9 
                return;
            }
            std::cout << *s++;
        }
        throw std::logic_error("extra arguments provided to printf");
    }

    int main()
    {
        xprintf("hello %x worlds\n", 5);
    }
