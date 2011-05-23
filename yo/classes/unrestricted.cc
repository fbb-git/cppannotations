#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <memory>

#include <bobcat/fswap>

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
            
            Tag(Type const &tp)
            :
                tag(tg),
                data(tp)
            {}
        };

        Tag<1, One>     one;
        Tag<2, string>  s;

        Union(One const &o)
        {
            new(&one) Tag<1, One>(o);
        }
        Union(string const &st)
        {
            new(&s) Tag<2, string>(st);
        }

        Union(Union const &other)
        {
            if (other.one.tag == 1)
                new(&one) Tag<1, One>(other.one.data);
            else
                new(&s) Tag<2, string>(other.s.data);
        }

        Union &operator=(Union other)
        {
            FBB::fswap(*this, other);
            return *this;
        }

        ~Union()
        {
            if (one.tag == 1)
                one.data.~One();
            else
                s.data.~string();
        };
    };



int main(int argc, char **argv)
{
    Union un {One()};
    Union us("hi there");

    Union u2(un);

    cout << us.s.data << '\n';

    u2 = un;
}




