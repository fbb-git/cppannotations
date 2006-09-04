#include "pipe.ih"

void Pipe::readVia(int const *fd, unsigned n)
{
    close(d_fd[WRITE]);

    for (unsigned idx = 0; idx < n; idx++)
        dup(READ, fd[idx]);

    close(d_fd[READ]);
}
