    #include "person.ih"

    Person::~Person()
    {
        delete d_name;
        delete d_address;
        delete d_phone;
    }
