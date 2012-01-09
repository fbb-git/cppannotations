#ifndef INCLUDED_SEMANTIC_
#define INCLUDED_SEMANTIC_

#include <utility>
#include <string>

union Semantic
{
    friend std::ostream &operator<<(std::ostream &out, Semantic const &obj);

    std::pair<int, int>          d_int;
    std::pair<int, std::string>  d_str;

    public:
        enum Type
        {
            UNDEFINED,
            INT,
            IDENTIFIER
        };

        Semantic();
        Semantic(Type type, char const *txt);
        Semantic(Semantic const &other);             // 2
        ~Semantic();

        Semantic &operator=(Semantic const &rhs);

        void swap(Semantic &other);

};

inline Semantic::Semantic()
:
    d_int {UNDEFINED, 0}    
{}

#endif
