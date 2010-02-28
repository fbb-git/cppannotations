#ifndef INCLUDED_CONVERSION_H_
#define INCLUDED_CONVERSION_H_

//CONVERSION
    template <typename T, typename U>
    class LconvertibleToR
    {
        struct Char2
        {
            char array[2];
        };
        static T makeT();
        static char test(U const &);
        static Char2 test(...);

        public:
            LconvertibleToR(LconvertibleToR const &other) = delete;
            enum { yes = sizeof(test(makeT())) == sizeof(char) };
            enum { sameType = 0 };
    };

    template <typename T>
    class LconvertibleToR<T, T>
    {
        public:
            LconvertibleToR(LconvertibleToR const &other) = delete;
            enum { yes = 1 };
            enum { sameType = 1 };
    };
//=
//LBASERDERIVED
    template <typename Base, typename Derived>
    struct LBaseRDerived
    {
        LBaseRDerived(LBaseRDerived const &) = delete;
        enum {
            yes =
                LconvertibleToR<Derived const *, Base const *>::yes &&
                not LconvertibleToR<Base const *, void const *>::sameType
        };
    };
//=
//LBASERTRUE
    template <typename Base, typename Derived>
    struct LBaseRtrulyDerived
    {
        LBaseRtrulyDerived(LBaseRtrulyDerived const &) = delete;
        enum {
            yes =
                LBaseRDerived<Base, Derived>::yes &&
                not LconvertibleToR<Base const *, Derived const *>::sameType
        };
    };
//=
#endif
