// explicitly link against stdc++fs:
//
//      gx directoryentry.cc -lstdc++fs

//de
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
using namespace std;

int main(int argc, char **argv)
{
    fs::directory_entry de{argv[1]};
    cout << de.path() << '\n';

    de.replace_filename(argv[2]);
    cout << de.path() << '\n';

    de.assign(argv[2]);
    cout << de.path() << '\n';
}
//=







