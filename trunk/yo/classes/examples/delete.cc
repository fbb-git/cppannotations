/*
    This example illustrates the use of delete[] in combination with
    arrays.

    First a new array is allocated, and deleted thereafter. It shows that
    only the first object is deleted.

    If, however, a single object is allocated, and delete[] is called, a
    segmentation error results: the compiler keeps deleting objects that don't
    exist.

    If the array contains plain values or pointers nothing in particular
    happens: delete and delete[] may both be used.

    Finally, if the array contains auto_pointers, the same situation as with
    objects can be observed: in the `delete array' situation the objects
    reached via the remaining auto-ptrs are not released, whereas they are
    released in the situation where delete[] is used.
*/

#include <string>
#include <iostream>
#include <memory>


class X
{
    public:
        X()
        {
            cerr << "X constructor called" << endl;
        }
        ~X()
        {
            cerr << "X destructor called" << endl;
        }
};


int main(int argc, char **argv)
{
    cerr << "deleting an array with objects without []:\n";
    delete new X[3];

    cerr << "deleting an array with objects with []:\n";
    delete[] new X[3];

    // cout << "deleting a non-existing array\n":
    //delete[] new X();    THIS RESULTS IN A SEGMENTATION FAULT!!!


    cerr << "deleting an array with plain values without []:\n";
    delete new int[3];

    cerr << "deleting an array with plain values with []:\n";
    delete[] new int[3];


    cerr << "deleting an array with pointers without []:\n";
    delete new int *[3];

    cerr << "deleting an array with pointers with []:\n";
    delete[] new int *[3];


    cerr << "deleting an array with auto-pointers without []:\n";
    auto_ptr<X>
        *a1 = new auto_ptr<X>[3];

    a1[0].reset(auto_ptr<X>(new X()).release());
    a1[1].reset(auto_ptr<X>(new X()).release());
    a1[2].reset(auto_ptr<X>(new X()).release());

    delete a1;


    cerr << "deleting an array with auto-pointers with []:\n";

    auto_ptr<X>
        *a2 = new auto_ptr<X>[3];

    a2[0].reset(auto_ptr<X>(new X()).release());
    a2[1].reset(auto_ptr<X>(new X()).release());
    a2[2].reset(auto_ptr<X>(new X()).release());

    delete[] a2;

}
