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

        cout << "The max. int value is " << *max_element(ia, ia + 5) << endl;
        cout << "The max. absolute int value is " <<
                *max_element(ia, ia + 5, AbsValue()) << endl;

        return 0;
    }
    /*
        Generated output:

        The max. int value is 10
        The max. absolute int value is -12
    */
