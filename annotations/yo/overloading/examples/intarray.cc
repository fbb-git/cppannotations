    #include "intarray.ih"

    IntArray::IntArray(size_t size)
    :
        d_size(size)
    {
        if (d_size < 1)
            throw string("IntArray: size of array must be >= 1");

        d_data = new int[d_size];
    }

    IntArray::IntArray(IntArray const &other)
    :
        d_size(other.d_size),
        d_data(new int[d_size])
    {
        memcpy(d_data, other.d_data, d_size * sizeof(int));
    }

    IntArray::~IntArray()
    {
        delete[] d_data;
    }

    IntArray const &IntArray::operator=(IntArray const &other)
    {
        IntArray tmp(other);
        swap(tmp);
        return *this;
    }

    int &IntArray::operatorIndex(size_t index) const
    {
        boundary(index);
        return d_data[index];
    }

    int &IntArray::operator[](size_t index)
    {
        return operatorIndex(index);
    }

    int const &IntArray::operator[](size_t index) const
    {
        return operatorIndex(index);
    }

    void IntArray::boundary(size_t index) const
    {
        if (index < d_size)
            return;
        ostringstream out;
        out  << "IntArray: boundary overflow, index = " <<
                index << ", should be < " << d_size << '\n';
        throw out.str();
    }
