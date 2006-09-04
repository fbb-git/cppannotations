    #ifndef _FATALEXCEPTION_H_
    #define _FATALEXCEPTION_H_

    #include "exception.h"

    class FatalException: public Exception
    {
        public:
            FatalException(char const *reason)
            :
                Exception(reason)
            {}
            void process() const
            {
                exit(1);
            }
    };
    #endif
