    #ifndef _EXCEPTION_H_
    #define _EXCEPTION_H_

    #include <iostream>
    #include <string>

    class Exception
    {
        friend std::ostream &operator<<(std::ostream &str, Exception const &e)
        {
            return str << e.operator std::string();
        }

        std::string d_reason;

        public:
            virtual ~Exception()
            {}
            virtual void process() const = 0;
            virtual operator std::string() const
            {
                return d_reason;
            }
        protected:
            Exception(char const *reason)
            :
                d_reason(reason)
            {}
    };
    #endif
