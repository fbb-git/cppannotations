#include <iostream>
#include <future>
#include <iomanip>

using namespace std;

//code
int m1[2][2] = {{1, 2}, {3, 4}};
int m2[2][2] = {{3, 4}, {5, 6}};

void innerProduct(promise<int> &ref, int row, int col)
{
    int sum = 0;
    for (int idx = 0; idx != 2; ++idx)
        sum += m1[row][idx] * m2[idx][col];

    ref.set_value(sum);
}

int main()
{
    promise<int> result[2][2];

    for (int row = 0; row != 2; ++row)
    {
        for (int col = 0; col != 2; ++col)
            thread(innerProduct, ref(result[row][col]), row, col).detach();
    }

    for (int row = 0; row != 2; ++row)
    {
        for (int col = 0; col != 2; ++col)
            cout << setw(3) << result[row][col].get_future().get();
        cout << '\n';
    }
}
//=

