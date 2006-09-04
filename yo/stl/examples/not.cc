    #include <iostream>
    #include <string>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main(int argc, char **argv)
    {
        bool bArr[] = {true, true, true, false, false, false};
        unsigned const bArrSize = sizeof(bArr) / sizeof(bool);

        for (unsigned idx = 0; idx < bArrSize; ++idx)
            cout << bArr[idx] << " ";
        cout << endl;

        transform(bArr, bArr + bArrSize, bArr, logical_not<bool>());

        for (unsigned idx = 0; idx < bArrSize; ++idx)
            cout << bArr[idx] << " ";
        cout << endl;
    }
    /*
        generated output:

        1 1 1 0 0 0
        0 0 0 1 1 1
    */
