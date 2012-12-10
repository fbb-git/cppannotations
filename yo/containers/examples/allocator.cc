#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vs;    

    auto allocator = vs.get_allocator();        // get the allocator

    string *sp = allocator.allocate(3);         // allocate 4 strings

    allocator.construct(&sp[0], "hello world"); // allocate 1st string
    allocator.construct(&sp[1], sp[0]);         // use the copy constructor
    allocator.construct(&sp[2], 12, '=');       // string of 12 = chars

    cout << sp[0] << '\n' <<                    // show the strings
            sp[1] << '\n' <<
            sp[2] << '\n' <<
            "could have allocated " << allocator.max_size() << " strings\n";

    for (size_t idx = 0; idx != 3; ++idx)
        allocator.destroy(sp + idx);            // delete the string's
                                                // contents

    allocator.deallocate(sp, 3);                // and delete sp itself again.
}
