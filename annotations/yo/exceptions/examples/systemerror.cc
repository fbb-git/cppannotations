#include <iostream>
#include <system_error>

using namespace std;

int main()
try
{
    try
    {
        throw system_error{2, system_category(), "system error thrown"};
    }
    catch (system_error const &se)
    {
        cout << se.what() << ", " << se.code() << '\n';
        throw;
    }
}
catch (exception const &ex)
{
    cout << ex.what() << '\n';
}
catch (...)
{
    cout << "unknown\n";
}
