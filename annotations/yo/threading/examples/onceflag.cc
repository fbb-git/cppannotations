// initializing a (waitd to the essentials) singleton, using std::once_flag.
// don't forget -pthread

#include <iostream>
#include <mutex>

struct Single
{
    static Single *s_single;
    static std::once_flag s_resourceFlag;

    static void initialize()
    {
        std::cout << "initializing\n";
        s_single = new Single;
    }

    static Single *instance()
    {
        std::call_once(s_resourceFlag, initialize);
        return s_single;
    }
};

Single *Single::s_single;
std::once_flag Single::s_resourceFlag;

int main()
{
    Single::instance();
    Single::instance();
}
