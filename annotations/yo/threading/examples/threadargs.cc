#include <iostream>
#include <thread>

using namespace std;

struct NoMove
{
    NoMove() = default;
    NoMove(NoMove &&tmp) = delete;
};

struct MoveOK
{
    int d_value = 10;

    MoveOK() = default;
    MoveOK(MoveOK const &) = default;

    MoveOK(MoveOK &&tmp)
    {
        d_value = 0;
        cout << "MoveOK move cons.\n";
    }
};

void valueArg(int value)
{}
void refArg(int &ref)
{}
void r_refArg(int &&tmp)
{
    tmp = 100;
}
void r_refNoMove(NoMove &&tmp)
{}
void r_refMoveOK(MoveOK &&tmp)
{}

int main()
{
     int value = 0;

     std::thread(valueArg,   value).join();
     std::thread(refArg,     ref(value)).join();
     std::thread(r_refArg,   move(value)).join();

//    std::thread(refArg,     value);

    std::thread(r_refArg,   value).join();
    cout << "value after r_refArg: " << value << '\n';

//  std::thread(r_refNoMove, NoMove());

    NoMove noMove;
//  std::thread(r_refNoMove, noMove).join();

    MoveOK moveOK;
    std::thread(r_refMoveOK, moveOK).join();
    cout << moveOK.d_value << '\n';
}
