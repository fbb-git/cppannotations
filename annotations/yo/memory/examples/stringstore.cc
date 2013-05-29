    #include "strings.ih"

//CONS
    Strings::Strings()
    :
        d_string(0),
        d_size(0)
    {}

    Strings::Strings(char const *const *cStrings, size_t size)
    :
        d_string(new string[size]),
        d_size(size)
    {
        for (size_t idx = 0; idx != size; ++idx)
            d_string[idx] = cStrings[idx];
    }
//=

//DESTR
    Strings::~Strings()
    {
        delete[] d_string;
    }
//=
