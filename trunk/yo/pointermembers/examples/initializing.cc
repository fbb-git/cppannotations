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

    int main()
    {                                           // initialization
        size_t (PointerDemo::*getPtr)() const = &PointerDemo::get;
        size_t PointerDemo::*valuePtr         = &PointerDemo::d_value;

        getPtr   = &PointerDemo::get;           // assignment
        valuePtr = &PointerDemo::d_value;
    }
