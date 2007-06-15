    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne;

        cout << "The length of the stringOne string is "
            << stringOne.size() << " characters\n"
                "It is " << (stringOne.empty() ? "" : " not ")
            << "empty\n";

        stringOne = "";

        cout << "After assigning a \"\"-string to a string-object\n"
                "it is " << (stringOne.empty() ? "also" : " not")
            << " empty\n";
    }
