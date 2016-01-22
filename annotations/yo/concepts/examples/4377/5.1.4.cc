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
concept bool C2()
{
    return requires (T t) 
           { 
                t + t ; 
           }
    ; // ends return
}


template <typename T>
requires C<T>
T sum(T a, T b)
{
    return a + b;
}

template <typename T>
concept bool RT() 
{
    return requires (T t) 
            {
                typename T::type;
                {*t} -> typename T::type const &;
            };
}

template <typename T>
requires C2<T>()
T add(T a, T b)
{
    return a + b;
}


template <class T>
concept bool Cd()
{
    return requires(T t, double d)
    {
        d > 0;
        t / d;
    };
}

int main()
{
}









