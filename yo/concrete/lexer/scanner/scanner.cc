    #include "scanner.ih"

    Scanner::Scanner(istream *yyin, string const &initialName)
    {
        switch_streams(yyin, yyout);
        d_fileInfo.push_back(FileInfo(initialName, false));
    }
