#include <iostream>
#include <thread>

using namespace std;

thread_local int t_value = 100;

void modify(char const *label, int newValue)
{
    cout << label << " before: " << t_value << ". Address: " <<
                                                    &t_value << endl;
    t_value = newValue;
    cout << label << " after: " << t_value << endl;
}

int main()
{
    thread(modify, "first", 50).join();
    thread(modify, "second", 20).join();
    modify("main", 0);
}
