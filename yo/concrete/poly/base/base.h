    #ifndef INCLUDED_BASE_
    #define INCLUDED_BASE_

    #include <iosfwd>

    class Base
    {
        friend std::ostream &operator<<(std::ostream &out, Base const &obj);

        public:
            virtual ~Base() = default;
            Base *clone() const;
        private:
            virtual Base *ownClone() const = 0;
            virtual std::ostream &insert(std::ostream &os) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &out, Base const &obj)
    {
        return obj.insert(out);
    }
    
    #endif
