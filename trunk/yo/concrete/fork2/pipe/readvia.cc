#include "pipe.ih"

void Pipe::readVia(int fd)
{
    close(d_fd[WRITE]);
    dup(READ, fd);
    close(d_fd[READ]);
}
