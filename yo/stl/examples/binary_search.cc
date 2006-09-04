#include <iostream>
#include <algorithm>

class Comparator
{
    public:
        Comparator(int &v, int *&ip)
        :
            v(v),
            ip(ip)
        {}
        bool operator()(int const &i1, int const &i2)
        {
            if (i1 == i2)
                const_cast<int const *>(ip) = &i1 == &v ? &i2 : &i1;
            return i1 < i2;
        }
    private:
        int
            *&ip,
            &v;
};


int main(int argc, char **argv)
{
    int
        *ip,
        value = atoi(argv[1]),
        x[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

    Comparator
        comp(value, ip);

    if (binary_search(x, x + 9, value, comp))
        cout << "found it: element " << (ip - x) << endl;
    else
        cout << "didn't find it\n";
}
