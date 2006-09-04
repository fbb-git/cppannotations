    #include "scanner.ih"

    void Scanner::stackTrace()
    {
        for (unsigned idx = 0; idx < d_fileName.size() - 1; ++idx)
            cerr << idx << ": " << d_fileName[idx]  << " included " <<
                                    d_fileName[idx + 1]  << endl;
    }
