#include "pipe.ih"

void Pipe::writeVia(int fd)
{
    close(d_fd[READ]);
    dup(WRITE, fd);
    close(d_fd[WRITE]);
}
