#include "pipe.ih"

void Pipe::writeVia(int const *fd, unsigned n)
{
    close(d_fd[READ]);

    for (unsigned idx = 0; idx < n; idx++)
        dup(WRITE, fd[idx]);

    close(d_fd[WRITE]);
}
