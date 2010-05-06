    #include <iostream>

    class oformstream: public std::ostream              // 1
    {
        public:
            oformstream(std::ostream &ostr)             // 2
            :
                std::ostream(ostr.rdbuf())
            {}

            std::ostream &form(char const *fmt, ...);   // 3

    };
