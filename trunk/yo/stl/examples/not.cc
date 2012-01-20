    #include <iostream>
    #include <string>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main(int argc, char **argv)
    {
        bool bArr[] = {true, true, true, false, false, false};
        size_t const bArrSize = sizeof(bArr) / sizeof(bool);

        for (size_t idx = 0; idx < bArrSize; ++idx)
            cout << bArr[idx] << " ";
        cout << '\n';

        transform(bArr, bArr + bArrSize, bArr, logical_not<bool>());

        for (size_t idx = 0; idx < bArrSize; ++idx)
            cout << bArr[idx] << " ";
        cout << '\n';
    }
    /*
      Displays:

        1 1 1 0 0 0
        0 0 0 1 1 1
    */
