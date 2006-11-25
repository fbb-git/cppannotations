    class Person
    {
        char *d_name;
        char *d_address;
        char *d_phone;

        public:
            Person();
            Person(char const *name, char const *address,
                   char const *phone);
            ~Person();

            char const *name() const;
            char const *address() const;
            char const *phone() const;
    };

	inline Person::Person()
	{}

/*
    person.ih contains:

    #include "person.h"
    char const *strdupnew(char const *org);
*/
