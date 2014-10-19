#include "main.ih"

void display()
{
    size_t nr = 0;
    for (auto el: g_data)
        cerr << el << (++nr % 10 == 0 ? '\n' : ' ');

    cerr << '\n';
}
