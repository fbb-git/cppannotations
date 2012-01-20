#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

template<typename Operation>
class Binder2nd:
        public std::unary_function<typename Operation::first_argument_type,
                                   typename Operation::result_type>
{
    typedef typename Operation::second_argument_type SecondArg;

    protected:
        Operation d_operation;
        SecondArg d_arg2;

    public:
        Binder2nd(Operation const &operation, SecondArg const &arg2)
        :
            d_operation(operation),
            d_arg2(arg2)
        {}

        template <typename ...Params>
        typename Operation::result_type
        operator()(Params &&...params) const
        {
            return d_operation(std::forward<Params>(params)..., d_arg2);
        }
};

template<typename Operation, typename SecondArg>
inline Binder2nd<Operation> Bind2nd(Operation const &operation,
                                    SecondArg const &arg2)
{
    return Binder2nd<Operation>(
                operation,
                typename Operation::second_argument_type(arg2)
            );
}

using namespace std;

int main(int argc, char **argv)
{
    int iArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << count_if(iArr, iArr + 10, Bind2nd(less_equal<int>(), 6)) <<
        ' ';
    cout << count_if(iArr, iArr + 10, Bind2nd(not2(greater<int>()), 6)) <<
        ' ';
    cout << count_if(iArr, iArr + 10, not1(Bind2nd(greater<int>(), 6))) <<
        '\n';
}
    // Displays: 6 6 6
