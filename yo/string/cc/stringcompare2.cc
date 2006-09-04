    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");

            // comparing from a certain offset in stringOne
        if (!stringOne.compare(1, stringOne.length() - 1, "ello World"))
            cout << "comparing 'Hello world' from index 1"
                    " to 'ello World': ok\n";

            // the number of characters to compare (2nd arg.)
            // may exceed the number of available characters:
        if (!stringOne.compare(1, string::npos, "ello World"))
            cout << "comparing 'Hello world' from index 1"
                    " to 'ello World': ok\n";

            // comparing from a certain offset in stringOne over a
            // certain number of characters in "World and more"
            // This fails, as all of the chars in stringOne
            // starting at index 6 are compared, not just
            // 3 chars in "World and more"
        if (!stringOne.compare(6, 3, "World and more"))
            cout <<
            "comparing 'Hello World' from index 6 over"
            " 3 positions to 'World and more': ok\n";
        else
            cout << "Unequal (sub)strings\n";

            // This one will report a match, as only 5 characters are
            // compared of the  source and target strings
        if (!stringOne.compare(6, 5, "World and more", 0, 5))
            cout <<
            "comparing 'Hello World' from index 6 over"
            " 5 positions to 'World and more': ok\n";
        else
            cout << "Unequal (sub)strings\n";
    }
    /*
            Generated output:

        comparing 'Hello world' from index 1 to 'ello World': ok
        comparing 'Hello world' from index 1 to 'ello World': ok
        Unequal (sub)strings
        comparing 'Hello World' from index 6 over 5 positions to
                    'World and more': ok
    */
