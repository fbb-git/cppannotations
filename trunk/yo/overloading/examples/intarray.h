    class IntArray
    {
        int     *d_data;
        unsigned d_size;

         public:
            IntArray(unsigned size = 1);
            IntArray(IntArray const &other);
            ~IntArray();
            IntArray const &operator=(IntArray const &other);

                                                // overloaded index operators:
            int &operator[](unsigned index);                // first
            int const &operator[](unsigned index) const;    // second
        private:
            void boundary(unsigned index) const;
            void copy(IntArray const &other);
            int &operatorIndex(unsigned index) const;
    };
