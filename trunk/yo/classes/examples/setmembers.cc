    #include "person.h"                 // given earlier

    void Person::setName(string const &name)
    {
        d_name = name;
    }
    void Person::setAddress(string const &address)
    {
        d_address = address;
    }
    void Person::setPhone(string const &phone)
    {
        d_phone = phone;
    }
    void Person::setMass(size_t mass)
    {
        d_mass = mass;
    }
