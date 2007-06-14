    class Support
    {
        std::ostream &d_out;
        std::string d_letters;

        public:
            Support(std::ostream &out, char const *letters);
            void operator()(std::string &str) const;
    };

    inline Support::Support(std::ostream &out, char const *letters)
    :
        d_out(out),
        d_letters(letters)
    {}

    inline void Support::operator()(std::string &str) const
    {
        d_out << str << " ";

        for
        (
            std::string::iterator strIter = str.begin();
                strIter != str.end();
                    ++strIter
        )
        {
            if (d_letters.find(*strIter) != std::string::npos)
                *strIter = toupper(*strIter);
        }
        d_out << str << std::endl;
    }
