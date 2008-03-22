    #include <vector>
    #include <numeric>

    template <typename T>
    T sumVector(std::vector<T> &array)
    {
        return std::accumulate(array.begin(), array.end(), T());
    }
