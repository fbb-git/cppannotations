#include <iostream>
#include <string>
#include "Vector.h"

int main()
{
    Vector<int>
        bv(5),
        b2;

    b2 = bv;

    bv[0] = 3;
    bv[1] = 33;
    bv[2] = 13;
    bv[3] = 6;
    bv[4] = 373;

    copy(bv.begin(), bv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    Vector<int>::reverse_iterator
            rit  = bv.rbegin();

    while (rit != bv.rend())
        cout << *rit++ << ", ";
    cout << endl;

    bv.push_back(12);
    bv.push_back(5);

    copy(bv.begin(), bv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    bv.sort();
    copy(bv.begin(), bv.end(), ostream_iterator<int>(cout, " "));
    cout << "bv has " << bv.size() << " elements\n";

    Vector<string>
        bstr;

    bstr.push_back("bravo");
    bstr.push_back("delta");
    bstr.push_back("foxtrot");
    bstr.push_back("echo");
    bstr.push_back("charley");
    bstr.push_back("alpha");

    bstr.sort();
    copy(bstr.begin(), bstr.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}
