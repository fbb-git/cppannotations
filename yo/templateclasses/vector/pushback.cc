    template <typename T>
    T &Vector<T>::operator[](unsigned index) throw(char const *)
    {
        if (index >= (beyond - data))
            throw "Vector array index out of bounds";
        return data[index];
    }
