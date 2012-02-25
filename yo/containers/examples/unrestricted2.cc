#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <bobcat/fswap>

using namespace std;
using namespace FBB;

class Data
{
    public:
        enum Tag
        {
            INT,
            STRING
        };

    private:
        union Union
        {
            int                  u_int;
            std::string          u_string;

            Union(int value);
            Union(std::string const &init);
            Union(Tag tag, Union const &other);

            ~Union();                       // no action
            void destroy(Tag myTag);        // use this instead
        
            void copy(Union const &other, Tag otag);
            bool assign(Tag myTag, Union const &other, Tag otag);
        };

        Tag d_tag;
        Union d_union;
    
    public:
            // constructors
        Data(std::string const &str);
        Data(int value);

        Data(Data const &other);
        ~Data();
        Data &operator=(Data const &rhs);
        string const &str() const;
        int value() const;
};

bool Data::Union::assign(Tag myTag, Union const &other, Tag otag)
{
    char saved[sizeof(Union)];
    memcpy(saved, this, sizeof(Union));
    bool ret = true;
    try
    {
        copy(other, otag);
        fswap(*this, *reinterpret_cast<Union *>(saved));
        destroy(myTag);
    }
    catch (...)
    {
        ret = false;
    }
    memcpy(this, saved, sizeof(Union));        // roll back
}

Data::Union::Union(Tag tag, Union const &other)
{
    copy(other, tag);
}

void Data::Union::destroy(Tag myTag)
{
    if (myTag == Tag::STRING)
        u_string.~string();
}

void Data::Union::copy(Union const &other, Tag otag)
{
    if (otag == INT)
        u_int = other.u_int;
    else
        new (this) string(other.u_string);
}

inline Data::Union::~Union()
{};
inline Data::Union::Union(int value)
:
    u_int(value)
{}
inline Data::Union::Union(std::string const &str)
:
    u_string(str)
{}


Data::Data(Data const &other)
:
    d_tag(other.d_tag),
    d_union(d_tag, other.d_union)
{}

    // destructor
Data::~Data()
{
    d_union.destroy(d_tag);
}

    // overloaded assignment operator
Data &Data::operator=(Data const &rhs)
{
    if (d_union.assign(d_tag, rhs.d_union, rhs.d_tag))
        d_tag = rhs.d_tag;
}

        // accessors
inline string const &Data::str() const
{
    return d_union.u_string;
}
inline int Data::value() const
{
    return d_union.u_int;
}

Data::Data(std::string const &str)
:
    d_tag(STRING),
    d_union(str)
{}
Data::Data(int value)
:
    d_tag(INT),
    d_union(value)
{}

int main(int argc, char **argv)
{
    Data v(2);

    cout << v.value() << '\n';

    Data a("hi");
    Data b("lo");

    cout << a.str() << ' ' << b.str() << '\n';

    a = b;

    cout << a.str() << ' ' << b.str() << '\n';

    a = v;

    cout << v.value() << '\n';

    a = b;

    cout << a.str() << ' ' << b.str() << '\n';

    a = a;

    cout << a.str() << ' ' << b.str() << '\n';


}






