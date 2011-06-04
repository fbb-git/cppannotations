    Selector's member functions serve the following tasks:
    itemization(
    itht(Selector)(Selector()): the (default) constructor. It
clears the read, write, and execute tt(fd_set) variables, and switches off the
alarm. Except for tt(d_max), the remaining data members do not require
specific initializations:
        verbinsert(SELECTOR)(examples/selector.cc)
    itht(wait)(int wait()): this member em(blocks) until the em(alarm) times
out or until activity is sensed at any of the file descriptors monitored by
the tt(Selector) object. It throws an exception when the tt(select) system
call itself fails:
        verbinsert(WAIT)(examples/selector.cc)
    itht(nReady)(int nReady): this member function's return value is only
defined when tt(wait) has returned. In that case it returns 0 for an
alarm-timeout, -1 if tt(select) failed, and otherwise the number of file
descriptors on which activity was sensed:
        verbinsert(NREADY)(examples/selector.h)
    itht(readFd)(int readFd()): this member function's return
value is also only defined after tt(wait) has returned. Its return value is
-1 if no (more) input file descriptors are available. Otherwise the next file
descriptor available for reading is returned:
        verbinsert(READFD)(examples/selector.h)
    itht(writeFd)(int writeFd()): operating analogously to tt(readFd), it
returns the next file descriptor to which output is written.  It uses
tt(d_writeidx) and tt(d_ret_read) and is implemented analogously to
tt(readFd);
    itht(exceptFd)(int exceptFd()): operating analogously to tt(readFd), it
returns the next exception file descriptor on which activity was sensed.  It
uses tt(d_except_idx) and tt(d_ret_except) and is implemented analogously to
tt(readFd);
    itht(setAlarm)(void setAlarm(int sec, int usec = 0)): this member
activates tt(Select)'s alarm facility. At least the number of seconds to wait
for the alarm to go off must be specified. It simply assigns values to
tt(d_alarm)'s fields. At the next tt(Select::wait) call, the alarm will fire
(i.e., tt(wait) returns with return value 0) once the configured
alarm-interval has passed:
        verbinsert(SETALARM)(examples/selector.h)
    itht(noAlarm)(void noAlarm()): this member switches off the alarm, by
simply setting the alarm interval to a very long period:
        verbinsert(NOALARM)(examples/selector.h)
    itht(addReadFd)(void addReadFd(int fd)): this member adds a
file descriptor to the set of input file descriptors monitored by the
tt(Selector) object. The member function tt(wait) will return once input is
available at the indicated file descriptor:
        verbinsert(ADDREAD)(examples/selector.h)
    itht(addWriteFd)(void addWriteFd(int fd)): this member adds a file
descriptor to the set of output file descriptors monitored by the tt(Selector)
object. The member function tt(wait) will return once output is available at
the indicated file descriptor. Using tt(d_write), it is implemented
analogously to tt(addReadFd);
    itht(addExceptFd)(void addExceptFd(int fd)): this member adds a file
descriptor to the set of exception file descriptors to be monitored by the
tt(Selector) object.  The member function tt(wait) will return once activity
is sensed at the indicated file descriptor. Using tt(d_except), it is
implemented analogously to tt(addReadFd);
    itht(rmReadFd)(void rmReadFd(int fd)): this member removes a file
descriptor from the set of input file descriptors monitored by the
tt(Selector) object:
        verbinsert(RMREAD)(examples/selector.h)
    itht(rmWriteFd)(void rmWriteFd(int fd)): this member removes a file
descriptor from the set of output file descriptors monitored by the
tt(Selector) object.  Using tt(d_write), it is implemented analogously to
tt(rmReadFd);
    itht(rmExceptFd)(void rmExceptFd(int fd)): this member removes a file
descriptor from the set of exception file descriptors to be monitored by the
tt(Selector) object.  Using tt(d_except), it is implemented analogously to
tt(rmReadFd);
    )
    The class's remaining (two) members are support members, and should not be
used by non-member functions. Therefore, they are declared in the class's
tt(private) section:
    itemization(
    it() The member tt(addFd) adds a file descriptor to a tt(fd_set):
        verbinsert(ADDFD)(examples/selector.cc)
    it() The member tt(checkSet) tests whether a file descriptor (tt(*index))
is found in a tt(fd_set):
        verbinsert(CHECKSET)(examples/selector.cc)
    )
