    template <unsigned Rows, unsigned Columns, typename DataType = double>
    class Matrix;

    template <unsigned Columns, typename DataType>
    class Matrix<1, Columns, DataType>;

    template<unsigned Columns, typename DataType>
    Matrix<1, Columns, DataType> function(Matrix<Rows, Columns, DataType> mat)
    {}
