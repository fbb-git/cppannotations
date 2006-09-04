    #include <algorithm>
    #include <string>
    #include <iostream>

    class SquaresDiff
    {
        unsigned d_minimum;

        public:
            SquaresDiff(unsigned minimum)
            :
                d_minimum(minimum)
            {}
            bool operator()(unsigned first, unsigned second)
            {
                return second * second - first * first  >= d_minimum;
            }
    };

    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "Alpha", "bravo", "charley", "delta", "echo", "echo",
                "foxtrot", "golf"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);
        string *result = adjacent_find(sarr, last);

        cout << *result << endl;
        result = adjacent_find(++result, last);

        cout << "Second time, starting from the next position:\n" <<
            (
                result == last ?
                    "** No more adjacent equal elements **"
                :
                    "*result"
            ) << endl;

        unsigned iv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned *ilast = iv + sizeof(iv) / sizeof(unsigned);
        unsigned *ires = adjacent_find(iv, ilast, SquaresDiff(10));

        cout <<
            "The first numbers for which the squares differ at least 10: "
            << *ires << " and " << *(ires + 1) << endl;

        return 0;
    }
    /*
        Generated output:

        echo
        Second time, starting from the next position:
        ** No more adjacent equal elements **
        The first numbers for which the squares differ at least 10: 5 and 6
    */
