#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void printcpp(string const &format)
{
    size_t left = 0;
    size_t right = 0;

    while (true)
    {
        if ((right = format.find('%', right)) == string::npos)
            break;
        if (format.find("%%", right) != right)
            throw std::runtime_error(
                        "printcpp: missing arguments");
        ++right;
        cout << format.substr(left, right - left);
        left = ++right;
    }
    cout << format.substr(left);
}

template<typename First, typename ... Params>
void printcpp(std::string const &format, First value, Params ... params)
{
    size_t left = 0;
    size_t right = 0;
    while (true)
    {                                              
        if ((right = format.find('%', right)) == string::npos)      // 1
            throw std::logic_error("printcpp: too many arguments");

        if (format.find("%%", right) != right)                      // 2
            break;

        ++right;
        cout << format.substr(left, right - left);
        left = ++right;
    }
    cout << format.substr(left, right - left) << value;
    printcpp(format.substr(right + 1), params ...);



int main(int argc, char **argv)
try
{
    printcpp("Hello % with %%main%% called with % args"
                                            " and a string showing %\n",
        "world", argc, string("A String"));
}
catch (std::runtime_error err)
{
    std::cout << err.what() << '\n';
    return 1;
}
