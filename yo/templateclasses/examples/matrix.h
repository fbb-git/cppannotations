    #include <istream>
    #include <algorithm>
    #include <numeric>

    template <size_t Rows, size_t Columns, typename DataType = double>
    class Matrix
    {
//HEAD
        public:
            typedef Matrix<1, Columns, DataType>    MatrixRow;
            typedef Matrix<Rows, 1, DataType>       MatrixColumn;

        private:
            MatrixRow d_matrix[Rows];
//=
        public:
//CONSTRUCTORS
            Matrix(std::istream &str)
            {
                for (size_t row = 0; row < Rows; row++)
                    for (size_t col = 0; col < Columns; col++)
                        str >> d_matrix[row][col];
            }
            Matrix()
            {
                std::fill(d_matrix, d_matrix + Rows, MatrixRow());
            }
//=
//OPERATOR=
            MatrixRow &operator[](size_t idx)
            {
                return d_matrix[idx];
            }
//=
            MatrixRow const &operator[](size_t idx) const
            {
                return d_matrix[idx];
            }
//MARGINALS
            MatrixRow columnMarginals() const
            {
                return MatrixRow(*this);
            }
            MatrixColumn rowMarginals() const
            {
                return MatrixColumn(*this);
            }
            DataType sum()  const
            {
                return rowMarginals().sum();
            }
//=
    };

//MATRIXROW
    template <size_t Columns, typename DataType>  // no default specified
    class Matrix<1, Columns, DataType>
//=
    {
//ROWDATA
        DataType d_column[Columns];
//=
        public:
//ROWCONS1
            Matrix()
            {
                std::fill(d_column, d_column + Columns, DataType());
            }
//=
//ROWCONS2
            template <size_t Rows>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            {
                std::fill(d_column, d_column + Columns, DataType());

                for (size_t col = 0; col < Columns; col++)
                    for (size_t row = 0; row < Rows; row++)
                        d_column[col] += matrix[row][col];
            }
//=
//ROWOPERATOR=
            DataType &operator[](size_t idx)
            {
                return d_column[idx];
            }
//=
            DataType const &operator[](size_t idx) const
            {
                return d_column[idx];
            }
    };

//MATRIXCOLUMN
    template <size_t Rows, typename DataType>
    class Matrix<Rows, 1, DataType>
//=
    {
        DataType d_row[Rows];
        public:
            Matrix()
            {
                std::fill(d_row, d_row + Rows, DataType());
            }
            template <size_t Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            {
                for (size_t row = 0; row < Rows; row++)
                    d_row[row] =
                        std::accumulate
                        (
                            &matrix[row][0], &matrix[row][Columns], DataType()
                        );
            }
            DataType &operator[](size_t idx)
            {
                return d_row[idx];
            }
            DataType const &operator[](size_t idx) const
            {
                return d_row[idx];
            }
//SUMCOLUMN
            DataType sum()
            {
                return std::accumulate(d_row, d_row + Rows, DataType());
            }
//=
    };

//MATRIX1X1
    template <typename DataType>
    class Matrix<1, 1, DataType>
//=
    {
        DataType d_cell;
        public:
            Matrix()
            :
                d_cell(DataType())
            {}
//1X1CONS
            template <size_t Rows, size_t Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            :
                d_cell(matrix.rowMarginals().sum())
            {}
            template <size_t Rows>
            Matrix(Matrix<Rows, 1, DataType> const &matrix)
            :
                d_cell(matrix.sum())
            {}
//=
//ACCESSORS
            operator DataType &()
            {
                return d_cell;
            }
            DataType &get()
            {
                return d_cell;
            }
//=
            operator DataType const &() const
            {
                return d_cell;
            }
            DataType const &get() const
            {
                return d_cell;
            }
    };
