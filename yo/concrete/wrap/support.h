    class Support
    {
        std::ostream &d_out;

        public:
            Support(std::ostream &out);
            void operator()(std::string &str) const;
    };

    inline Support::Support(std::ostream &out)
    :
        d_out(out)
    {}

    inline void Support::operator()(std::string &str) const
    {
        d_out << str << " ";
        transform(str.begin(), str.end(), str.begin(), toupper);
        d_out << str << std::endl;
    }
