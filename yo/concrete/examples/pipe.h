//HEAD
    class Pipe
    {
        enum    RW { READ, WRITE };
        int     d_fd[2];
//=
        public:
            Pipe();
            int readOnly();
            void readFrom(int fileDescriptor);
            int writeOnly();
            void writtenBy(int fileDescriptor);
            void writtenBy(int const *fileDescriptors, unsigned n = 2);
        private:
            void redirect(int d_fd, int alternateFd);
    };
