    #include <string>

    class Person
    {
        std::string d_name;     // name of person
        std::string d_address;  // address field
        std::string d_phone;    // telephone number
        unsigned    d_weight;   // the weight in kg.

        public:                 // interface functions
            void setName(std::string const &n);
            void setAddress(std::string const &a);
            void setPhone(std::string const &p);
            void setWeight(unsigned weight);

            std::string const &name()    const;
            std::string const &address() const;
            std::string const &phone()   const;
            unsigned weight()            const;
    };
