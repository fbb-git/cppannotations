#include <iostream>
#include <cstring>

using namespace std;

    struct Data
    {
        int d_value;

        Data(int value)
        :
            d_value(value)
        {
            cout << "cons "<< d_value << "\n";
        }
        Data(Data const &other)
        :
            d_value(other.d_value)
        {
            cout << "copy " << d_value << '\n';
        }
        Data(Data &&other)
        :
            d_value(other.d_value)
        {
            cout << "move " << other.d_value << " to " << d_value << '\n';
        }
    };

    Data &&makeData(int x)
    {
        Data ret(x);
        return move(ret);
    }

    int main()
    {
        Data &&ref = makeData(1);
        cout << ref.d_value << '\n';

        return 0;
    }
    /*
        Output with g++ 4.3.3:
            cons 1
            move 134514832 to 134514832
            134514832

        Output with g++ 4.4.0:
            cons 1
            move 1 to 1
            1
    */
