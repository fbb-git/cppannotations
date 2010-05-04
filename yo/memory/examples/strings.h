    #include <string>

//STRINGSTORE
    class Strings
    {
        std::string *d_string;
        size_t d_size;

        public:
            Strings();
            Strings(char const *const *cStrings, size_t n);
            ~Strings();

            std::string const &at(size_t idx) const;
            size_t size() const;
    };
//=
