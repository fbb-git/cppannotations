    #include <istream>
    #include <algorithm>
    #include <numeric>

    template <size_t Rows, size_t Columns, typename DataType = double>
    class Matrix
    {
//HEAD
        typedef Matrix<1, Columns, DataType>    MatrixRow;
        typedef Matrix<Rows, 1, DataType>       MatrixColumn;

        MatrixRow d_matrix[Rows];
//=
        public:
            Matrix();
            Matrix(std::istream &str);
            MatrixRow &operator[](size_t idx);
            MatrixRow const &operator[](size_t idx) const;
            MatrixRow columnMarginals() const;
            MatrixColumn rowMarginals() const;
            DataType sum()  const;
    };

//MATRIXROW
    template <size_t Columns, typename DataType>  // no default allowed
    class Matrix<1, Columns, DataType>
//=
    {
//ROWDATA
        DataType d_column[Columns];
//=
        public:
            Matrix();

            template <size_t Rows>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix);

            DataType &operator[](size_t idx);
            DataType const &operator[](size_t idx) const;
    };


//MATRIXCOLUMN
    template <size_t Rows, typename DataType>
    class Matrix<Rows, 1, DataType>
//=
    {
        DataType d_row[Rows];
        public:
            Matrix();

            template <size_t Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix);

            DataType &operator[](size_t idx);
            DataType const &operator[](size_t idx) const;
            DataType sum();
    };

//MATRIX1X1
    template <typename DataType>
    class Matrix<1, 1, DataType>
//=
    {
        DataType d_cell;
        public:
            Matrix();

            template <size_t Rows, size_t Columns>
            Matrix(Matrix<Rows, Columns, DataType> const &matrix);

            template <size_t Rows>
            Matrix(Matrix<Rows, 1, DataType> const &matrix);

            operator DataType &();
            DataType &get();
            operator DataType const &() const;
            DataType const &get() const;
    };

//MARGINALS
    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<1, Columns, DataType>
    Matrix<Rows, Columns, DataType>::columnMarginals() const
    {
        return MatrixRow(*this);
    }

    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<Rows, 1, DataType>
    Matrix<Rows, Columns, DataType>::rowMarginals() const
    {
        return MatrixColumn(*this);
    }

    template <size_t Rows, size_t Columns, typename DataType>
    DataType Matrix<Rows, Columns, DataType>::sum()  const
    {
        return rowMarginals().sum();
    }
//=


//CONSTRUCTORS
    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<Rows, Columns, DataType>::Matrix()
    {
        std::fill(d_matrix, d_matrix + Rows, MatrixRow());
    }
    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<Rows, Columns, DataType>::Matrix(std::istream &str)
    {
        for (size_t row = 0; row < Rows; row++)
            for (size_t col = 0; col < Columns; col++)
                str >> d_matrix[row][col];
    }
//=

//OPERATORINDEX
    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<1, Columns, DataType>
    &Matrix<Rows, Columns, DataType>::operator[](size_t idx)
    {
        return d_matrix[idx];
    }
//=

    template <size_t Rows, size_t Columns, typename DataType>
    Matrix<1, Columns, DataType>
    const &Matrix<Rows, Columns, DataType>::operator[](size_t idx) const
    {
        return d_matrix[idx];
    }

//ROWCONS1
    template <size_t Columns, typename DataType>
    Matrix<1, Columns, DataType>::Matrix()
    {
        std::fill(d_column, d_column + Columns, DataType());
    }
//=
//ROWCONS2
    template <size_t Columns, typename DataType>
    template <size_t Rows>
    Matrix<1, Columns, DataType>::Matrix(
                            Matrix<Rows, Columns, DataType> const &matrix)
    {
        std::fill(d_column, d_column + Columns, DataType());

        for (size_t col = 0; col < Columns; col++)
            for (size_t row = 0; row < Rows; row++)
                d_column[col] += matrix[row][col];
    }
//=

//ROWOPERATORINDEX
    template <size_t Columns, typename DataType>
    DataType &Matrix<1, Columns, DataType>::operator[](size_t idx)
    {
        return d_column[idx];
    }
//=

    template <size_t Columns, typename DataType>
    DataType const &Matrix<1, Columns, DataType>::operator[](size_t idx) const
    {
        return d_column[idx];
    }


    template <size_t Rows, typename DataType>
    Matrix<Rows, 1, DataType>::Matrix()
    {
        std::fill(d_row, d_row + Rows, DataType());
    }

    template <size_t Rows, typename DataType>
    template <size_t Columns>
    Matrix<Rows, 1, DataType>::Matrix(
                            Matrix<Rows, Columns, DataType> const &matrix)
    {
        for (size_t row = 0; row < Rows; row++)
            d_row[row] =
                std::accumulate
                (
                    &matrix[row][0], &matrix[row][Columns], DataType()
                );
    }

    template <size_t Rows, typename DataType>
    DataType &Matrix<Rows, 1, DataType>::operator[](size_t idx)
    {
        return d_row[idx];
    }

    template <size_t Rows, typename DataType>
    DataType const &Matrix<Rows, 1, DataType>::operator[](size_t idx) const
    {
        return d_row[idx];
    }

//SUMCOLUMN
    template <size_t Rows, typename DataType>
    DataType Matrix<Rows, 1, DataType>::sum()
    {
        return std::accumulate(d_row, d_row + Rows, DataType());
    }
//=

    template <typename DataType>
    Matrix<1, 1, DataType>::Matrix()
    :
        d_cell(DataType())
    {}

//1X1CONS
    template <typename DataType>
    template <size_t Rows, size_t Columns>
    Matrix<1, 1, DataType>::Matrix(
                            Matrix<Rows, Columns, DataType> const &matrix)
    :
        d_cell(matrix.rowMarginals().sum())
    {}

    template <typename DataType>
    template <size_t Rows>
    Matrix<1, 1, DataType>::Matrix(Matrix<Rows, 1, DataType> const &matrix)
    :
        d_cell(matrix.sum())
    {}
//=
//ACCESSORS
    template <typename DataType>
    Matrix<1, 1, DataType>::operator DataType &()
    {
        return d_cell;
    }

    template <typename DataType>
    DataType &Matrix<1, 1, DataType>::get()
    {
        return d_cell;
    }
//=
    template <typename DataType>
    Matrix<1, 1, DataType>::operator DataType const &() const
    {
        return d_cell;
    }

    template <typename DataType>
    DataType const &Matrix<1, 1, DataType>::get() const
    {
        return d_cell;
    }
