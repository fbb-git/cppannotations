    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello Cruel World");

        stringOne.erase(5, 6);

        cout << stringOne << endl;

        stringOne.erase();

        cout << "'" << stringOne << "'\n";
    }
