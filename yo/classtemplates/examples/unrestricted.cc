#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <cstring>

using namespace std;

struct One
{
    int x;
    string s;

    One()
    :
        x(0),
        s("hi")
    {}
    One(One const &other)
    :
        s(other.s)
    {
        cout << "One cc\n";
    }

    ~One()
    {
        cout << "~One\n";
    }
};

    union Union
    {
        template <int tg, typename Type>
        struct Tag
        {
            int tag;
            Type data;
            
            template <typename Data>
            Tag(Data const &tp)
            :
                tag(tg),
                data(tp)
            {}
        };

        Tag<1, One>     one;
        Tag<2, string>  str;
        Tag<3, std::ostringstream>  oss;

        Union(One const &o)
        {
            new (&one) Tag<1, One>(o);
        }
        Union(string const &st)
        {
            new (&str) Tag<2, string>(st);
        }
        Union(ostringstream const &o)
        {
            new (&oss) Tag<3, ostringstream>("");
        }

        void swap(Union &other)
        {
            char buffer[sizeof(Union)];
            memcpy(buffer, this, sizeof(Union));
            memcpy(this, &other, sizeof(Union));
            memcpy(&other, buffer, sizeof(Union));
        }

        Union(Union const &other)
        {
            if (other.one.tag == 1)
                new(&one) Tag<1, One>(other.one.data);
            else
                new(&str) Tag<2, string>(other.str.data);
        }

        Union &operator=(Union const &other)
        {
            Union tmp(other);
            swap(tmp);
            return *this;
        }

        ~Union()
        {
            if (one.tag == 1)
                one.data.~One();
            else
                str.data.~string();
        };
    };


    class Surround
    {
        int tag;
        union Union
        {
            std::ostringstream ostr;
            std::string str;
            int iValue;

            ~Union()
            {
                // what to do?
            }
        };
    };

main(int argc, char **argv)
{
    Union un {One()};
    Union us("hi there");

    Union u2(un);

    cout << us.str.data << '\n';

    u2 = un;
}




