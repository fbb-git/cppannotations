        #include <iostream>
        #include <iomanip>

        using namespace std;

        extern ostream &w10(ostream &str);

        int main()
        {
            w10(cout) << 3 << " ships sailed to America" << endl;
            cout << "And " << w10 << 3 << " more ships sailed too." << endl;
        }
