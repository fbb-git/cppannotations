#ifndef INCLUDED_BASICTRAITS_H_
#define INCLUDED_BASICTRAITS_H_

    template <typename TypeParam>
    class BasicTraits
    {
//BASIC
        template <typename T>
        struct Basic
        {
            typedef T Type;
            enum
            {
                isValue = true,
                isPointer = false,
                isConst = false
            };
        };
//=
        template <typename T>
        struct Basic<T const>
        {
            typedef T Type;
            enum
            {
                isValue = false,
                isPointer = true,
                isConst = true
            };
        };
//POINTER
        template <typename T>
        struct Basic<T *>
        {
            typedef T Type;
            enum
            {
                isValue = false,
                isPointer = true,
                isConst = false
            };
        };
//=
//CONST
        template <typename T>
        struct Basic<T const *>
        {
            typedef T Type;
            enum
            {
                isValue = false,
                isPointer = true,
                isConst = true
            };
        };
//=
        template <typename T>
        struct Basic<T &>
        {
            typedef T Type;
            enum
            {
                isValue = false,
                isPointer = false,
                isConst = false
            };
        };

        template <typename T>
        struct Basic<T const &>
        {
            typedef T Type;
            enum
            {
                isValue = false,
                isPointer = false,
                isConst = true
            };
        };

        public:
            typedef typename Basic<TypeParam>::Type ValueType;
            typedef ValueType *PtrType;
            typedef ValueType &RefType;

            enum
            {
                isValueType = Basic<TypeParam>::isValue,
                isPointerType = Basic<TypeParam>::isPointer,
                isReferenceType = not Basic<TypeParam>::isPointer and
                                  not Basic<TypeParam>::isValue,
                isConst = Basic<TypeParam>::isConst
            };

    };

#endif
