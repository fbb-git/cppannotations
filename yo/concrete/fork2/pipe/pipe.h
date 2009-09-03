#ifndef INCLUDED_PIPE_H_
#define INCLUDED_PIPE_H_

#include <cstddef>

namespace FBB
{
    class Pipe
    {
        protected:
            int d_fd[2];

        public:
            enum bad_pipe {};
            enum redirection_failed {};

            Pipe();
            Pipe(int socket)
            {
                d_fd[READ] = socket;
                d_fd[WRITE] = socket;
            }
            Pipe(int const *fd)
            {
                d_fd[READ] = fd[READ];
                d_fd[WRITE] = fd[WRITE];
            }

            // readVia():   set up redirection from d_fd[READ] to the given
            //              filedescriptor(s): reading from d_fd[READ]
            //              is done via the filedescriptor(s)
            void readVia(int filedescriptor);
            // not tested:
            void readVia(int const *filedescriptor, size_t n);

            // writeVia():  set up redirection from d_fd[WRITE] to the given
            //              filedescriptor(s): writing to d_fd[WRITE]
            //              is done via the filedescriptor(s)
            void writeVia(int filedescriptor);
            void writeVia(int const *filedescriptor, size_t n = 2);

            int readFd()
            {
                return d_fd[READ];
            }
            int writeFd()
            {
                return d_fd[WRITE];
            }

        protected:
            enum  RW { READ, WRITE };

        private:
            void dup(RW rw, int fd);

            Pipe(Pipe const &other);                // NI
            Pipe &operator=(Pipe const &other);     // NI
    };
}

#endif
