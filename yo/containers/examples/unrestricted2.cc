#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <bobcat/fswap>

using namespace std;
using namespace FBB;

class MultiData
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
        
            ~Union()
            {};
            Union()
            {};
            Union(Union const &other)
            {};
            Union &operator=(Union const &other)    // bluntly copies bytes
            {
                memcpy(this, &other, sizeof(Union));
                return *this;
            }
        };

        Tag d_tag;
        Union d_u;
    
    public:
            // constructors
        MultiData(std::string const &str)
        :
            d_tag(STRING)
        {
            new (&d_u) string(str);
        }

        MultiData(int value)
        :
            d_tag(INT)
        {
            d_u.u_int = value;
        }

        MultiData(MultiData const &other)
        :
            d_tag(other.d_tag)
        {
            copy(other);
        }
        
            // destructor
        ~MultiData()
        {
            destroy(d_u);
        }

            // overloaded assignment operator
        MultiData &operator=(MultiData const &rhs)
        {
            Union saved;
            saved = d_u;                    // copy the current union

            try
            {
                copy(rhs);                  // placement new initialization
                destroy(saved);             // delete the other memory

                d_tag = rhs.d_tag;
            }
            catch (...)
            {
                d_u = saved;                // roll back
            }
            return *this;
        }

                // accessors
        string const &str() const
        {
            return d_u.u_string;
        }
        int value() const
        {
            return d_u.u_int;
        }

    private:
            // copy (or use placement new) the other union fields to d_u
        void copy(MultiData const &other)
        {
            if (other.d_tag == INT)
                d_u.u_int = other.d_u.u_int;
            else
                new (&d_u) string(other.d_u.u_string);
        }
            // Swap the new union contents with the saved union, restoring 
            // the saved info into the current union.
            // then delete the original union value
            // then put back the new union (now in 'saved') into d_u
        void destroy(Union &saved)
        {
            fswap(d_u, saved);
            if (d_tag == STRING)
                d_u.u_string.~string();
            d_u = saved;
        }
};

int main(int argc, char **argv)
{
    MultiData v(2);

    cout << v.value() << '\n';

    MultiData a("hi");
    MultiData b("lo");

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






