    #include <iostream>
    #include <string>
    #include <hash_map>

    class Equal
    {
        public:
            size_t operator()(string const &s1, string const &s2) const
            {
                return (s1 == s2);
            }
    };

    class hashString
    {
        public:
            size_t operator()(string const &str) const
            {
                hash<char const *>
                    h;

                return (h(str.c_str()));
            }
    };

    int main()
    {
        hash_map
        <
            string,
            int,
            hashString,
            Equal
        >
            months;

        months["january"] = 31;
        months["february"] = 28;
        months["march"] = 31;
        months["april"] = 30;
        months["may"] = 31;
        months["june"] = 30;
        months["july"] = 31;
        months["august"] = 31;
        months["september"] = 30;
        months["october"] = 31;
        months["november"] = 30;
        months["december"] = 31;

        cout << "february -> " << months["february"] << endl <<
                "april     -> " << months["april"] << endl <<
                "june      -> " << months["june"] << endl <<
                "november  -> " << months["november"] << endl <<
                "december  -> " << months["december"] << endl;

        return (0);
    }
