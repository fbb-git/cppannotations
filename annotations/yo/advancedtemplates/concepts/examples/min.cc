#include <unordered_map>

#if 0

template<typename Type>
Type const &smaller(Type const &first, Type const &second)
{
    return second < first ? second : first;
}

#else

    // compile with g++ --std=c++2a -fconcepts min.cc

template <typename Type>
concept bool HasOpSmaller()
{
    return requires(Type lhs, Type rhs)
    {
        lhs < rhs;
    };
}

template<HasOpSmaller Type>
Type const &smaller(Type const &first, Type const &second)
{
    return second < first ? second : first;
}

#endif

int main()
{
    std::unordered_map<int, int> umap;
    smaller(umap, umap);
}
