#include <iostream>
#include <streambuf>
#include <istream>

    class RandBuf: public std::streambuf
    {
        // implements a buffer for random numbers
    };
    class RandStream: private std::streambuf, public std::istream
    {
        // implements a stream to extract random values from
        public:
            std::streambuf::in_avail;
    };

using namespace std;

int main()
{
    RandBuf rb;

    cout << rb.in_avail() << '\n';
}
