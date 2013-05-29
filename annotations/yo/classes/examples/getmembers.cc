    #include "person.h"                 // given earlier
    using namespace std;

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
    size_t Person::mass() const
    {
       return d_mass;
    }
