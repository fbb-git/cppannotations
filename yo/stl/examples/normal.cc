#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main() 
{ 
    std::mt19937 engine(time(0)); 
    std::normal_distribution<> dist; 

    for (size_t idx = 0; idx < 10; ++idx)
        std::cout << "a random value: " << dist(engine) << "\n";

    cout << '\n' <<
        dist.min() << " " << dist.max() << '\n';
} 




