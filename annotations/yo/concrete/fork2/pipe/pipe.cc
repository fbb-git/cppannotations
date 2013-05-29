#include "pipe.ih"

Pipe::Pipe()
{
    if (pipe(d_fd))
        throw bad_pipe();
}
