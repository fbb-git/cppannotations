#ifndef INCLUDED_BINARY_
#define INCLUDED_BINARY_

#include <bobcat/fswap>
#include <unordered_map>

class Binary
{
    int *d_ip;
    static std::unordered_map<size_t, size_t> s_copy;

    public:
        size_t d_nr;
        size_t d_copy;

        Binary();
        Binary(size_t nr);
        Binary(Binary const &other);
        Binary(Binary &&tmp);
        ~Binary();

        Binary &operator=(Binary const &other) = delete;    // for this demo
        Binary &operator=(Binary &&tmp);        

        void swap(Binary &other);

        Binary &operator+=(Binary const &rhs) &;
        Binary &&operator+=(Binary const &rhs) &&;

    private: 
        void add(Binary const &other);

    friend Binary operator+(Binary const &lhs, Binary const &rhs); 
    friend Binary operator+(Binary &&lhs, Binary const &rhs);
};


inline void Binary::swap(Binary &other)
{
    FBB::fswap(*this, other);
}
        
#endif
