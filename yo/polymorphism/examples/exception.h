    #ifndef INCLUDED_EXCEPTION_H_
    #define INCLUDED_EXCEPTION_H_
    #include <iostream>
    #include <string>

    class Exception
    {
        std::string d_reason;

        public:
            Exception(std::string const &reason);
            virtual ~Exception();

            std::ostream &insertInto(std::ostream &out) const;
            void handle() const;

        private:
            virtual void action() const;
    };

    inline void Exception::action() const
    {
        throw;
    }
    inline Exception::Exception(std::string const &reason)
    :
        d_reason(reason)
    {}
    inline void Exception::handle() const   
    {
        action();
    }
    inline std::ostream &Exception::insertInto(std::ostream &out) const
    {
        return out << d_reason;
    }

    inline std::ostream &operator<<(std::ostream &out, Exception const &e)
    {
        return e.insertInto(out);
    }

    #endif
