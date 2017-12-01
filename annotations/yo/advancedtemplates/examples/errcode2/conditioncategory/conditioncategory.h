#ifndef INCLUDED_CONDITIONCATEGORY_
#define INCLUDED_CONDITIONCATEGORY_

#include <system_error>
#include <vector>
#include <string>
#include <tuple>

class ConditionCategory: public std::error_category
{
    friend class ErrorCondition;

    typedef std::tuple<
                std::string,                // 0: condition name 
                char const *                // 1: descr.
            > Info;

    std::vector<Info> d_conditionInfo;

    public:
        ConditionCategory(ConditionCategory const &other) = delete;


        char const *name() const noexcept override;
        std::string message(int ev) const override;
        bool equivalent(std::error_code const &code,
                        int condition) const noexcept override;

    private:
        ConditionCategory();
        void addCondition(char const *name, char const *description);
        size_t size() const;
        std::string const &operator[](size_t idx) const;
};

inline void ConditionCategory::addCondition(char const *name, 
                                       char const *description)
{
    d_conditionInfo.push_back({ name, description });
}

inline size_t ConditionCategory::size() const
{
    return d_conditionInfo.size();
}

inline std::string const &ConditionCategory::operator[](size_t idx) const
{
    return std::get<0>(d_conditionInfo[idx]);
}

#endif



