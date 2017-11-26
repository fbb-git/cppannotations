#ifndef INCLUDED_ERRORSOURCE_H_
#define INCLUDED_ERRORSOURCE_H_

#include <system_error>
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>

struct CategoryData;

class ErrorSource
{
            // a pointer to a function returning true if the provided
            // error_code is equivalent to the error_condition (...?)
    typedef bool (*EquivPtr)(char const *conditionName,
                            std::error_code const &);

    public:
                // get<0> gives a NTBS describing the error condition
        typedef std::tuple<
                    char const *,               // 0: condition name 
                    char const *                // 1: descr.
                > Info;

    private:
            // the vector holding the source's name and handling function
            // address (may be 0)
        typedef std::vector<Info> InfoVector;

            // mapping the error source's name to an s_info index
        typedef std::unordered_map<char const *, size_t> ConditionMap;

            // mapping the error category's name to the handling function
        typedef std::unordered_map<char const *, EquivPtr> CategoryMap;

        InfoVector d_info;
        ConditionMap d_condition;
        CategoryMap  d_category;

    public:
                
        enum Enum           // enum returning values of error conditions,
        {};                 // which are the addresses of 

        ErrorSource();          // can only be used once, which occurs 
                                // in errorsource1.cc

                            // name: single name defined for the condition
                            //      without ErrorCodeEnum
        void addCondition(char const *name, char const *description);

                // sourceName could be CalcError, SimError, InputError
        void addCategory(CategoryData const &data);

        bool equivalent(int condition, // index in s_info
                        std::error_code const &code);

        Enum operator()(char const *conditionName) const;

    private:
                                        // add to s_condition or exception.
        void addCondition(char const *name); 


//    CalcError = 1,
//    SimError,
//    InputError
};

extern ErrorSource g_errorSource;

#endif
