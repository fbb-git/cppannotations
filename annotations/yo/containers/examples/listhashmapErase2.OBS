/*
    The way to remove elements from a hash_map isn't intuitively obsious:
    a for_each construction can't be used, as the erase() during the for_each
    fucks up the for_each process.

    This also holds true for other gerneric algorithms in which iterators are
    used, like remove_if etc.

    The problem is probably caused by the fact that the keys in a hash_map
    aren't ordered, and therefore reordering keys isn't a well defined
    operation.

    the approach taken here is to find successive elements in the hash_map,
    using a Finder object. Each object found is then removed outside of
    the iterating loop. The assumption being that iterators can be incremented
    while the element still exist, and that the element can safely be removed
    after incrementing the iterator. Also, the end() iterator is assumed not
    to change it value when intermediate elements of the hash_map are erased.

    Hence, the procedure is based on the functioning of a construction like
    hm.erase(iterator++)

*/

#include <algorithm>
#include <iostream>
#include <hash_map>

class Finder
{
    public:
        bool operator()(pair<char const *, int> const &it)
        {
            cout << "Saw " << it.first << '\n';
            return *it.first == 'a' || *it.first == 'e';
        }
};

class List
{
    public:
        void operator()(pair<char const *, int> const &it)
        {
            cout << "Element [" << it.first << "] = " << it.second << '\n';
        }
};

int main(int argc, char **argv)
{
    hash_map<char const *, int>
        hm;

    hm["a"] = 1;
    hm["b"] = 2;
    hm["c"] = 3;
    hm["d"] = 4;
    hm["e"] = 5;
    hm["f"] = 6;
    hm["g"] = 7;
    hm["h"] = 8;

    hash_map<char const *, int>::iterator
        end = hm.end(),
        found = hm.begin();

    while ((found = find_if(found, end, Finder())) != end)
    {
        cout << "Removing " << found->first << " " << found->second << '\n';
        hm.erase(found++);
    }

    cout << "\nListing:\n\n";

    for_each(hm.begin(), hm.end(), List());
}
