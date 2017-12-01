#ifndef INCLUDED_ERRORCONDCAT_
#define INCLUDED_ERRORCONDCAT_

#include <system_error>
#include <vector>
#include <string>
#include <tuple>

class ErrorCondCat: public std::error_category
{
    typedef std::tuple<
                std::string,                // 0: condition name 
                char const *                // 1: descr.
            > Info;

    std::vector<Info> d_conditionInfo;

    public:
        ErrorCondCat();

        char const *name() const noexcept override;
        std::string message(int ev) const override;
        bool equivalent(std::error_code const &code,
                        int condition) const noexcept override;

        void addCondition(char const *name, char const *description);
        size_t size() const;
        std::string const &operator[](size_t idx) const;
};

inline void ErrorCondCat::addCondition(char const *name, 
                                       char const *description)
{
    d_conditionInfo.push_back({ name, description });
}

inline size_t ErrorCondCat::size() const
{
    return d_conditionInfo.size();
}

inline std::string const &ErrorCondCat::operator[](size_t idx) const
{
    return std::get<0>(d_conditionInfo[idx]);
}

#endif



