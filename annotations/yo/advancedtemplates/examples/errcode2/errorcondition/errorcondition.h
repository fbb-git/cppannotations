#ifndef INCLUDED_ERRORCONDITION_H_
#define INCLUDED_ERRORCONDITION_H_

#include <unordered_map>

#include "../conditioncategory/conditioncategory.h"

class ErrorCondition
{
    static ErrorCondition *s_instance;

    ConditionCategory d_ec;

    typedef std::unordered_map<std::string, size_t> ConditionMap;
    ConditionMap d_condition;

    public:
        enum Enum           // enum returning values of error conditions,
        {};

        static ErrorCondition &instance();

                            // name: name used for the error_condition
        void addCondition(char const *name, char const *description);

        Enum operator()(char const *condName) const;    // enum given the
                                                        // condition's name

        std::string const &operator[](size_t nr) const; // condition name
                                                        // given its nr
    private:
        ErrorCondition() = default; // singleton, see instance.cc
        
    friend std::error_condition make_error_condition(Enum ec);
};

inline std::string const &ErrorCondition::operator[](size_t nr) const
{
    return d_ec[nr];
}

//trait
namespace std
{
    template <>
    struct is_error_condition_enum<ErrorCondition::Enum>: public true_type 
    {};
}
//=

#endif
