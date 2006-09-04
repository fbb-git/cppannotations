    #include <numeric>

    template <typename T>
    T add(T *array, unsigned n)
    {
        return std::accumulate(array, array + n, T());
    }
