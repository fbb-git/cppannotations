    #include "scanner.ih"

    void Scanner::stackTrace()
    {
        for (size_t idx = 0; idx < d_fileInfo.size() - 1; ++idx)
            cerr << idx << ": " << d_fileInfo[idx].d_name  << " included " <<
                                    d_fileInfo[idx + 1].d_name  << '\n';
    }
