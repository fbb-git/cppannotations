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
                isPointer = false,
                isConst = false,
                isRef = false,
                isRRef = false
            };
        };
//=
        template <typename T>
        struct Basic<T const>
        {
            typedef T Type;
            enum
            {
                isPointer = true,
                isConst = true,
                isRef = false,
                isRRef = false
            };
        };
//POINTER
        template <typename T>
        struct Basic<T *>
        {
            typedef T Type;
            enum
            {
                isPointer = true,
                isConst = false,
                isRef = false,
                isRRef = false
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
                isPointer = true,
                isConst = true,
                isRef = false,
                isRRef = false
            };
        };
//=
        template <typename T>
        struct Basic<T &>
        {
            typedef T Type;
            enum
            {
                isPointer = false,
                isConst = false,
                isRef = true,
                isRRef = false
            };
        };

        template <typename T>
        struct Basic<T const &>
        {
            typedef T Type;
            enum
            {
                isPointer = false,
                isConst = true,
                isRef = true,
                isRRef = false
            };
        };
        template <typename T>
        struct Basic<T &&>
        {
            typedef T Type;
            enum
            {
                isPointer = false,
                isConst = false,
                isRef = false,
                isRRef = true
            };
        };
        template <typename T>
        struct Basic<T const &&>
        {
            typedef T Type;
            enum
            {
                isPointer = false,
                isConst = true,
                isRef = false,
                isRRef = true
            };
        };

        public:
            typedef typename Basic<TypeParam>::Type ValueType;
            typedef ValueType *PtrType;
            typedef ValueType &RefType;
            typedef ValueType &&RvalueRefType;

            enum
            {
                isPointerType = Basic<TypeParam>::isPointer,
                isReferenceType = Basic<TypeParam>::isRef,
                isRvalueReferenceType = Basic<TypeParam>::isRRef,
                isConst = Basic<TypeParam>::isConst,

                isPlainType = not (isPointerType or isReferenceType or
                                   isRvalueReferenceType or isConst)
            };

    };

#endif
