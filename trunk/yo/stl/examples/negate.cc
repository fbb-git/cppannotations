    #include <iostream>
    #include <string>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main(int argc, char **argv)
    {
        int iArr[] = { 1, -2, 3, -4, 5, -6 };

        transform(iArr, iArr + 6, iArr, negate<int>());

        for (int idx = 0; idx < 6; ++idx)
            cout << iArr[idx] << ", ";

        cout << endl;
    }
    /*
        Generated output:

        -1, 2, -3, 4, -5, 6,
    */
