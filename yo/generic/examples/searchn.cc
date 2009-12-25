    #include <algorithm>
    #include <iostream>
    #include <iterator>

    class absInt
    {
        public:
            bool operator()(int i1, int i2)
            {
                return abs(i1) == abs(i2);
            }
    };

    using namespace std;

    int main()
    {
        int range1[] =  {-2, -4, -4, -6, -8, 2, 4, 4, 6, 8};
        int range2[] =  {6, 8};

        copy
        (
            search_n(range1, range1 + 8, 2, 4),
            range1 + 8,
            ostream_iterator<int>(cout, " ")
        );
        cout << endl;

        copy
        (
            search_n(range1, range1 + 8, 2, 4, absInt()),
            range1 + 8,
            ostream_iterator<int>(cout, " ")
        );
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        4 4
        -4 -4 -6 -8 2 4 4
    */
