    #include <iostream>
    #include <functional>
    #include <algorithm>
    #include <vector>
    using namespace std;

    int main(int argc, char **argv)
    {
        int iArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        cout << count_if(iArr, iArr + 10, bind2nd(less_equal<int>(), 6)) <<
            endl;
        cout << count_if(iArr, iArr + 10, bind2nd(not2(greater<int>()), 6)) <<
            endl;
        cout << count_if(iArr, iArr + 10, not1(bind2nd(greater<int>(), 6))) <<
            endl;
    }
    /*
        produced output:

        6
        6
        6
    */
