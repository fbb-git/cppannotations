#include <istream>
#include <ostream>
#include <utility>

    // The complete interface of the class template Binops: if additional
    // operators are overloaded Binops requires no modifications.
    //
template <typename Derived>
class Binops
{
    template <typename Der>
    friend std::ostream &operator<<(
                            std::ostream &out, Binops<Der> const &rhs);

    template <typename Der>
    friend std::istream &operator>>(std::istream &in, Binops<Der> &rhs);

    void eWrap(std::istream &in);
    void iWrap(std::ostream &out) const;
};

    // Completing the overloads for operator+: all function templates, that
    // depend on operator+=(...) defined in Derived
    //
template <class Derived, typename Rhs>
Derived &operator+=(Binops<Derived> &lhs, Rhs const &rhs)
{
    Derived tmp{ Derived{static_cast<Derived &>(lhs)} += rhs };
    tmp.swap(static_cast<Derived &>(lhs));
    return static_cast<Derived &>(lhs);
}

template <class Derived, typename Rhs>
Derived operator+(Binops<Derived> &&lhs, Rhs const &rhs)
{
    return static_cast<Derived &&>(std::move(lhs)) += rhs;
}

template <class Derived, typename Rhs>
Derived operator+(Binops<Derived> const &lhs, Rhs const &rhs)
{
    return Derived{static_cast<Derived const &>(lhs)} += rhs;
}

    // Other operators may be added here, and are implemented analogously, see
    // the Annotations.

    // Implementing the insertion operator. The extraction operator is
    // implemented analogously, see the Annotations:
    //
template <typename Derived>
inline void Binops<Derived>::iWrap(std::ostream &out) const
{
    static_cast<Derived const &>(*this).insert(out);
}

template <typename Derived>
inline std::ostream &operator<<(std::ostream &out, Binops<Derived> const &rhs)
{
    rhs.iWrap(out);
    return out;
}






////////////////////////////////////////////////////////////////////////

    // User area: the user defines a class Derived, and wants to provide
    // addition and insertion: the operator+=() && and insert() functions have
    // to be implemented and Derived derives from Binops<Derived>. For insert
    // a friend declaration is also required.

#include <iostream>

using namespace std;

class Derived: public Binops<Derived>
{
    friend Binops<Derived>; // only required for stream insertion/extraction

    int d_value = 0;

    public:
        Derived() = default;

        Derived(int value)
        :
            d_value(value)
        {}

        void swap(Derived &other);

        Derived &&operator+=(Derived const &rhs) &&;

    private:
        void insert(std::ostream &out) const;
};

inline void Derived::insert(std::ostream &out) const
{
    out << "Inserting a Derived object";
}

Derived &&Derived::operator+=(Derived const &rhs) &&
{
    d_value += rhs.d_value;
    return std::move(*this);
}

inline void Derived::swap(Derived &rhs)
{
    std::swap(d_value, rhs.d_value);
}

int main()
{
    Derived o1{ 1 },
    Derived o2{ 2 };
    o1 += o2;
    // o1 *= o2;            // adding this statement results in
                            // a compilation error

    o1 = o1 + o2;
    o1 += o1;

    cout << o1 << '\n';
}
