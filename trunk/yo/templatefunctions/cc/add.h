    #include <numeric>

    template <typename T>
    T add(T *array, size_t n)
    {
        return std::accumulate(array, array + n, T());
    }
