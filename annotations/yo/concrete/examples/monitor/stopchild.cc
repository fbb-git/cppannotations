    #include "monitor.ih"

//STOP
    void Monitor::stopChild(int nr, string const &)
    {
        auto it = find_if(d_child.begin(), d_child.end(), Find{ nr });

        if (it == d_child.end())
            cerr << "No child number " << nr << '\n';
        else
        {
            d_selector.rmReadFd(it->second->readFd());
            d_child.erase(it);
        }
    }
//=
