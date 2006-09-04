    class PointerDemo
    {
        public:
            unsigned get() const
            {
                return d_value;
            }
            unsigned d_value;
    };

    int main()
    {                                           // initialization
        unsigned (PointerDemo::*getPtr)() const = &PointerDemo::get;
        unsigned PointerDemo::*valuePtr         = &PointerDemo::d_value;

        getPtr   = &PointerDemo::get;           // assignment
        valuePtr = &PointerDemo::d_value;
    }
