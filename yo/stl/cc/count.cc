    #include <algorithm>
    #include <iostream>
    using namespace std;

    int main()
    {
        int ia[] = {1, 2, 3, 4, 3, 4, 2, 1, 3};

        cout << "Number of times the value 3 is available: " <<
            count(ia, ia + sizeof(ia) / sizeof(int), 3) <<
            endl;

        return 0;
    }
    /*
        Generated output:

        Number of times the value 3 is available: 3
    */
