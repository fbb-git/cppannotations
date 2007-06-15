#include <iomanip>
#include <iostream>

int main()
{
    cout.setf(ios::showbase);

    cout << hex << 16 << oct << 16 << endl;

    cout.unsetf(ios::showbase);

    cout << hex << 16 << oct << 16 << endl;

    cout << setprecision(5) << 1.123456789 << endl;

    cout.setf(ios::showpoint);
    cout << setprecision(2) << dec << 10.0 << endl;

    cout << "|" << setw(4) << 4 << "|" << endl;
    cout.setf(ios::left);
    cout << "|" << setw(4) << -4 << "|" << endl;
    cout << "|" << setw(4) << 4 << "|" << endl;
    cout.unsetf(ios::left);
    cout.setf(ios::internal);
    cout << "|" << setw(4) << -4 << "|" << endl;

    cout << setbase(8) << 16 << " " << 16 << endl;
    cout << dec << 5 << endl;

    return (0);
}
