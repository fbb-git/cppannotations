#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

struct Move
{
    Move()
    {}
    Move(Move &&rvalue)
    {}
    ~Move()
    {}
};

//typedef unique_ptr<int> up;
int main()
{
    unique_ptr<ifstream> ip(new ifstream("hi"));
    unique_ptr<ifstream> ip2(move(ip));

    unique_ptr<Move> ip3(new Move);
    unique_ptr<Move> ip4(move(ip3));
}
