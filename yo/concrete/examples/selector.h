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
//=
        public:
            Selector();

            int wait();
//NREADY
            int nReady()
            {
                return d_ret;
            }
//=
//READFD
            int readFd()
            {
                return checkSet(&d_readidx, d_ret_read);
            }
//=
            int writeFd()
            {
                return checkSet(&d_writeidx, d_ret_write);
            }
            int exceptFd()
            {
                return checkSet(&d_exceptidx, d_ret_except);
            }
//SETALARM
            void setAlarm(int sec, int usec = 0)
            {
                d_alarm.tv_sec  = sec;
                d_alarm.tv_usec = usec;
            }
//=
//NOALARM
            void noAlarm()
            {
                setAlarm(INT_MAX, INT_MAX);
            }
//=
//ADDREAD
            void addReadFd(int fd)
            {
                addFd(&d_read, fd);
            }
//=
            void addWriteFd(int fd)
            {
                addFd(&d_write, fd);
            }
            void addExceptFd(int fd)
            {
                addFd(&d_except, fd);
            }
//RMREAD
            void rmReadFd(int fd)
            {
                FD_CLR(fd, &d_read);
            }
//=
            void rmWriteFd(int fd)
            {
                FD_CLR(fd, &d_write);
            }
            void rmExceptFd(int fd)
            {
                FD_CLR(fd, &d_except);
            }
        private:
            int checkSet(int *index, fd_set &set);
            void addFd(fd_set *set, int fd);
    };

    #endif
