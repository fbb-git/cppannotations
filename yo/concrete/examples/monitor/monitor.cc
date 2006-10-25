    #include "monitor.ih"

//WAIT
    void Monitor::waitForChild(int signum)
    {
        cerr << "Won't wait for child\n";

        int status;
        wait(&status);

        signal(SIGCHLD, waitForChild);
    }
//=
//KILL
    void Monitor::killChild(map<int, Child *>::value_type it)
    {
        if (kill(it.second->pid(), SIGTERM))
            cerr << "Couldn't kill process " << it.second->pid() << endl;
    }
//=
//EXIT
    void Monitor::exiting(int, string const &)
    {
        for_each(d_child.begin(), d_child.end(), killChild);
        exit(0);
    }
//=







