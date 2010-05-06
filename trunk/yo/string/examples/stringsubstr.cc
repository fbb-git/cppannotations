    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");

        cout << stringOne.substr(0, 5)  << '\n'
             << stringOne.substr(6)     << '\n'
             << stringOne.substr()      << '\n';
    }
