#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Cout: private std::streambuf, public std::ostream
{
    std::mutex d_mutex;

    public:
        Cout()
        :
            std::strembuf(std::cout.rdbuf())
            std::ostream(this)
        {}
};

template <typename Type>
Cout &operator<<(Cout &out, Type const &value)
{
    std::lock_guard{out.d_mutex);
    static_cast<std::ostream>(*this) << value;
}

