    #include <iostream>
    #include <vector>
    #include <iterator>
    #include "foreach.h"
    using namespace std;

    int main()
    {
        vector<string> vs;

        ForEach(istream_iterator<string>(cin), istream_iterator<string>(),
            vs, &vector<string>::push_back);

        cout << "The vector contains " << vs.size() << " strings\n";
    }
    /*
        Output generated when the program reads this source:

        The vector contains 47 strings
    */
