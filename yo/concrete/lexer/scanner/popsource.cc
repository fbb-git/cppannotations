    #include "scanner.ih"

    bool Scanner::popSource(yy_buffer_state *current)
    {
        if (d_state.empty())
            return false;

        yy_delete_buffer(current);
        yy_switch_to_buffer(d_state.top());
        d_state.pop();

        delete d_fileInfo.back().d_in;      // closes the stream as well
        d_fileInfo.pop_back();

        return true;
    }
