#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

inline int stringcasecmp(string lhs, string rhs)
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

    auto pos = find_if(                         // deprecated in C++17
                    v1.begin(), v1.end(),
                    not1( bind2nd(ptr_fun(stringcasecmp), target) )
               );

                                                // preferred alternative:
    auto pos = find_if(v1.begin(), v1.end(),    // use a lambda expression
            [&](auto const &str)
            {
                return not stringcasecmp(str, target);
    
            }
        );

    if ( pos != v1.end())
       cout <<   "The search for `" << target << "' was successful.\n"
                 "The next string is: `" << pos[1] << "'.\n";
}

    // on input:
    //  VERY   I have existed for years, but very little has changed
    // the program displays:
    //  The search for `VERY' was successful.
    //  The next string is: `little'.
