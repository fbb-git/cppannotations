    #ifndef _WARNINGEXCEPTION_H_
    #define _WARNINGEXCEPTION_H_

    #include "exception.h"

    class WarningException: public Exception
    {
        public:
            WarningException(char const *reason)
            :
                Exception(reason)
            {}
            void process() const;
    };
    #endif
