    #include <algorithm>
    #include <iterator>
    #include <string>
    #include <vector>
    using namespace std;

    int main()
    {
        vector<string> vs;

        copy(istream_iterator<string>(cin), istream_iterator<string>(),
             back_inserter(vs));

        for
        (
            vector<string>::iterator from = vs.begin();
                from != vs.end();
                    ++from
        )
            cout << *from << " ";
        cout << endl;

        return 0;
    }
