    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");
        string stringTwo;

        if (stringOne != stringTwo)
            stringTwo = stringOne;

        if (stringOne == stringTwo)
            stringTwo = "Something else";

        if (stringOne.compare(stringTwo) > 0)
            cout << "stringOne after stringTwo in the alphabet\n";
        else if (stringOne.compare(stringTwo) < 0)
            cout << "stringOne before stringTwo in the alphabet\n";
        else
            cout << "Both strings are the same\n";

        // Alternatively:

        if (stringOne > stringTwo)
            cout <<
            "stringOne after stringTwo in the alphabet\n";
        else if (stringOne < stringTwo)
            cout <<
            "stringOne before stringTwo in the alphabet\n";
        else
            cout << "Both strings are the same\n";

        return 0;
    }
