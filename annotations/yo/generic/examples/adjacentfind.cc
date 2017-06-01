    #include <algorithm>
    #include <string>
    #include <iostream>
    using namespace std;

    class SquaresDiff
    {
        size_t d_minimum;
        public:
            SquaresDiff(size_t minimum)
            :
                d_minimum(minimum)
            {}
            bool operator()(size_t first, size_t second)
            {
                return second * second - first * first  >= d_minimum;
            }
    };
    int main()
    {
        string sarr[] =
            {
                "Alpha", "bravo", "charley", "delta", "echo", "echo",
                "foxtrot", "golf"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);
        string *result = adjacent_find(sarr, last);

        cout << *result << '\n';
        result = adjacent_find(++result, last);

        cout << "Second time, starting from the next position:\n" <<
            (
                result == last ?
                    "** No more adjacent equal elements **"
                :
                    "*result"
            ) << '\n';

        size_t iv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        size_t *ilast = iv + sizeof(iv) / sizeof(size_t);
        size_t *ires = adjacent_find(iv, ilast, SquaresDiff(10));

        cout <<
            "The first numbers for which the squares differ at least 10: "
            << *ires << " and " << *(ires + 1) << '\n';
    }
    /*
    Displays:

    echo
    Second time, starting from the next position:
    ** No more adjacent equal elements **
    The first numbers for which the squares differ at least 10: 5 and 6
    */
