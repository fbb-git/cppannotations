/*
    This example shows in a very simple way that the unserlying = operator is
    used with copy(): the object's address itself is passed as the output
    iterator of the copy() algorithm.

    An interesting feature is that the return value is a pointer to an Ostream
    object located nObjects farther than the initial Ostream object, thus
    indicating the number of objects that were passed to the Ostream's
    assignment operator
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
    string
        a[] =
        {
            "ape",
            "nut",
            "maria",
            "william",
        };

    Ostream
        ostr;

    Ostream
        *op = copy(a, a + 4, &ostr);

    cerr << (op == &ostr ? "same" : "different") << " object: " <<
            (op - &ostr) << "\n";

}
