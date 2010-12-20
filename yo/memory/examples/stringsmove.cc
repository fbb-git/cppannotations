    Strings::Strings(Strings const &&tmp)
    :
        d_memory(tmp.d_memory),
        d_size(tmp.d_size),
        d_capacity(tmp.d_capacity)
    {
        const_cast<Strings &>(tmp.d_memory) = 0;
    }
