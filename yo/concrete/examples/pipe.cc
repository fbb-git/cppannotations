    #include "pipe.h"
    #include <unistd.h>

//CONS
    Pipe::Pipe()
    {
        if (pipe(d_fd))
            throw "Pipe::Pipe(): pipe() failed";
    }
//=
//REDIRECT
    void Pipe::redirect(int d_fd, int alternateFd)
    {
        if (dup2(d_fd, alternateFd) < 0)
            throw "Pipe: redirection failed";
    }
//=
//READ
    int Pipe::readOnly()
    {
        close(d_fd[WRITE]);
        return d_fd[READ];
    }
    void Pipe::readFrom(int fd)
    {
        readOnly();

        redirect(d_fd[READ], fd);
        close(d_fd[READ]);
    }
//=
//WRITE
    int Pipe::writeOnly()
    {
        close(d_fd[READ]);
        return d_fd[WRITE];
    }
    void Pipe::writtenBy(int fd)
    {
        writtenBy(&fd, 1);
    }
    void Pipe::writtenBy(int const *fd, unsigned n)
    {
        writeOnly();

        for (int idx = 0; idx < n; idx++)
            redirect(d_fd[WRITE], fd[idx]);

        close(d_fd[WRITE]);
    }
//=
