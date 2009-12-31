    #include <algorithm>
    #include <iostream>
    using namespace std;

    class AbsValue
    {
        public:
            bool operator()(int first, int second) const
            {
                return abs(first) < abs(second);
            }
    };
    int main()
    {
        int     ia[] = {-4, 7, -2, 10, -12};

        cout << "The max. int value is " << *max_element(ia, ia + 5) << '\n';
        cout << "The max. absolute int value is " <<
                *max_element(ia, ia + 5, AbsValue()) << '\n';
    }
    /*
        Displays:
            The max. int value is 10
            The max. absolute int value is -12
    */
