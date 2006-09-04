    #include <algorithm>
    #include <iostream>

    template<typename T>
    class Vector
    {
        friend std::ostream &operator<< <T> (std::ostream &str,
                                            Vector<T> const &vector);
        T *d_data;
        T *d_beyond;
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &str, Vector<T> const &vector)
    {
        std::copy(vector.d_data, vector.d_beyond,
                            std::ostream_iterator<T *>(str, " "));
        return str;
    }
