    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");

        stringOne[6] = 'w';         // now "Hello world"
        if (stringOne[0] == 'H')
            stringOne[0] = 'h';     // now "hello world"

        //  *stringOne = 'H';       // THIS WON'T COMPILE

        stringOne = "Hello World";  // Now using the at()

                                    // member function:
        stringOne.at(6) =
                stringOne.at(0);    // now "Hello Horld"
        if (stringOne.at(0) == 'H')
            stringOne.at(0) = 'W';  // now "Wello Horld"

        return 0;
    }
