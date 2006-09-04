#include "scanner.ih"

void Scanner::performSwitch(yy_buffer_state *current, unsigned size)
{
    if (d_state.size() == s_maxDepth)
        throw nestingTooDeep;

    throwOnCircularInclusion();
    d_fileName.push_back(d_nextSource);

    ifstream *newStream = new ifstream(d_nextSource.c_str());

    if (!*newStream)
        throw cantRead;

    d_state.push(current);
    yy_switch_to_buffer(yy_create_buffer(newStream, size));
}
