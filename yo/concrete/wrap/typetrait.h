template <typename T>
class TypeTrait
{
    template <typename U> struct Type
    {
        enum { isPointer = false };
        enum { isConst   = false };
        enum { isRef     = false };

        typedef U Plain;
    };
    template <typename U> struct Type<U const>
    {
        enum { isPointer = false };
        enum { isConst   = true };
        enum { isRef     = false };

        typedef U Plain;
    };
    template <typename U> struct Type<U *>
    {
        enum { isPointer = true };
        enum { isConst   = false };
        enum { isRef     = false };

        typedef U Plain;
    };
    template <typename U> struct Type<U const *>
    {
        enum { isPointer = true };
        enum { isConst   = true };
        enum { isRef     = false };

        typedef U Plain;
    };
    template <typename U> struct Type<U &>
    {
        enum { isPointer = false };
        enum { isConst   = false };
        enum { isRef     = true };

        typedef U Plain;
    };
    template <typename U> struct Type<U const &>
    {
        enum { isPointer = false };
        enum { isConst   = true };
        enum { isRef     = true };

        typedef U Plain;
    };

    public:
        enum { isPointer = Type<T>::isPointer };
        enum { isConst   = Type<T>::isConst };
        enum { isRef     = Type<T>::isRef };

        typedef typename Type<T>::Plain Plain;
};
