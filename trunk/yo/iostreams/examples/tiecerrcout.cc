    #include <iostream>
    using namespace std;

    int main()
    {
        cerr.tie(0);        // untie
        cout << "first (buffered) line to cout ";
        cerr << "first (unbuffered) line to cerr\n";
        cout << "\n";

        cerr.tie(&cout);    // tie cout to cerr
        cout << "second (buffered) line to cout ";
        cerr << "second (unbuffered) line to cerr\n";
        cout << "\n";
    }
    /*
        Generated output:

        first (unbuffered) line to cerr
        first (buffered) line to cout
        second (buffered) line to cout second (unbuffered) line to cerr
    */
