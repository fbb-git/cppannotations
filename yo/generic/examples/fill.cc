    #include <algorithm>
    #include <vector>
    #include <iterator>
    #include <iostream>
    using namespace std;

    int main()
    {
        vector<int>     iv(8);

        fill(iv.begin(), iv.end(), 8);

        copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        8 8 8 8 8 8 8 8
    */
