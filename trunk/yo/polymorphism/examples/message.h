    #ifndef MESSAGEEXCEPTION_H_
    #define MESSAGEEXCEPTION_H_

    #include "exception.h"

    class MessageException: public Exception
    {
        public:
            MessageException(char const *reason)
            :
                Exception(reason)
            {}
            void process() const;
    };
    #endif
