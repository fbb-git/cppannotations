    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <cctype>

    void lowerCase(char &c)                     // `c' *is* modified
    {
        c = static_cast<char>(tolower(c));
    }
                                                // `str' is *not* modified
    void capitalizedOutput(std::string const &str)
    {
        char    *tmp = strcpy(new char[str.size() + 1], str.c_str());

        std::for_each(tmp + 1, tmp + str.size(), lowerCase);

        tmp[0] = toupper(*tmp);
        std::cout << tmp << " ";
        delete tmp;
    };

    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "BRAVO", "charley", "DELTA",  "echo",
                "FOXTROT", "golf", "HOTEL"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);

        for_each(sarr, last, capitalizedOutput)("that's all, folks");
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        Alpha Bravo Charley Delta Echo Foxtrot Golf Hotel That's all, folks
    */
