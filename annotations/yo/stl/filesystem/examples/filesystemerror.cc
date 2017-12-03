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
    try
    {
        throw fs::filesystem_error{ "exception encountered", "p1", "p2",
                                    make_error_code(errc::address_in_use) };
    }
    catch (fs::filesystem_error const &fse)
    {
        cerr << fse.what() << ",\n" << 
                fse.path1() << ",\n" <<
                fse.path2() << ",\n" << 
                fse.code() << '\n';
    
        throw;
    }
}
catch (exception const &ec)
{
    cerr << ec.what() << '\n';
}
//=
