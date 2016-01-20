template <typename T>
requires requires (T t) { t + t ; }
T add(T a, T b)
{
    return a + b;
}

// concept avoids the double requires:

template <typename T>
concept bool C = requires (T t) 
                        { t + t ; }
                    ; // <--- NOTE, as in classes

template <typename T>
requires C<T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
}


