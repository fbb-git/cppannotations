    #include <iostream>

    class PointerDemo
    {
        public:
            size_t d_value;
            size_t get() const;
    };

    inline size_t PointerDemo::get() const
    {
        return d_value;
    }

    using namespace std;

    int main()
    {                                           // initialization
        size_t (PointerDemo::*getPtr)() const = &PointerDemo::get;
        size_t PointerDemo::*valuePtr   = &PointerDemo::d_value;

        PointerDemo object;                     // (1) (see text)
        PointerDemo *ptr = &object;

        object.*valuePtr = 12345;               // (2)
        cout << object.*valuePtr << '\n' <<
                object.d_value << '\n';

        ptr->*valuePtr = 54321;                 // (3)
        cout << object.d_value << '\n' <<
                (object.*getPtr)() << '\n' <<   // (4)
                (ptr->*getPtr)() << '\n';
    }

