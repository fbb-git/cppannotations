    #include "person.ih"

    Person::Person(char const *name, char const *address, char const *phone)
    :
        d_name(strdupnew(name)),
        d_address(strdupnew(address)),
        d_phone(strdupnew(phone))
    {}
