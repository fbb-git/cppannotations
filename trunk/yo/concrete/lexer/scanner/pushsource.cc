    #include "scanner.ih"

    void Scanner::pushSource(yy_buffer_state *current, size_t size)
    {
        if (d_state.size() == s_maxDepth)
            throw nestingTooDeep;

        throwOnCircularInclusion();
        d_fileInfo.push_back(FileInfo(d_nextSource));

        ifstream *newStream = d_fileInfo.back().d_in;

        if (!*newStream)
            throw cantRead;

        d_state.push(current);
        yy_switch_to_buffer(yy_create_buffer(newStream, size));
    }
