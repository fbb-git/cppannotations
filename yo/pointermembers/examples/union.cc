    #include <string>
    #include <iostream>
    #include <iomanip>

    class X
    {
        public:
            void fun();
            std::string d_str;
    };

    inline void X::fun()
    {
        std::cout << "hello\n";
    }

    using namespace std;

    int main()
    {
        union
        {
            void (X::*f)();
            unsigned char *cp;
        }
            u = { &X::fun };

        cout.fill('0');
        cout << hex;
        for (unsigned idx = sizeof(void (X::*)()); idx-- > 0; )
            cout << setw(2) << static_cast<unsigned>(u.cp[idx]);
        cout << endl;
    }
