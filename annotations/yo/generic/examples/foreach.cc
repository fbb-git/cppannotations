    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iostream>
    #include <cctype>
    using namespace std;

    void lowerCase(char &c)                     // `c' *is* modified
    {
        c = tolower(static_cast<unsigned char>(c));
    }
    void capitalizedOutput(string const &str)   // `str' is *not* modified
    {
        char    *tmp = strcpy(new char[str.size() + 1], str.c_str());

        for_each(tmp + 1, tmp + str.size(), lowerCase);

        tmp[0] = toupper(*tmp);
        cout << tmp << " ";
        delete tmp;
    };
    int main()
    {
        string sarr[] =
            {
                "alpha", "BRAVO", "charley", "DELTA",  "echo",
                "FOXTROT", "golf", "HOTEL"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);

        for_each(sarr, last, capitalizedOutput)("that's all, folks");
        cout << '\n';
    }
    /*
    Displays:

    Alpha Bravo Charley Delta Echo Foxtrot Golf Hotel That's all, folks
    */
