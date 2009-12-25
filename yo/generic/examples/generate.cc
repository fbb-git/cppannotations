    #include <algorithm>
    #include <vector>
    #include <iterator>
    #include <iostream>

    class NaturalSquares
    {
        size_t d_newsqr;
        size_t d_last;

        public:
            NaturalSquares(): d_newsqr(0), d_last(0)
            {}
            size_t operator()()
            {                   // using: (a + 1)^2 == a^2 + 2*a + 1
                return d_newsqr += (d_last++ << 1) + 1;
            }
    };

    using namespace std;

    int main()
    {
        vector<size_t>    uv(10);

        generate(uv.begin(), uv.end(), NaturalSquares());

        copy(uv.begin(), uv.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        1 4 9 16 25 36 49 64 81 100
    */
