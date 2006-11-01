#include "pipe.ih"

void Pipe::writeVia(int const *fd, size_t n)
{
    close(d_fd[READ]);

    for (size_t idx = 0; idx < n; idx++)
        dup(WRITE, fd[idx]);

    close(d_fd[WRITE]);
}
