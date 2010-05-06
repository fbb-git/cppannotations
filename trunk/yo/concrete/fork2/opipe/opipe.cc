#include "opipe.ih"

OPipe::OPipe(size_t size)
:
    Pipe(),
    OFdNStreambuf(Pipe::d_fd[READ], size == 0 ? 1 : size),
    ostream(this)
{}
