#include <iostream>
#include <experimental/filesystem>

// explicitly link against stdc++fs:
//
//      gx path.cc -lstdc++fs

namespace fs = std::experimental::filesystem;

int main()
{
    fs::path p{ "/abs/olu/te.cc" };


    p.replace_filename("this/part");

    std::cout << "Current path is " << fs::current_path() << '\n' <<
                 "Absolute path for " << p << " is " <<
                                                fs::absolute(p) << '\n';
}
