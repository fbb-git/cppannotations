// The classes Add and Sub performing the basic arithmetic operations.
// Each operation type has its own class. Here Add and Sub only provide 
// operator@=  (for demonstration purposes)
//
// Binops is the class befriending the arithmetic operation classes
// Derived is the class that's derived from Binops. Derived wants to offer + and
// - operators. It does so by deriving from Binops<Derived, '+', '-'>
//
// The design is based on the CRTP, stepping over several classes
// Structure (read the ascii art below from bottom to top):
//
//
//  Binops0<Binops, Derived>      Sub<Binops, Derived>
//          |   Ends the            |   Binops now also is a Sub
//          |   recursion           |
//          |                       |
//          +---+--------------------+
//              |
//       Binops0<Binops, Derived, '-'>        Add<Binops, Derived>
//              |   Recursively defning         |   Binops now also is an Add
//              |   Binops0s for remaining      |
//              |   operators                   |
//              |                               |
//              +-----------+-------------------+
//                          |
//                       Binops0<Binops, Derived, '+', '-'> 
//                          |   this forwards the Binops class to the
//                          |   binary operator classes
//                          |
//                       Binops<Derived, '+', '-'>
//                          |   declares all binary operator classes as friend
//                          |
//                        Derived 
//                            (wants, e.g., + and - operations)
//
//////////////////////////////////////////////////////////////////
    // The basic arithmetic classes:

#include <utility>

template <class Binops, class Derived>
struct Add
{
    Derived &operator+=(Derived const &rhs) &; // Used as: object1 += object2
    Derived &&operator+=(Derived const &rhs) &&;    // (anon.) += object2
};

template <class Binops, class Derived>
Derived &&Add<Binops, Derived>::operator+=(Derived const &rhs) &&
{
    static_cast<Binops &>(*this).addWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Binops, class Derived>
Derived &Add<Binops, Derived>::operator+=(Derived const &rhs) &
{
    return 
        static_cast<Derived &>(*this) = 
            Derived{
                std::move(static_cast<Derived &>(*this))
            } += rhs;
}


template <class Derived>
Derived operator+(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.addWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator+(Derived &&lhs, Derived const &rhs)
{
    lhs.addWrap(rhs);
    return std::move(lhs);
}

////////////////////////////////////////////////////


template <class Binops, class Derived>
struct Sub
{
    void operator-=(Derived const &rhs)
    {
        static_cast<Binops &>(*this).subWrap(rhs);
    }
};

template <class Binops, class Derived>
struct Mul
{
    void operator*=(Derived const &rhs)
    {
        static_cast<Binops &>(*this).mulWrap(rhs);
    }                                          
};

//////////////////////////////////////////////////////////////////
    // The recursively defined Binops0 class: receives Binops, so a static
    // cast becomes available to reach the basic arithmetic classes

    // The general declaration:
    // 
template <class Binops, class Derived, int ...ops>
class Binops0;

    // The terminating definition:
    //
template <class Binops, class Derived>
class Binops0<Binops, Derived>
{};

    // The recursive definition: each variant inherits from the corresponding
    // arithmetic class, and from itself, derived with the remaining operators
    // (ops)
    //
    // This one is for addition:
    //
template <class Binops, class Derived, int ...ops>
class Binops0<Binops, Derived, '+', ops...>
:
    public Binops0<Binops, Derived, ops...>,
    public Add<Binops, Derived>
{};

    // This one is for subtraction:
    //
template <class Binops, class Derived, int ...ops>
class Binops0<Binops, Derived, '-', ops...>
:
    public Binops0<Binops, Derived, ops...>,
    public Sub<Binops, Derived>
{};

    // This one is for multiplication:
    //
template <class Binops, class Derived, int ...ops>
class Binops0<Binops, Derived, '*', ops...>
:
    public Binops0<Binops, Derived, ops...>,
    public Mul<Binops, Derived>
{};

    // The class Binops befriends all arithmetic classes, and implements
    // wrappers for the arithmetic functions potentially defined in 
    // Derived.
    // The arithmetic classes call Binops' functions, which in turn call
    // Derived's functions. This way Derived only needs to implement the
    // necessary functions. Since the other functions aren't called, they
    // arent't instantiated so there are no linker-errors
    //
template <class Derived, int ...ops>
class Binops:
    public Binops0<Binops<Derived, ops...>, Derived, ops...>
{
    friend class Add<Binops<Derived, ops...>, Derived>;
    friend class Sub<Binops<Derived, ops...>, Derived>;
    friend class Mul<Binops<Derived, ops...>, Derived>;

    friend Derived operator+<Derived>(Derived const &lhs, Derived const &rhs); 
    friend Derived operator+<Derived>(Derived &&lhs, Derived const &rhs);

    void (Derived::*fun)(Derived const &);

            // Note that the following function names should be different from
            // the function names in Derived: if they're identical, and the
            // corresponding Derived class function doesn't exist, then the
            // program will recursively call Binops member, causing a
            // stack-overflow, and therefore a segfault. I added B to indicate
            // a Binops function.

        void addWrap(Derived const &rhs);
        void subWrap(Derived const &rhs);
        void mulWrap(Derived const &rhs);
};

template <class Derived, int ...ops>
inline void Binops<Derived, ops...>::addWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).add(rhs);
}

template <class Derived, int ...ops>
inline void Binops<Derived, ops...>::subWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).sub(rhs);
}

template <class Derived, int ...ops>
inline void Binops<Derived, ops...>::mulWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).mul(rhs);
}

////////////////////////////////////////////////////////////////////////

    // User area: the user defines a class Derived, and wants to provide
    // addition and subtraction.
    // When additional operators are added to the template argument list 
    // (e.g. '*') compilation still succeeds, but because of the missing mul
    // function compilation fails if associated operators are actually 
    // used (like o1 *= o2, shown below)
    // 

#include <iostream>

using namespace std;

class Derived: public Binops<Derived, '+', '-'>
{
    friend class Binops<Derived, '+', '-'>;

    int d_value = 0;

    public:
        Derived() = default;

        Derived(int value)
        :
            d_value(value)
        {}
            

    void add(Derived const &rhs);
    void sub(Derived const &rhs);
};

inline void Derived::add(Derived const &rhs)
{
    cout << "adding " << d_value << " + " << rhs.d_value << "\n";
    d_value += rhs.d_value;
}

inline void Derived::sub(Derived const &rhs)
{
    cout << "subtracting " << d_value << " - " << rhs.d_value << "\n";
    d_value -= rhs.d_value;
}

int main()
{
    Derived o1(1), o2(2);
    o1 += o2;
    o1 -= o2;
    // o1 *= o2;            adding this statement causes a compilation error

    o1 = o1 + o2;
    o1 += o1;
}


