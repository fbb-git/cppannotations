    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");
        char const *cString = stringOne.c_str();

        cout << cString << '\n';
    }
