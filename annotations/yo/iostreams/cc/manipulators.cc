#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::showbase);

    cout << hex << 16 << oct << 16 << '\n';

    cout.unsetf(ios::showbase);

    cout << hex << 16 << oct << 16 << '\n';

    cout << setprecision(5) << 1.123456789 << '\n';

    cout.setf(ios::showpoint);
    cout << setprecision(2) << dec << 10.0 << '\n';

    cout << "|" << setw(4) << 4 << "|" << '\n';
    cout.setf(ios::left);
    cout << "|" << setw(4) << -4 << "|" << '\n';
    cout << "|" << setw(4) << 4 << "|" << '\n';
    cout.unsetf(ios::left);
    cout.setf(ios::internal);
    cout << "|" << setw(4) << -4 << "|" << '\n';

    cout << setbase(8) << 16 << " " << 16 << '\n';
    cout << dec << 5 << '\n';

    return (0);
}
