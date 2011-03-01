#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <iterator>

//BINDER2ND
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

            template <typename ... Params>
            typename Operation::result_type
            operator()(Params &&...params) const
            {
                return d_operation(std::forward<Params>(params) ..., d_arg2);
            }
    };
//=
//BIND2ND
    template<typename Operation, typename SecondArg>
    inline Binder2nd<Operation> Bind2nd(Operation const &operation,
                                        SecondArg const &arg2)
    {
        return Binder2nd<Operation>(
                    operation,
                    typename Operation::second_argument_type(arg2)
                );
    }
//=

using namespace std;

inline int stringicmp(string const &lhs, string const &rhs)
{
    return strcasecmp(lhs.c_str(), rhs.c_str());
}

int main()
{
    string target;
    cin >> target;

    vector<string> v1;
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(v1));

    auto pos = find_if(
                    v1.begin(), v1.end(),
                    not1( Bind2nd(ptr_fun(stringicmp), target) )
               );

    if ( pos != v1.end())
       cout <<   "The search for `" << target << "' was successful.\n"
                 "The next string is: `" << pos[1] << "'.\n";
}
