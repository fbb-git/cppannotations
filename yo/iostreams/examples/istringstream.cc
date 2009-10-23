    #include <iostream>
    #include <sstream>
    using namespace std;

    int main()
    {
        istringstream istr("123 345");  // store some text.
        int x;

        istr.seekg(2);              // skip "12"
        istr >> x;                  // extract int
        cout << x << '\n';          // write it out
        istr.seekg(0);              // retry from the beginning
        istr >> x;                  // extract int
        cout << x << '\n';          // write it out
        istr.str("666");            // store another text
        istr >> x;                  // extract it
        cout << x << '\n';          // write it out
    }
    /*
        output of this program:
    3
    123
    666
    */
