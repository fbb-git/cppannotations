#ifndef INCLUDED_CONVERSION_H_
#define INCLUDED_CONVERSION_H_

//CONVERSION
    template <typename T, typename U>
    class Conversion
    {
        typedef char Convertible;
        struct NotConvertible
        {
            char array[2];
        };

        static T makeT();
        static Convertible test(U const &);
        static NotConvertible test(...);

        public:
            enum { exists = sizeof(test(makeT())) == sizeof(Convertible) };
            enum { sameType = 0 };
    };

    template <typename T>
    class Conversion<T, T>
    {
        public:
            enum { exists = 1 };
            enum { sameType = 1 };
    };
//=

    #define BASE_1st_DERIVED_2nd(Base, Derived) \
        (Conversion<Derived const *, Base const *>::exists && \
         not Conversion<Base const *, void const *>::sameType)


    #define BASE_1st_DERIVED_2nd_STRICT(Base, Derived) \
        (BASE_1st_DERIVED_2nd(Base, Derived) && \
         not Conversion<Base const *, Derived const *>::sameType)

#endif
