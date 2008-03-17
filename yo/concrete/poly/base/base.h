    #ifndef INCLUDED_BASE_
    #define INCLUDED_BASE_
    
    #include <iosfwd>
    
    class Base
    {
        public:
            virtual ~Base();
            virtual Base *clone() const = 0;
            virtual std::ostream &insert(std::ostream &os) const = 0;
    };
    
    inline Base::~Base()
    {}
    
    inline std::ostream &operator<<(std::ostream &out, Base const &obj)
    {
        return obj.insert(out);
    }
    
    #endif
