    #include <iostream>
    #include <string>
    #include <sstream>
    #include <fstream>

    using namespace std;

    int main()
    {
        ostringstream ostr("hello ", ios::ate);

        cout << ostr.str() << endl;

        ostr.setf(ios::showbase);
        ostr.setf(ios::hex, ios::basefield);
        ostr << 12345;

        cout << ostr.str() << endl;

        ostr << " -- ";
        ostr.unsetf(ios::hex);
        ostr << 12;

        cout << ostr.str() << endl;
    }
    /*
        Output from this program:
    hello
    hello 0x3039
    hello 0x3039 -- 12
    */
