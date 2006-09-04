    #include <iostream>

    class PointerDemo
    {
        public:
            unsigned get() const
            {
                return d_value;
            }
            unsigned d_value;
    };

    using namespace std;

    int main()
    {                                           // initialization
        unsigned (PointerDemo::*getPtr)() const = &PointerDemo::get;
        unsigned PointerDemo::*valuePtr   = &PointerDemo::d_value;

        PointerDemo object;                     // (1) (see text)
        PointerDemo *ptr = &object;

        object.*valuePtr = 12345;               // (2)
        cout << object.*valuePtr << endl;
        cout << object.d_value << endl;

        ptr->*valuePtr = 54321;                 // (3)
        cout << object.d_value << endl;

        cout << (object.*getPtr)() << endl;     // (4)
        cout << (ptr->*getPtr)() << endl;
    }
