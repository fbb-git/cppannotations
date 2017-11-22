#include <system_error>

using namespace std;

int main()
{
    error_code ec{ make_error_code(errc::bad_address) };
}
