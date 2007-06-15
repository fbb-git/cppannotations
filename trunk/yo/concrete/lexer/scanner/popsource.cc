    #include "scanner.ih"

    bool Scanner::popSource(yy_buffer_state *current)
    {
        if (d_state.empty())
            return false;

        yy_delete_buffer(current);
        yy_switch_to_buffer(d_state.top());
        d_state.pop();
        d_fileName.pop_back();

        return true;
    }
