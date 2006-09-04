    #include "scanner.ih"

    void Scanner::throwOnCircularInclusion()
    {
        vector<string>::iterator
            it = find(d_fileName.begin(), d_fileName.end(), d_nextSource);

        if (it != d_fileName.end())
            throw circularInclusion;
    }
