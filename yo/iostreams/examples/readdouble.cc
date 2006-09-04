    #include <fstream>
    using namespace std;

    int main(int argc, char **argv)
    {
        ifstream f(argv[1]);
        double   d;

        // reads double in binary form.
        f.read(reinterpret_cast<char *>(&d), sizeof(double));
    }
