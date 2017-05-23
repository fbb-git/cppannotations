    #include <cstddef>

    class IntArray
    {
        int     *d_data;
        size_t d_size;

         public:
            IntArray(size_t size = 1);
            IntArray(IntArray const &other);
            ~IntArray();
            IntArray &operator=(IntArray const &other);

                                                // overloaded index operators:
            int &operator[](size_t index);              // first
            int operator[](size_t index) const;         // second

            void swap(IntArray &other);         // trivial

        private:
            void boundary(size_t index) const;
            int &operatorIndex(size_t index) const;
    };
