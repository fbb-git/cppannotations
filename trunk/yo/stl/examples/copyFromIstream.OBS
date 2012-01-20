/*
    This example shows in a very simple way that the unserlying = operator is
    used with copy(): the object's address itself is passed as the output
    iterator of the copy() algorithm.

    An interesting feature is that the return value is a pointer to an Ostream
    object located nObjects farther than the initial Ostream object, thus
    indicating the number of objects that were passed to the Ostream's
    assignment operator.

    Compared with the plain copy() example this one shows the use of the
    istream_iterator<>() in combination with copy() and the simple Ostream
    object into which the elements are copied
*/

#include <algorithm>
#include <iostream>
#include <string>

class Ostream
{
    public:
        Ostream &operator=(string const &item)
        {
            cerr << "assigning " << item << '\n';
        }
};

int main()
{
    Ostream
        ostr;

    Ostream
        *op = copy(istream_iterator<string>(cin), istream_iterator<string>(),
                &ostr);

    cerr << (op == &ostr ? "same" : "different") << " object: " <<
            (op - &ostr) << "\n";

}
