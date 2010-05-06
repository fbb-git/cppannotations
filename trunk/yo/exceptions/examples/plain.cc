    #include <cstddef>

    class Composed
    {};

    class Incomplete2
    {
        Composed d_composed;
        char *d_cp;         // plain pointers
        int *d_ip;

        public:
            Incomplete2(size_t nChars, size_t nInts)
            try
            :
                d_composed(/* arguments */),    // might throw
                d_cp(0),
                d_ip(0)
            {
                preamble();                     // might throw
                d_cp = new char[nChars];        // might throw
                d_ip = new int[nChars];         // might throw
                postamble();                    // might throw
            }
            catch (...)
            {
                delete[] d_cp;                  // clean up
                delete[] d_ip;
            }
        private:
            void preamble();
            void postamble();
    };
