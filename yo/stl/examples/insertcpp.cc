    #include <iostream>
    #include <memory>
    using namespace std;

    int main()
    {
        auto_ptr<string> sp(new string("Hello world"));

        cout << *sp << endl;

        sp->insert(strlen("Hello "), "C++ ");
        cout << *sp << endl;
    }
    /*
        produced output:

        Hello world
        Hello C++ world
    */
