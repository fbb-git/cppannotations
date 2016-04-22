#include <iostream>
#include <string>

struct Namespace
{
//    using namespace std;      cannot be used here
    std::string d_str;

    std::string text() const;
};

int main()
{
    using namespace std;        // but here is OK

    string text;

    Namespace ns;

    cout << ns.text();
}
