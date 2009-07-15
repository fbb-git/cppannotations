    #include <cstddef>

    class IntArray
    {
        int *d_data;
        size_t d_capacity;
        size_t d_nUsed;

        public:
            IntArray(size_t capacity = 0);
            IntArray(IntArray const &other);
            IntArray(IntArray &&other);             // move constructor
            ~IntArray();

            IntArray &operator=(IntArray const &other);
            IntArray &operator=(IntArray &&other);  // Note: move operator=()
    };

    IntArray::IntArray(IntArray &&other)
    {
        d_data = other.d_data;
        other.d_data = 0;
        d_capacity = other.d_capacity;
        d_nUsed = other.d_nUsed;
    }
