#include <iostream>
#include <experimental/filesystem>

// explicitly link against stdc++fs:
//
//      gx spaceinfo.cc -lstdc++fs

namespace fs = std::experimental::filesystem;

//demo
int main()
{
    fs::path p{ "/tmp" };

    auto pod = fs::space(p);

    std::cout << "The filesystem containing /tmp has a capacity of " <<
                                            pod.capacity << " bytes,\n"
        "i.e., " << pod.capacity / 1024 << " KB.\n"
        "# free bytes: " << pod.free << "\n"
        "# available:  " << pod.available << '\n';
}
//=
