    #include "person.h"                 // given earlier

    string const &Person::name() const
    {
        return d_name;
    }
    string const &Person::address() const
    {
       return d_address;
    }
    string const &Person::phone() const
    {
       return d_phone;
    }
    size_t Person::weight() const
    {
       return d_weight;
    }
