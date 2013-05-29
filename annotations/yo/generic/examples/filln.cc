    #include <algorithm>
    #include <vector>
    #include <iterator>
    #include <iostream>
    using namespace std;

    int main()
    {
        vector<int>     iv(8);

        fill_n(iv.begin() + 2, 4, 8);

        copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    // Displays:    0 0 8 8 8 8 0 0
