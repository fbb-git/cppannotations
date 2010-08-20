#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    std::mt19937 engine(time(0));
    bernoulli_distribution dist(0);

    for (int idx = 0; idx < 20; ++idx)
        cout << (dist(engine) ? "heads" : "tail") << 
                (idx + 1 == 10 ? '\n' : ' ');

    cout << '\n' <<
        dist.min() << " " << dist.max() << '\n';
}
