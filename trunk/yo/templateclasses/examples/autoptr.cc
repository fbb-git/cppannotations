    #include <iostream>
    #include <algorithm>
    #include <string>
    #include "autoptr.h"
    using namespace std;

    int main(int argc, char **argv)
    {
        FBB::auto_ptr<string> sp(new string[argc]);
        copy(argv, argv + argc, sp.get());

        cout << "First auto_ptr, program name: " << sp[0] << endl;

        FBB::auto_ptr<string> second(sp);

        cout << "First auto_ptr, pointer now: " << sp.get() << endl;
        cout  << "Second auto_ptr, program name: " << second[0] << endl;

        return 0;
    }
    /*
        Generated output:

        First auto_ptr, program name: a.out
        First auto_ptr, pointer now: 0
        Second auto_ptr, program name: a.out
    */
