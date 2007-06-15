    #include "monitor.ih"
//SEND
    void Monitor::sendChild(int nr, string const &line)
    {
        map<int, Child *>::iterator it =
            find_if(d_child.begin(), d_child.end(), Find(nr));

        if (it == d_child.end())
            cerr << "No child number " << nr << endl;
        else
        {
            ofdnstreambuf ofdn(it->second->writeFd());
            ostream out(&ofdn);

            out << line << endl;
        }
    }
//=
