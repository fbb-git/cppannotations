    #include <algorithm>
    #include <iostream>
    using namespace std;

    class Odd
    {
        public:
            bool operator()(int value) const
            {
                return value & 1;
            }
    };
    int main()
    {
        int     ia[] = {1, 2, 3, 4, 3, 4, 2, 1, 3};

        cout << "The number of odd values in the array is: " <<
            count_if(ia, ia + sizeof(ia) / sizeof(int), Odd{}) << '\n';
    }
    // Displays:    The number of odd values in the array is: 5
