/*
    This example shows that the map's erase() function does not use
    the delete operator if the data element of the map is a pointer.
    Remove the explicit delete operator and notice that the
    destructor isn't called anymore
*/
#include <iostream>
#include <hash_map>

class Item
{
    public:
        ~Item()
        {
            cerr << "Destructor called\n";
        }
};

int main(int argc, char **argv)
{
    hash_map<char const *, Item *>
        hm;

    if (hm["item"])
        cout << "hm[item] exists\n";
    else
        cout << "hm[item] does not exist\n";

    hm["item"] = new Item;

    delete hm["item"];
    hm.erase("item");

    if (hm["item"])
        cout << "hm[item] exists\n";
    else
        cout << "hm[item] does not exist\n";
}
