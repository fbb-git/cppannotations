    #include "monitor.ih"

//  void Monitor::killChild(map<int, Child *>::value_type it)
//  {
//      if (kill(it.second->pid(), SIGTERM))
//          cerr << "Couldn't kill process " << it.second->pid() << '\n';
//  }

//KILL
    void Monitor::killChild(map<int, Child *>::value_type it)
    {
        if (kill(it.second->pid(), SIGTERM))
            cerr << "Couldn't kill process " << it.second->pid() << '\n';

        // reap defunct child process
        int status = 0;
        while( waitpid( it.second->pid(), &status, WNOHANG) > -1)
        {};
    }
//=
//EXIT
    void Monitor::exiting(int value, string const &msg)
    {
        for_each(d_child.begin(), d_child.end(), killChild);
        if (msg.length())
            cerr << msg << '\n';
        throw value;
    }
//=
//INIT
    void (Monitor::*Monitor::s_handler[sizeofCommands])(int, string const &);

    void Monitor::initialize()
    {
        if (s_handler[UNKNOWN] != 0)    // already initialized
            return;

        s_handler[UNKNOWN] =    &Monitor::unknown;
        s_handler[START] =      &Monitor::createNewChild;
        s_handler[EXIT] =       &Monitor::exiting;
        s_handler[STOP] =       &Monitor::stopChild;
        s_handler[TEXT] =       &Monitor::sendChild;
    }
//=
