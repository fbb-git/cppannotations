#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>

#include "placementalloc.h"
#include "plainalloc.h"
#include "newalloc.h"

#include "storage.h"

using namespace std;

int main(int argc, char **argv)
{
    switch (argv[1][0])
    {
        default:
            cout << "Provide argument to read from stdin:\n"
                "n: read strings, using NewAlloc with a vector\n"
                "p: read strings, using PlacementAlloc with a deque\n"
                "s: read ints, using a simple PlainAlloc with a list\n";
        break;

        case 'n':
        {
            Storage<string, NewAlloc, std::vector> storage;

            copy(istream_iterator<string>(cin), istream_iterator<string>(),
                    back_inserter(storage));

            cout << "Element index 1 is " << storage[1] << '\n';
            storage[1] = "hello";

            copy(storage.begin(), storage.end(),
                 ostream_iterator<NewAlloc<string> >(cout, "\n"));
        }
        break;

         case 'p':
         {
            Storage<string, PlacementAlloc, deque> storage;

            copy(istream_iterator<string>(cin), istream_iterator<string>(),
                    back_inserter(storage));

            copy(storage.begin(), storage.end(),
                 ostream_iterator<PlacementAlloc<string> >(cout, "\n"));
        }
        break;

        case 's':
        {
             Storage<int, PlainAlloc, list> storage;

             copy(istream_iterator<int>(cin), istream_iterator<int>(),
                     back_inserter(storage));

             copy(storage.begin(), storage.end(),
                  ostream_iterator<PlainAlloc<int> >(cout, "\n"));
        }
        break;
    }
}
