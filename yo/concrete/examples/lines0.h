    #include <string>
    #include <fstream>

//LINES
    class Lines
    {
        std::vector<std::string> d_line;
    
        public:
            Lines(std::istream &in);
            std::std::string &operator[](size_t idx);
    };
//=
