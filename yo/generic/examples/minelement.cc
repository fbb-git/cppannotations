    #include <algorithm>
    #include <iostream>

    class AbsValue
    {
        public:
            bool operator()(int first, int second) const
            {
                return abs(first) < abs(second);
            }
    };

    using namespace std;

    int main()
    {
        int     ia[] = {-4, 7, -2, 10, -12};

        cout << "The minimum int value is " << *min_element(ia, ia + 5) <<
                '\n';
        cout << "The minimum absolute int value is " <<
                *min_element(ia, ia + 5, AbsValue()) << '\n';

        return 0;
    }
    /*
        Displays:

        The minimum int value is -12
        The minimum absolute int value is -2
    */
