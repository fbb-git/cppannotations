    #include "selector.h"

//SELECTOR
    Selector::Selector()
    {
        FD_ZERO(&d_read);
        FD_ZERO(&d_write);
        FD_ZERO(&d_except);
        noAlarm();
        d_max = 0;
    }
//=
//WAIT
    int Selector::wait()
    {
        timeval t = d_alarm;

        d_ret_read = d_read;
        d_ret_write = d_write;
        d_ret_except = d_except;

        d_readidx = 0;
        d_writeidx = 0;
        d_exceptidx = 0;

        d_ret = select(d_max, &d_ret_read, &d_ret_write, &d_ret_except, 
                       t.tv_sec == -1 && t.tv_usec == -1 ? 0 : &t);

        if (d_ret < 0)
            throw "Selector::wait()/select() failed";

        return d_ret;
    }
//=
//ADDFD
    void Selector::addFd(fd_set *set, int fd)
    {
        FD_SET(fd, set);
        if (fd >= d_max)
            d_max = fd + 1;
    }
//=
//CHECKSET
    int Selector::checkSet(int *index, fd_set &set)
    {
        int &idx = *index;

        while (idx < d_max && !FD_ISSET(idx, &set))
            ++idx;

        return idx == d_max ? -1 : idx++;
    }
//=
