#include <iostream>
#include <string>
#include <algorithm>

#include <bobcat/fswap>

using namespace std;
using namespace FBB;

struct Data
{
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

            Union(Union const &other) = delete;
            Union &operator=(Union const &other) = delete;

            Union(Union const &other, Tag tag);
            Union(Union &&tmp, Tag tag);

            ~Union();                       // no action
            void destroy(Tag myTag);        // use this instead

            void assign(Tag myTag, Union const &other, Tag otag);
            void assign(Tag myTag, Union &&tmp, Tag otag);

            void swap(Tag myTag, Union &other, Tag otag);

            private:
                void copy(Union const &other, Tag tag);
                void copy(Union &&other, Tag tag);
        };

        Tag d_tag;
        Union d_union;

    public:
            // constructors
        Data(std::string const &str);
        Data(int value);

        Data(Data const &other);
        Data(Data &&tmp);
        ~Data();
        Data &operator=(Data const &rhs);
        Data &operator=(Data &&rhs);

        string const &str() const;
        int value() const;
};

void Data::Union::swap(Tag myTag, Union &other, Tag oTag)
{
    Union tmp(*this, myTag);

    destroy(myTag);
    copy(other, oTag);

    other.destroy(oTag);
    other.copy(tmp, myTag);
}

void Data::Union::assign(Tag myTag, Union const &other, Tag otag)
{
    char saved[sizeof(Union)];
    memcpy(saved, this, sizeof(Union));         // raw copy: saved <- *this
    try
    {
        copy(other, otag);                      // *this = other: may throw
                                                // *this <-> saved
        fswap(*this, *reinterpret_cast<Union *>(saved));
        destroy(myTag);                         // destroy original *this
        memcpy(this, saved, sizeof(Union));     // install new *this
    }
    catch (...)                                 // copy threw
    {
        memcpy(this, saved, sizeof(Union));     // roll back: restore *this
        throw;
    }
}

void Data::Union::assign(Tag myTag, Union &&tmp, Tag otag)
{
    char saved[sizeof(Union)];
    memcpy(saved, this, sizeof(Union));
    try
    {
        copy(std::move(tmp), otag);
        fswap(*this, *reinterpret_cast<Union *>(saved));
        destroy(myTag);
        memcpy(this, saved, sizeof(Union));
    }
    catch (...)
    {
        memcpy(this, saved, sizeof(Union));
        throw;
    }
}

inline Data::Union::Union(Union const &other, Tag tag)
{
    copy(other, tag);
}

inline Data::Union::Union(Union &&tmp, Tag tag)
{
    copy(std::move(tmp), tag);
}

void Data::Union::destroy(Tag myTag)
{
    if (myTag == Tag::STRING)
        u_string.~string();
}

void Data::Union::copy(Union const &other, Tag tag)
{
    if (tag == INT)
        u_int = other.u_int;
    else
        new (this) string(other.u_string);
}

void Data::Union::copy(Union &&tmp, Tag tag)
{
    if (tag == INT)
        u_int = tmp.u_int;
    else
        new (this) string(std::move(tmp.u_string));
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
    d_union(other.d_union, d_tag)
{}

Data::Data(Data &&tmp)
:
    d_tag(tmp.d_tag),
    d_union(std::move(tmp.d_union), d_tag)
{}

    // destructor
Data::~Data()
{
    d_union.destroy(d_tag);
}

    // overloaded assignment operator
Data &Data::operator=(Data const &rhs)
{
    Data tmp(rhs);

    d_union.swap(d_tag, tmp.d_union, tmp.d_tag);
    swap(d_tag, tmp.d_tag);

//    if (d_union.assign(d_tag, rhs.d_union, rhs.d_tag))
//        d_tag = rhs.d_tag;

    return *this;
}

Data &Data::operator=(Data &&tmp)
{
    d_union.assign(d_tag, std::move(tmp.d_union), tmp.d_tag);
    d_tag = tmp.d_tag;

    return *this;
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
