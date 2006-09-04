    #include <string>
    #include <iostream>
    #include <iomanip>

    class X
    {
        public:
            void fun()
            {
                std::cout << "hello\n";
            }
            std::string d_str;
    };

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
