    #include <iostream>
    #include <memory>
    #include <cstring>
    using namespace std;

    int main()
    {
        shared_ptr<string> sp(new string("Hello world"));
        shared_ptr<string> sp2(sp);

        sp->insert(strlen("Hello "), "C++ ");
        cout << *sp << '\n' <<
                *sp2 << '\n';
    }
    /*
        Displays:
            Hello C++ world
            Hello C++ world
    */
