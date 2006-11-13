    #ifndef _INCLUDED_SELECTOR_H_
    #define _INCLUDED_SELECTOR_H_
//HEADERS
    #include <limits.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/types.h>
//=
//CLASS
    class Selector
    {
        fd_set          d_read;
        fd_set          d_write;
        fd_set          d_except;
        fd_set          d_ret_read;
        fd_set          d_ret_write;
        fd_set          d_ret_except;
        timeval         d_alarm;
        int             d_max;
        int             d_ret;
        int             d_readidx;
        int             d_writeidx;
        int             d_exceptidx;

        public:
            Selector();

            int wait();
            int nReady();
            int readFd();
            int writeFd();
            int exceptFd();
            void setAlarm(int sec, int usec = 0);
            void noAlarm();
            void addReadFd(int fd);
            void addWriteFd(int fd);
            void addExceptFd(int fd);
            void rmReadFd(int fd);
            void rmWriteFd(int fd);
            void rmExceptFd(int fd);

        private:
            int checkSet(int *index, fd_set &set);
            void addFd(fd_set *set, int fd);
    };
//=

//NREADY
    inline int Selector::nReady()
    {
        return d_ret;
    }
//=
//READFD
    inline int Selector::readFd()
    {
        return checkSet(&d_readidx, d_ret_read);
    }
//=
    inline int Selector::writeFd()
    {
        return checkSet(&d_writeidx, d_ret_write);
    }
    inline int Selector::exceptFd()
    {
        return checkSet(&d_exceptidx, d_ret_except);
    }
//SETALARM
    inline void Selector::setAlarm(int sec, int usec)
    {
        d_alarm.tv_sec  = sec;
        d_alarm.tv_usec = usec;
    }
//=
//NOALARM
    inline void Selector::noAlarm()
    {
        setAlarm(INT_MAX, INT_MAX);
    }
//=
//ADDREAD
    inline void Selector::addReadFd(int fd)
    {
        addFd(&d_read, fd);
    }
//=
    inline void Selector::addWriteFd(int fd)
    {
        addFd(&d_write, fd);
    }
    inline void Selector::addExceptFd(int fd)
    {
        addFd(&d_except, fd);
    }
//RMREAD
    inline void Selector::rmReadFd(int fd)
    {
        FD_CLR(fd, &d_read);
    }
//=
    inline void Selector::rmWriteFd(int fd)
    {
        FD_CLR(fd, &d_write);
    }
    inline void Selector::rmExceptFd(int fd)
    {
        FD_CLR(fd, &d_except);
    }

    #endif
