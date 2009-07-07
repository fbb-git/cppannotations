    #include "scanner.ih"

    inline bool operator==(Scanner::FileInfo const &fi, string const &name)
    {
        return fi.d_name == name;
    }

    void Scanner::throwOnCircularInclusion()
    {
        vector<FileInfo>::iterator
            it = find(d_fileInfo.begin(), d_fileInfo.end(), d_nextSource);

        if (it != d_fileInfo.end())
            throw circularInclusion;
    }

