    #include <iostream>
    #include <iterator>
    #include "foreach.h"
    #include <string>
    using namespace std;

    // -----------------------------------------------------------------

    class X
    {
        public:
            void handler(std::string const &str)
            {
                std::cout << str << '\n';
            }
            void handler(std::string const &str) const
            {
                std::cout << "const: " << str << '\n';
            }
            void constMember(std::string const &str) const
            {
                std::cout << "const member: " << str << '\n';
            }
            void nonConstMember(std::string const &str)
            {
                std::cout << "non-const member: " << str << '\n';
            }
            void operator()(std::string const &str) const
            {
                std::cout << "op()() cons " << str << '\n';
            }
    };

    int main(int argc, char **argv)
    {
        X x;

        STL(argv, argv + argc,
                &std::for_each<char **, ForEachObj<X, string const> >,
                x, &X::constMember);
    }
