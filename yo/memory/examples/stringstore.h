    #include <string>

//STRINGSTORE
    class StringStore
    {
        std::string *d_string;
        size_t d_size;

        public:
            StringStore();
            StringStore(char const *const *cStrings, size_t n);
            ~StringStore();

            std::string const &at(size_t idx) const;
            size_t size() const;
    };
//=
