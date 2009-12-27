    #include <iostream>
    #include <memory>
    #include <cstring>
    using namespace std;

    int main()
    {
        unique_ptr<string> sp(new string("Hello world"));

        cout << *sp << '\n';
        sp->insert(strlen("Hello "), "C++ ");
        cout << *sp << '\n';
    }
    /*
        Displays:
            Hello world
            Hello C++ world
    */
