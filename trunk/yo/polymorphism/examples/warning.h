    #ifndef WARNINGEXCEPTION_H_
    #define WARNINGEXCEPTION_H_

    #include "exception.h"

    class Warning: public Exception
    {
        public:
            Warning(std::string const &reason)
            :
                Exception("Warning: " + reason)
            {}
    };
    #endif
