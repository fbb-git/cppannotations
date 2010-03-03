#include <stdlib.h>
#include <procbuf.h>
#include <fstream>


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        procbuf
            p("gzip > out.gz", ios::out);

        ostream
            ostr(&p);

        for (int idx = 0; idx < 1000; ++idx)
        {
            double
                d = rand() / static_cast<double>(rand());
            ostr.write(&d, sizeof(d));
        }
    }
    else
    {
        procbuf
            p("gunzip < out.gz", ios::in);

        istream
            istr(&p);

        double
            d;

        for (int idx = 0; idx < 1000; ++idx)
        {
            if (!(istr.read(&d, sizeof(d))))
            {
                cout << "read stopped at " << idx << '\n';
                return (1);
            }
        }
    }
}
