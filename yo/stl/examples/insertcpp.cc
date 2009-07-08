    #include <iostream>
    #include <memory>
    #include <cstring>
    using namespace std;

    int main()
    {
        unique_ptr<string> sp(new string("Hello world"));

        cout << *sp << endl;
        sp->insert(strlen("Hello "), "C++ ");
        cout << *sp << endl;
    }
    /*
        produced output:

        Hello world
        Hello C++ world
    */
