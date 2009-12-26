    #include <iostream>
    #include <iterator>
    #include <string>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int main()
    {
        vector<string> vs;

        copy(istream_iterator<string>(cin), istream_iterator<string>(),
             back_inserter(vs));

        for
        (
            vector<string>::const_iterator begin = vs.begin(), end = vs.end();
                begin != end; ++begin
        )
            cout << *begin << ' ';
        cout << '\n';
    }
