#include "pipe.ih"

void Pipe::dup(RW rw, int fd)
{
    if (dup2(d_fd[rw], fd) < 0)
        throw redirection_failed();
}
