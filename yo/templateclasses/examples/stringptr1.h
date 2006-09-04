    #ifndef _INCLUDED_STRINGPTR_H_
    #define _INCLUDED_STRINGPTR_H_

    #include <string>
    #include <vector>

    class StringPtr: public std::vector<std::string *>
    {
        public:
            StringPtr(StringPtr const &other);
            ~StringPtr();

            StringPtr &operator=(StringPtr const &other);
    };

    #endif
