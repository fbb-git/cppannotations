Although the compiler is unable to provide (default) implementations for
constructors and destructors of unrestricted unions, em(we) can. The task
isn't difficult, but there are some caveats. 

    Consider the unrestricted union's destructor. It clearly should destroy
tt(u_string)'s data if that is its currently active field; but it should do
nothing if tt(u_int) is its currently active field. But how do we tell the
destructor what field to destroy? We can't as the
unrestricted union does not offer information about what field is currently
active.

    Here is one way to solve this problem:

    If the unrestricted union is embedded in a larger aggregate, like a class
or a struct, then the class or struct may be provided with a tag data member
storing the currently active union-field. The tag can be of an enumeration
type, defined by the surrounding aggregate. The unrestricted union may then be
completely controlled by the surrounding aggregate. Under this approach we'll
start out with explicit empty implementations of the constructors and
destructor that would otherwise have received default implementations from the
compiler: 
        verb(
    Union::~Union()
    {};
    Union::Union()
    {};
    Union::Union(Union const &other)
    {};
        )




