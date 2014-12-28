    #include <iostream>
    #include <algorithm>
    #include <iterator>
    using namespace std;

    int main()
    {
        istreambuf_iterator<char> in(cin.rdbuf());
        istreambuf_iterator<char> eof;
        ostreambuf_iterator<char> out(cout.rdbuf());

        copy(in, eof, out);
    }
