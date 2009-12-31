    #include <algorithm>
    #include <iostream>
    #include <iterator>
    using namespace std;

    class absInt
    {
        public:
            bool operator()(int i1, int i2) const
            {
                return abs(i1) == abs(i2);
            }
    };
    int main()
    {
        int range1[] =  {-2, -4, -6, -8, 2, 4, 6, 8};
        int range2[] =  {6, 8};

        copy
        (
            search(range1, range1 + 8, range2, range2 + 2),
            range1 + 8,
            ostream_iterator<int>(cout, " ")
        );
        cout << '\n';

        copy
        (
            search(range1, range1 + 8, range2, range2 + 2, absInt()),
            range1 + 8,
            ostream_iterator<int>(cout, " ")
        );
        cout << '\n';
    }
    /*
        Displays:
            6 8
            -6 -8 2 4 6 8
    */
