    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");

        cout << stringOne.substr(0, 5)  << endl
             << stringOne.substr(6)     << endl
             << stringOne.substr()      << endl;
    }
