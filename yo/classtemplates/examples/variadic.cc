
#include <iostream>
#include <stdexcept>
#include <string>

namespace FBB
{
    void printf(char const *s)
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
    void printf(const char* s, T value, Args ... args)      // 2
    {
        while (*s)
        {
            if (*s == '%' && *(++s) != '%')                 // 6
            {
                std::cout << value;                         // 8
                printf(*s ? ++s : s, args...);              // 9 
                return;
            }
            std::cout << *s++;
        }
        throw std::logic_error("extra arguments provided to printf");
    }

} // FBB

int main(int argc, char **argv)
try
{
    FBB::printf("Hello %x with main called with %x args"
                                            " and a string showing %x\n",
        "world", argc, std::string("A String"));

    return 0;
}
catch (std::runtime_error err)
{
    std::cout << err.what() << std::endl;
    return 1;
}





