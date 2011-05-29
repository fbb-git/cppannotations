    Strings::Strings(Strings &&tmp)
    :
        d_memory(tmp.d_memory),
        d_size(tmp.d_size),
        d_capacity(tmp.d_capacity)
    {
        tmp.d_memory = 0;
    }
