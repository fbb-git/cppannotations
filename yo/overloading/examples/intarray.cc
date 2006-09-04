    #include "intarray.ih"

    IntArray::IntArray(unsigned size)
    :
        d_size(size)
    {
        if (d_size < 1)
        {
            cerr << "IntArray: size of array must be >= 1\n";
            exit(1);
        }
        d_data = new int[d_size];
    }

    IntArray::IntArray(IntArray const &other)
    {
        copy(other);
    }

    IntArray::~IntArray()
    {
        delete[] d_data;
    }

    IntArray const &IntArray::operator=(IntArray const &other)
    {
        if (this != &other)
        {
            delete[] d_data;
            copy(other);
        }
        return *this;
    }

    void IntArray::copy(IntArray const &other)
    {
        d_size = other.d_size;
        d_data = new int[d_size];
        memcpy(d_data, other.d_data, d_size * sizeof(int));
    }

    int &IntArray::operatorIndex(unsigned index) const
    {
        boundary(index);
        return d_data[index];
    }

    int &IntArray::operator[](unsigned index)
    {
        return operatorIndex(index);
    }

    int const &IntArray::operator[](unsigned index) const
    {
        return operatorIndex(index);
    }

    void IntArray::boundary(unsigned index) const
    {
        if (index >= d_size)
        {
            cerr << "IntArray: boundary overflow, index = " <<
                    index << ", should range from 0 to " << d_size - 1 << endl;
            exit(1);
        }
    }
