    #include <algorithm>
    #include <iterator>
    using namespace std;

    class Insertable
    {
        public:
            typedef int const &const_reference;

            void push_back(int const &)
            {}
    };

    int main()
    {
        int arr[] = {1};
        Insertable insertable;

        copy(arr, arr + 1, back_inserter(insertable));
    }
