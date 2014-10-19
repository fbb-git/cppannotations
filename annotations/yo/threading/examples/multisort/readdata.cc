#include "main.ih"

void readData()
{
    int value;                      // read the data
    while (cin >> value)
        g_data.push_back(value);
}
