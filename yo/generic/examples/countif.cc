    #include <algorithm>
    #include <iostream>

    class Odd
    {
        public:
            bool operator()(int value)
            {
                return value & 1;
            }
    };

    using namespace std;

    int main()
    {
        int     ia[] = {1, 2, 3, 4, 3, 4, 2, 1, 3};

        cout << "The number of odd values in the array is: " <<
            count_if(ia, ia + sizeof(ia) / sizeof(int), Odd()) << endl;

        return 0;
    }
    /*
        Generated output:

        The number of odd values in the array is: 5
    */
