/*
    The way to remove elements from a hash_map isn't intuitively obsious:
    a for_each construction can't be used, as the erase() during the for_each
    fucks up the for_each process.

    This also holds true for other gerneric algorithms in which iterators are
    used, like remove_if etc.

    The problem is probably caused by the fact that the keys in a hash_map
    aren't ordered, and therefore reordering keys isn't a well defined
    operation.

    the approach taken here is to collect the relevant keys in a set, and then
    iterate over the set of keys, removing the corresponding elements from the
    hash_map
*/

#include <algorithm>
#include <iostream>
#include <hash_map>
#include <set>

class Eraser
{
    public:
        Eraser(set <char const *> &keys)
        :
            keys(keys)
        {}
        void operator()(pair<char const *, int> const &it)
        {
            if (*it.first == 'a' || *it.first == 'e')
                keys.insert(set<char const *>::value_type(it.first));
        }
    private:
        set<char const *>
            &keys;
};


class Remove
{
    public:
        Remove(hash_map <char const *, int> &hm)
        :
            hm(hm)
        {}
        void operator()(char const *cp)
        {
            hm.erase(cp);
        }
    private:
        hash_map<char const *, int>
            &hm;
};


class List
{
    public:
        bool operator()(pair<char const *, int> const &it)
        {
            cerr << it.first << " = " << it.second << endl;
            return true;
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

    set<char const *> keys;

    for_each(hm.begin(), hm.end(), Eraser(keys));

    for_each(keys.begin(), keys.end(), Remove(hm));

    for_each(hm.begin(), hm.end(), List());

}
