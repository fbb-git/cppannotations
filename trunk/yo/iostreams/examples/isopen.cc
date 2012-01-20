    #include <fstream>
    #include <iostream>

    using namespace std;

    int main()
    {
        ofstream of;

        cout << "of's open state: " << boolalpha << of.is_open() << '\n';

        of.open("/dev/null");       // on Unix systems

        cout << "of's open state: " << of.is_open() << '\n';
    }
    /*
        Generated output:
    of's open state: false
    of's open state: true
    */
