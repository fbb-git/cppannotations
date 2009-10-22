    #include <iostream>
    #include <sstream>

    using namespace std;

    int main()
    {
        ostringstream ostr("hello ", ios::ate);

        cout << ostr.str() << '\n';

        ostr.setf(ios::showbase);
        ostr.setf(ios::hex, ios::basefield);
        ostr << 12345;

        cout << ostr.str() << '\n';

        ostr << " -- ";
        ostr.unsetf(ios::hex);
        ostr << 12;

        cout << ostr.str() << '\n';

        ostr.str("new text");
        cout << ostr.str() << '\n';

        ostr.seekp(4, ios::beg);
        ostr << "world";
        cout << ostr.str() << '\n';
    }
    /*
        Output from this program:
    hello
    hello 0x3039
    hello 0x3039 -- 12
    new text
    new world
    */
