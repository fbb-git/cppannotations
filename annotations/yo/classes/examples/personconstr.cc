    COMMENT(
Also note that
the example doesn't show where the destructor is called; this action occurs
implicitly when the below function tt(main()) terminates and hence when its
local variable tt(p) ceases to exist.



    When tt(printperson()) receives a fully defined tt(Person) object (i.e.,
containing a name, address and phone number), the data are correctly printed.
However, when a tt(Person) object is only partially filled, e.g. with only a
name, tt(printperson()) passes 0-pointers to tt(cout). This unesthetic
feature can be remedied with a little more code:

verb(
    void printperson(Person const &p)
    {
        if (p.name())
            cout << "Name   : " << p.name() << "\n";
        if (p.address())
            cout << "Address : " << p.address() << "\n";
        if (p.phone())
            cout << "Phone  : " << p.phone() << "\n";
    }
)
Alternatively, the constructor tt(Person::Person()) might initialize the
members to `printable defaults', like tt(" ** undefined ** ").



    The destructor, constructor and the class definition are given below.

verb(
    // class definition
    class Person
    {
        public:
            Person();          // constructor
            ~Person();         // destructor

            // functions to set fields
            void setName(string const &n);
            void setAddress(string const &a);
            void setPhone(string const &p);

            // functions to inspect fields
            string const &name() const;
            string const &address() const;
            string const &phone() const;

        private:
            char *name;             // name of person
            char *address;          // address field
            char *phone;            // telephone number
    };

    // constructor
    Person::Person()
    {
        name = 0;
        address = 0;
        phone = 0;
    }

    // destructor
    Person::~Person()
    {
        free(name);
        free(address);
        free(phone);
    }
)
END COMMENT)
