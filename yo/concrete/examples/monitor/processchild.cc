    #include "monitor.ih"
//CHILD
    void Monitor::processChild(int fd)
    {
        ifdstreambuf ifdbuf(fd);
        istream istr(&ifdbuf);
        string line;

        getline(istr, line);
        cout << d_child[fd]->pid() << ": " << line << endl;
    }
//=
