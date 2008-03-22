#include <vector>
using namespace std;

    template <typename Type>                                    // function 1
    Type add(Type const &lvalue, Type const &rvalue);

    template <typename Type1, typename Type2>                   // function 2
    Type1 add(Type1 const &lvalue, Type2 const &rvalue);

    template <typename Type1, typename Type2, typename Type3>   // function 3
    Type1 add(Type1 const &lvalue, Type1 const &mvalue, Type2 const &rvalue);

    double add(float lvalue, double rvalue);                    // function 4
    double add(std::vector<double> const &vd);                  // function 5
    double divide(double lvalue, double rvalue);                // function 6

int main()
{
    double x = 12.5;
    add(x, 12.5);
}
