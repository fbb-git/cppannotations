    class Support
    {
        std::ostream &d_out;

        public:
            Support(std::ostream &out)
            :
                d_out(out)
            {}

            void operator()(std::string &str) const
            {
                d_out << str << " ";
                transform(str.begin(), str.end(), str.begin(), toupper);
                d_out << str << std::endl;
            }
    };
