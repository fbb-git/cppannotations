    class PointerDemo
    {
        public:
            unsigned d_value;
            unsigned get() const;
    };

    inline unsigned PointerDemo::get() const
    {
        return d_value;
    }

    int main()
    {                                           // initialization
        unsigned (PointerDemo::*getPtr)() const = &PointerDemo::get;
        unsigned PointerDemo::*valuePtr         = &PointerDemo::d_value;

        getPtr   = &PointerDemo::get;           // assignment
        valuePtr = &PointerDemo::d_value;
    }
