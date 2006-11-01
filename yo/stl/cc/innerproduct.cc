    #include <numeric>
    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>

    class Cat
    {
        std::string  d_sep;
        public:
            Cat(std::string const &sep)
            :
                d_sep(sep)
            {}
            std::string operator()
                (std::string const &s1, std::string const &s2) const
            {
                return s1 + d_sep + s2;
            }
    };

    using namespace std;

    int main()
    {
        size_t ia1[] = {1, 2, 3, 4, 5, 6, 7};
        size_t ia2[] = {7, 6, 5, 4, 3, 2, 1};
        size_t init = 0;

        cout << "The sum of all squares in ";
        copy(ia1, ia1 + 7, ostream_iterator<size_t>(cout, " "));
        cout << "is " <<
            inner_product(ia1, ia1 + 7, ia1, init) << endl;

        cout << "The sum of all cross-products in ";
        copy(ia1, ia1 + 7, ostream_iterator<size_t>(cout, " "));
        cout << " and ";
        copy(ia2, ia2 + 7, ostream_iterator<size_t>(cout, " "));
        cout << "is " <<
            inner_product(ia1, ia1 + 7, ia2, init) << endl;

        string names1[] = {"Frank", "Karel", "Piet"};
        string names2[] = {"Brokken", "Kubat", "Plomp"};

        cout << "A list of all combined names in ";
        copy(names1, names1 + 3, ostream_iterator<string>(cout, " "));
        cout << "and\n";
        copy(names2, names2 + 3, ostream_iterator<string>(cout, " "));
        cout << "is:" <<
            inner_product(names1, names1 + 3, names2, string("\t"),
                Cat("\n\t"), Cat(" ")) <<
            endl;

        return 0;
    }
    /*
        Generated output:

        The sum of all squares in 1 2 3 4 5 6 7 is 140
        The sum of all cross-products in 1 2 3 4 5 6 7  and 7 6 5 4 3 2 1 is 84
        A list of all combined names in Frank Karel Piet and
        Brokken Kubat Plomp is:
                Frank Brokken
                Karel Kubat
                Piet Plomp
    */
