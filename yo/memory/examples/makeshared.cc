/*
Defined in header <memory>
		
template< class T, class... Args >
shared_ptr<T> make_shared( Args... args );
		

Constructs an object of type T and wraps it in a std::shared_ptr using args as
the parameter list for the constructor of T. 
Parameters
args 	- 	list of arguments with which an instance of T will be constructed.
Return value

std::shared_ptr of an instance of type T.
Complexity

Constant time given the T constructor also have a constant complexity.
Notes

This function allocates memory for the T object and for the shared_ptr's
control block with a single memory allocation. In contrast, the declaration
std::shared_ptr<T> p(new T(Args...)) performs two memory allocations, which
may incur unnecessary overhead. 
*/

#include <iostream>
#include <memory>
 
using namespace std;

struct Object
{
    int d_value;

    Object(int init)
    :
        d_value(init)
    {
        cout << "Constructing object " << this << " with " << init << '\n';
    }

    Object()
    :
        d_value(0)
    {
        cout << "Constructing default Object " << this << '\n';
    }

    ~Object()
    {
        cout << "Destroying Object " << this << '\n';
    }
};

ostream &operator<<(ostream &out, Object const &obj)
{
    return out << obj.d_value;
}

int main()
{
    auto sp = make_shared<Object>(10);

    auto shared(sp);

    cout << "Object contains " << *sp << ", use count = " << sp.use_count() << 
                                                                        '\n';
    sp = make_shared<Object>();

    cout << "Shared contains " << *shared << ", use count = " << 
                                                    sp.use_count() << '\n';
    cout << "Object contains " << *sp << '\n';
}


