#include "opipe.ih"

OPipe::OPipe(unsigned size)
:
    Pipe(),
    OFdNStreambuf(Pipe::d_fd[READ], size == 0 ? 1 : size),
    ostream(this)
{}
