#include <initializer_list>
using namespace std;

void values(std::initializer_list<int> iniValues)
{
}

void values2(std::initializer_list<std::initializer_list<int>> iniValues)
{
}

int main()
{
    values({2, 3, 5, 7, 11, 13});
    values2({{1, 2}, {2, 3}, {3, 5}, {4, 7}, {5, 11}, {6, 13}});
}
