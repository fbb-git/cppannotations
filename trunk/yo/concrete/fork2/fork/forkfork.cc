#include "fork.ih"

void Fork::fork() const
{
    int pid = ::fork();

    if (pid == 0)           // childprocess has pid == 0
    {
        d_redirector.childRedirections();
        d_child.run();
    }

    d_redirector.parentRedirections();
    d_parent.run(pid,
                    d_redirector.readChildCout(),
                    d_redirector.readChildCerr(),
                    d_redirector.writeChildCin());
}
