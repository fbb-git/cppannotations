#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
    static std::once_flag s_once;
    static Singleton *s_singleton;

    public:
        static Singleton *instance()
        {
            std::call_once(s_once, []{s_singleton = new Singleton;});
            return s_singleton;
        }
};

Singleton *Singleton::s_singleton = 0;
std::once_flag Singleton::s_once;

int main()
{
    cout << Singleton::instance() << '\n';
}
