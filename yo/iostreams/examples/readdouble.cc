    #include <fstream>
    using namespace std;

    int main(int argc, char **argv)
    {
        ifstream in(argv[1]);
        double   value;

        // reads double in raw, binary form from file.
        in.read(reinterpret_cast<char *>(&value), sizeof(double));
    }
