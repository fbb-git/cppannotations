#ifndef INCLUDED_ERRORCONDITION_H_
#define INCLUDED_ERRORCONDITION_H_

#include <system_error>
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>

struct CategoryData;

class ErrorCondition:  public std::error_category
{
    static ErrorCondition *s_instance;

    typedef std::tuple<
                std::string,                // 0: condition name 
                char const *                // 1: descr.
            > Info;

    std::vector<Info> d_conditionInfo;

    typedef std::unordered_map<std::string, size_t> ConditionMap;

    ConditionMap d_condition;

            // a pointer to a function returning true if the provided
            // error_code is equivalent to the error_condition (...?)
    typedef bool (*EquivPtr)(size_t condNr, std::error_code const &ec);

            // mapping the error condition's name 
            // to the handling function
    typedef std::unordered_map< std::error_category const *, EquivPtr > 
                                                                CategoryMap;

    CategoryMap d_category;

    public:
        enum Enum           // enum returning values of error conditions,
        {};


        static ErrorCondition &instance();

                            // name: single name defined for the condition
                            //      without ErrorCodeEnum
        void addCondition(char const *name, char const *description);

        void addCategory(char const *name,
                         std::error_category const *singleton, 
                         EquivPtr function); // , char const *description);

        Enum operator()(char const *condName) const;

        size_t nr(char const *name) const;  // nr of the named condition

        std::string const &operator[](size_t nr) const; // condition name

        char const *name() const noexcept override;
        std::string message(int ev) const override;

        bool equivalent(
                        std::error_code const &code,
                        int condition) const noexcept override;
    private:
        ErrorCondition();          // can only be used once, which occurs 
                                // in errorcondition1.cc
};

//simcondtrait
namespace std
{
    template <>
    struct is_error_condition_enum<ErrorCondition::Enum>: public true_type 
    {};
}
//=

std::error_condition make_error_condition(ErrorCondition::Enum ec);

inline std::string const &ErrorCondition::operator[](size_t nr) const
{
    return std::get<0>(d_conditionInfo[nr]);
}

#endif
