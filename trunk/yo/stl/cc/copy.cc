    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        string  *last = sarr + sizeof(sarr) / sizeof(string);

        copy(sarr + 2, last, sarr); // move all elements two positions left

                                    // copy to cout using an ostream_iterator
                                    // for strings,
        copy(sarr, last, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        charley delta echo foxtrot golf hotel golf hotel
    */
