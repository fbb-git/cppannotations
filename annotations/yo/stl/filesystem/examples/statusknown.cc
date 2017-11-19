#include <iostream>
#include <experimental/filesystem>

// explicitly link against stdc++fs:
//
//      gx statusknown.cc -lstdc++fs

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
    cerr << "File status_known is " <<
            status_known( fs::file_status{} ) << '\n';
}
