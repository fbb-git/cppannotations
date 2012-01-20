    #include <stdlib.h>     // for qsort()

    class Date;

    class Person
    {
        public:
            size_t length() const;
            size_t mass() const;
            char const *name() const;
            char const *city() const;
            Date const &birthdate() const;

        private:
            // all necessary data members
    };

    class Person_dbase
    {
        public:
            enum Listtype
            {
                list_by_length,
                list_by_mass,
                list_by_name,
                list_by_city,
                list_by_birthday,
            };

            // ... constructors etc.

            void list(Listtype type);
                        // list the information
        private:
            struct CmpPerson
            {
                union Compare_function
                {
                    int (*persons)// comparing two Persons
                        (Person const *p1, Person const *p2);
                    int (*voids)// for qsort()
                        (void const *p1, void const *p2);
                }
                    cmp;

                #define u2c(a) static_cast<char const *(Person::*)() const>\
                        (size_t (Person::*##a)() const)

                union Person_accessor
                {
                    char const
                        *(Person::*cp)() const;
                    int
                        (Person::*i)() const;
                    Date const
                        &(Person::*d)() const;
                }
                    pf;     // to Person's access functions
            };

            static CmpPerson
                cmpPerson[];
            static Listtype
                selector;

            static int cmpstr(Person const *p1,
                              Person const *p2);

            static int cmpint(Person const *p1,
                              Person const *p2);

            static int cmpdate(Person const *p1,
                              Person const *p2);

            Person
                *pp;    // pointer to the info
            size_t
                n;      // number of persons stored.
    };

    void Person_dbase::list(Listtype type)
    {
        selector = type;
        qsort(pp, n, sizeof(Person), cmpPerson[type].cmp.voids);
        // list the sorted Person-database (to be implemented)
    }

    #define ccp(a) reinterpret_cast<char const *(Person::*)() const>(##a)

    Person_dbase::CmpPerson
        Person_dbase::cmpPerson[] =
        {
            {       // compare- and access
                    // function to compare length
                cmpint,
//                reinterpret_cast<char const *(Person::*)() const>
                        ccp(&Person::length),
            },

            {       // same for mass
                cmpint,
                reinterpret_cast<char const *(Person::*)() const>
                (&Person::mass)
            },

            {       // same for name
                cmpstr,
                &Person::name,
            },

            {       // same for city
                cmpstr,
                &Person::city,
            },

            {       // same for Date
                cmpdate,
                reinterpret_cast<char const *(Person::*)() const>
                (&Person::birthdate),
            },
        };

    int Person_dbase::cmpstr(Person const *p1, Person const *p2)
    {
        return
        (
            strcmp
            (
                (p1->*cmpPerson[selector].pf.cp)(),
                (p2->*cmpPerson[selector].pf.cp)()
            )
        );
    }

    int Person_dbase::cmpint(Person const *p1, Person const *p2)
    {
        return
        (
            (p1->*cmpPerson[selector].pf.i)()
            -
            (p2->*cmpPerson[selector].pf.i)()
        );
    }

    int Person_dbase::cmpdate(Person const *p1, Person const *p2)
    {
        return
        (
            (p1->*cmpPerson[selector].pf.d)()
            <
            (p2->*cmpPerson[selector].pf.d)() ?
                -1
            :
                (p1->*cmpPerson[selector].pf.d)()
                >
                (p2->*cmpPerson[selector].pf.d)()
        );
    }
