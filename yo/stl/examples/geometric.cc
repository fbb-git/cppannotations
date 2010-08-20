#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main() 
{ 
    std::linear_congruential_engine<unsigned, 7, 3, 61> engine(0); 

    std::geometric_distribution<> dist; 

    for (size_t idx = 0; idx < 10; ++idx)
        std::cout << "a random value: " << dist(engine) << "\n";

    cout << '\n' <<
        dist.min() << " " << dist.max() << '\n';

} 




