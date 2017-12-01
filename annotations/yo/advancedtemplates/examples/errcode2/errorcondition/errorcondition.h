#ifndef INCLUDED_ERRORCONDITION_H_
#define INCLUDED_ERRORCONDITION_H_

#include <unordered_map>

#include "../errorcondcat/errorcondcat.h"

class ErrorCondition
{
    static ErrorCondition *s_instance;

    ErrorCondCat d_ec;

    typedef std::unordered_map<std::string, size_t> ConditionMap;

    ConditionMap d_condition;


    public:
        enum Enum           // enum returning values of error conditions,
        {};

        static ErrorCondition &instance();

                            // name: single name defined for the condition
                            //      without ErrorCodeEnum
        void addCondition(char const *name, char const *description);

        Enum operator()(char const *condName) const;

        size_t nr(char const *name) const;  // nr of the named condition

        std::string const &operator[](size_t nr) const; // condition name

    private:
        ErrorCondition() = default; // singleton, see instance.cc

    friend std::error_condition make_error_condition(Enum ec);
};

//simcondtrait
namespace std
{
    template <>
    struct is_error_condition_enum<ErrorCondition::Enum>: public true_type 
    {};
}
//=

inline std::string const &ErrorCondition::operator[](size_t nr) const
{
    return d_ec[nr];
}

#endif
