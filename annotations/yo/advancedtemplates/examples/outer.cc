template <typename T>
class Outer
{
    public:
        class Nested
        {};

        Nested nested() const;
};

template <typename T>
Outer<T>::Nested Outer<T>::nested() const
{
    return Nested{};
}
