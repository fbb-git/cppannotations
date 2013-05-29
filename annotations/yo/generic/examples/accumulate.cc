    #include <numeric>
    #include <vector>
    #include <iostream>
    using namespace std;

    int main()
    {
        int         ia[] = {1, 2, 3, 4};
        vector<int> iv(ia, ia + 4);

        cout <<
            "Sum of values: " << accumulate(iv.begin(), iv.end(), int()) <<
            "\n"
            "Product of values: " << accumulate(iv.begin(), iv.end(), int(1),
                                            multiplies<int>()) << '\n';
    }
    /*
        Displays:
            Sum of values: 10
            Product of values: 24
    */
