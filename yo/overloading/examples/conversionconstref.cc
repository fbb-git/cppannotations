    #include <string>

    class XString
    {
        std::string d_s;

        public:
            operator std::string const &() const
            {
                return d_s;
            }
    };

    int main()
    {
        XString x;
        std::string s;

        s = x;
    };
