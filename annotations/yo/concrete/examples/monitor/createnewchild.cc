    #include "monitor.ih"

//CHILD
    void Monitor::createNewChild(int, string const &)
    {
        Child *cp = new Child(++d_nr);

        cp->fork();

        int fd = cp->readFd();

        d_selector.addReadFd(fd);
        d_child[fd].reset(cp);

        cerr << "Child " << d_nr << " started\n";
    }
//=
