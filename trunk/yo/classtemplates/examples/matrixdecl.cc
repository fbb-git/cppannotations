    #include <cstddef>

    template <size_t Rows, size_t Columns, typename DataType = double>
    class Matrix;

    template <size_t Columns, typename DataType>
    class Matrix<1, Columns, DataType>;

    Matrix<1, 12> *function(Matrix<2, 18, size_t> &mat);
