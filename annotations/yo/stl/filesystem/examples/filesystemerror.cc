// explicitly link against stdc++fs:
//
//      gx filesystemerror.cc -lstdc++fs

//fse
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
using namespace std;


int main()
try
{
    throw fs::filesystem_error{ "exception encountered", "p1", "p2",
                                make_error_code(errc::address_in_use) };
}
catch(fs::filesystem_error const &fse)
{
    cerr << fse.what() << ", " << fse.path1() << ", " <<
                                fse.path2() << ", " << fse.code() << '\n';

    throw;          // calls std::terminate
}
catch(...)
{
    cerr << "not reached...\n";
}
//=
