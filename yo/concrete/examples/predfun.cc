    #include <algorithm>
    #include <iterator>
    #include <functional>
    #include <iostream>
    #include <string>
    #include "predicates.h"
    using namespace std;


    int main(int argc)
    {
        if (argc == 1)
            cout << "Counted " <<
                count_if(istream_iterator<char>(cin), istream_iterator<char>(),
                        PredicateFunction1<char>(isdigit)) << " digits\n";
        else

            cout << "Counted " <<
                count_if(istream_iterator<char>(cin), istream_iterator<char>(),
                        bind1st(
                            PredicateFunction2<char const*, char,
                                       char *(*)(char const*, int)>(strchr),
                            "0123456789")
                        ) << " digits\n";
    }
    /*
        Generated output after

            echo 1 world, there are 6 continents and 3 oceans | a.out
        or:
            echo 1 world, there are 6 continents and 3 oceans | a.out 2

        Counted 3 digits
    */
