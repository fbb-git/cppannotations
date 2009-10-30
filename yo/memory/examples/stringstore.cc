    #include "stringstore.ih"

//CONS
    StringStore::StringStore()
    :
        d_string(0),
        d_size(0)
    {}

    StringStore::StringStore(char const *const *cStrings, size_t size)
    :
        d_string(new string[size]),
        d_size(size)
    {
        for (size_t idx = 0; idx != size; ++idx)
            d_string[idx] = cStrings[idx];
    }
//=

//DESTR
    StringStore::~StringStore()
    {
        delete[] d_string;
    }
//=
