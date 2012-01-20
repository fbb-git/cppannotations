    #include <algorithm>
    #include <vector>
    #include <iterator>
    #include <iostream>
    using namespace std;

    class NaturalSquares
    {
        size_t d_newsqr;
        size_t d_last;

        public:
            NaturalSquares(): d_newsqr(0), d_last(0)
            {}
            size_t operator()()
            {                           // using: (a + 1)^2 == a^2 + 2*a + 1
                return d_newsqr += (d_last++ << 1) + 1;
            }
    };
    int main()
    {
        vector<size_t>    uv(10);

        generate_n(uv.begin(), 5, NaturalSquares());

        copy(uv.begin(), uv.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    // Displays:    1 4 9 16 25 0 0 0 0 0
