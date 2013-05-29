    #include <algorithm>
    #include <iterator>
    #include <functional>
    #include <iostream>
    #include <cstring>
    #include "predicates.h"
    using namespace std;

//CONTAINS
    class Contains
    {
        string d_target;
        size_t d_count;
        public:
            Contains(char const *target)
            :
                d_target(target),
                d_count(0)
            {}
            bool operator()(string const &str)
            {
                d_count++;
                return str.find_first_of(d_target) != string::npos;
            }
            bool operator()(string const &s1, string const &s2)
            {
                d_count++;
                return s1.find_first_of(s2) != string::npos;
            }
            size_t count() const
            {
                return d_count;
            }
    };
//=
//MAIN
    int main(int argc, char **argv)
    {
        Contains contains("aeiou");
        if (argc == 1)
            cout << "Counted " <<
                count_if(istream_iterator<string>(cin),
                         istream_iterator<string>(),
                         PredicateObject1<Contains, string>(contains)
                ) << " words containing vowels ";
        else
            cout << "Counted " <<
                count_if(istream_iterator<string>(cin),
                        istream_iterator<string>(),
                        bind2nd
                        (
                            PredicateObject2<Contains, string>(contains),
                            "aeiou"
                        )
                ) << " words containing vowels ";
        cout << "(read " << contains.count() << " strings)\n";
    }
    /*
        Generated output after executing (predobj.cc being this soure file)

            a.out < predobj.cc
        or
            a.out 2 < predobj.cc

        Counted 97 words containing vowels (read 149 strings)
    */
//=
