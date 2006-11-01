#include "pipe.ih"

void Pipe::readVia(int const *fd, size_t n)
{
    close(d_fd[WRITE]);

    for (size_t idx = 0; idx < n; idx++)
        dup(READ, fd[idx]);

    close(d_fd[READ]);
}
