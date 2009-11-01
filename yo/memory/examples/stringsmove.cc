    Strings::Strings(Strings &&tmp)
    :
        d_string(tmp.d_string),
        d_size(tmp.d_size)
    {
        tmp.d_string = 0;
    }
