    #ifndef FATAL_H_
    #define FATAL_H_

    #include "exception.h"

    class Fatal: public Exception
    {
        public:
            Fatal(std::string  const &reason);
        private:
            virtual void action() const;
    };

    inline Fatal::Fatal(std::string  const &reason)
    :
        Exception(reason)
    {}

    inline void Fatal::action() const
    {
        std::cout << "Fatal::action() terminates" << std::endl;
        std::terminate();
    }

    #endif
