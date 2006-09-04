    #include <iostream>
    using namespace std;

    int main()
    {
        cout << "first (buffered) line to cout ";
        cerr << "first (unbuffered) line to cerr\n";
        cout << "\n";

        cerr.tie(&cout);

        cout << "second (buffered) line to cout ";
        cerr << "second (unbuffered) line to cerr\n";
        cout << "\n";
    }
    /*
        Generated output:

    first (buffered) line to cout
    first (unbuffered) line to cerr
    second (buffered) line to cout second (unbuffered) line to cerr

    */
