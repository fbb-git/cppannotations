    #include "monitor.ih"
//CHILD
    void Monitor::processChild(int fd)
    {
        IFdStreambuf ifdbuf(fd);
        istream istr(&ifdbuf);
        string line;

        getline(istr, line);
        cout << d_child[fd]->pid() << ": " << line << '\n';
    }
//=
