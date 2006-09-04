    #include <istream>
    #include <algorithm>
    #include <numeric>

    template <unsigned Rows, unsigned Columns, typename DataType = double>
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
                for (unsigned row = 0; row < Rows; row++)
                    for (unsigned col = 0; col < Columns; col++)
                        str >> d_matrix[row][col];
            }
            Matrix()
            {
                std::fill(d_matrix, d_matrix + Rows, MatrixRow());
            }
//=
//OPERATOR=
            MatrixRow &operator[](unsigned idx)
            {
                return d_matrix[idx];
            }
//=
            MatrixRow const &operator[](unsigned idx) const
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
    template <unsigned Columns, typename DataType>  // no default specified
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
            template <unsigned Rows>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            {
                std::fill(d_column, d_column + Columns, DataType());

                for (unsigned col = 0; col < Columns; col++)
                    for (unsigned row = 0; row < Rows; row++)
                        d_column[col] += matrix[row][col];
            }
//=
//ROWOPERATOR=
            DataType &operator[](unsigned idx)
            {
                return d_column[idx];
            }
//=
            DataType const &operator[](unsigned idx) const
            {
                return d_column[idx];
            }
    };

//MATRIXCOLUMN
    template <unsigned Rows, typename DataType>
    class Matrix<Rows, 1, DataType>
//=
    {
        DataType d_row[Rows];
        public:
            Matrix()
            {
                std::fill(d_row, d_row + Rows, DataType());
            }
            template <unsigned Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            {
                for (unsigned row = 0; row < Rows; row++)
                    d_row[row] =
                        std::accumulate
                        (
                            &matrix[row][0], &matrix[row][Columns], DataType()
                        );
            }
            DataType &operator[](unsigned idx)
            {
                return d_row[idx];
            }
            DataType const &operator[](unsigned idx) const
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
            template <unsigned Rows, unsigned Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix)
            :
                d_cell(matrix.rowMarginals().sum())
            {}
            template <unsigned Rows>
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
