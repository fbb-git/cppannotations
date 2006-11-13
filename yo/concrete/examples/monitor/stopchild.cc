    #include "monitor.ih"

//STOP
    void Monitor::stopChild(int nr, string const &)
    {
        map<int, Child *>::iterator it =
            find_if(d_child.begin(), d_child.end(), Find(nr));

        if (it == d_child.end())
            cerr << "No child number " << nr << endl;
        else
        {
            d_selector.rmReadFd(it->second->readFd());

            delete it->second;
            d_child.erase(it);
        }
    }
//=
