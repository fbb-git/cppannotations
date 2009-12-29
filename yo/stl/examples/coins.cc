#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    std::mt19937 mt(time(0));
    bernoulli_distribution bd;

    for (int idx = 0; idx < 20; ++idx)
        cout << (bd(mt) ? "heads" : "tail") << (idx + 1 == 10 ? '\n' : ' ');
    cout << '\n';
}
