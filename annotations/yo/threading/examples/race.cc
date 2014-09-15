#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void multiply(vector<int> &data, int factor)
{
    cout << "multiply " << data.size() << " elements\n";
    for (auto &el: data)
        el *= factor;
}

void divide(vector<int> &data, int factor)
{
    cout << "divide " << data.size() << " elements\n";
    for (auto &el: data)
        el /= factor;
}

int main()
{
    vector<int> data {1,2,3,4,5,6,7,8,9,10};

    thread t1(multiply, ref(data), 5);
    thread t2(divide, ref(data), 5);

    t1.join();
    t2.join();
}

    
