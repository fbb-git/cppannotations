    #include "person.h"                 // given earlier

    // accessor functions ...()
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

    unsigned Person::weight() const
    {
       return d_weight;
    }
