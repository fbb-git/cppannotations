#include <iostream>
#include <ctime>
#include <random>

using namespace std;

    // arguments: 1st: number of random numbers to generate
    //            2nd: lowest positve random number,
    //            3rd: highest positive random number
                    
int main(int argc, char **argv)
{
    mt19937 mt( time(0) );      // seed with the current time in secs.

    for (
        size_t nGenerate = stoul(argv[1]), lowest = stoul(argv[2]),
                                           mod = stoul(argv[3]) + 1 - lowest;
            nGenerate--;
    )
        cout << (lowest + mt() % mod) << ' ';

    cout << '\n';
}
