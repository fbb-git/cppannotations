#include <iostream>
#include <unordered_map>
#include <experimental/filesystem>

// explicitly link against stdc++fs:
//
//      gx statusknown.cc -lstdc++fs

namespace fs = std::experimental::filesystem;
using namespace std;

//demo
namespace
{
    std::unordered_map<fs::file_type, char const *> map =
    {
        { fs::file_type::not_found, "an unknown file" },
        { fs::file_type::none,      "not yet or erroneously evaluated "
                                                            "file type" },
        { fs::file_type::regular,   "a regular file" },
        { fs::file_type::directory, "a directory" },
        { fs::file_type::symlink,   "a symbolic link" },
        { fs::file_type::block,     "a block device" },
        { fs::file_type::character, "a character device" },
        { fs::file_type::fifo,      "a named pipe" },
        { fs::file_type::socket,    "a socket file" },
        { fs::file_type::unknown,   "an unknown file type" }
    };

    void status(fs::path const &path)
    {
        fs::file_status stat = fs::directory_entry{ path }.symlink_status();
        
        cout << path << " is " << map[stat.type()] << '\n';
    };
} // anon. namespace

int main()
{
    for (auto entry: fs::directory_iterator{"/home/frank"})
        ::status(entry);

    cout << "File status_known is " <<
            status_known( fs::file_status{} ) << '\n';
}
//=








