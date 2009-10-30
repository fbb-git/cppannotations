    #include <string>

//STRINGSTORE
    class StringStore
    {
        std::string *d_string;
        size_t d_size;

        public:
            StringStore();
            StringStore(std::string const *strings, size_t n);
            ~StringStore();

            std::string const &at() const;
    };
//=
