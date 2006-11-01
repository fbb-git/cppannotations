    template <size_t Rows, size_t Columns, typename DataType = double>
    class Matrix;

    template <size_t Columns, typename DataType>
    class Matrix<1, Columns, DataType>;

    template<size_t Columns, typename DataType>
    Matrix<1, Columns, DataType> function(Matrix<Rows, Columns, DataType> mat)
    {}
