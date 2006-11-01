    #include "person.h"                 // given earlier

    // interface functions set...()
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

    void Person::setWeight(size_t weight)
    {
        d_weight = weight;
    }
