    #include <iostream>
    #include <algorithm>
    #include "stringptr.h"
    using namespace std;

    int main(int argc, char **argv)
    {
        StringPtr sp;

        while (*argv)
            sp.push_back(new string(*argv++));

        sort(sp.begin(), sp.end());
        copy(sp.begin(), sp.end(), ostream_iterator<string>(cout, " "));

        cout << "\n======\n";

        sort(sp.rbegin(), sp.rend());
        copy(sp.begin(), sp.end(), ostream_iterator<string>(cout, " "));

        cout << endl;
    }
    /*
            when called as:
        a.out bravo mike charlie zulu quebec

            generated output:
        a.out bravo charlie mike quebec zulu
        ======
        zulu quebec mike charlie bravo a.out
    */
