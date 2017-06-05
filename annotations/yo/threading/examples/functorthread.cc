    #include <iostream>
    #include <thread>
    #include <array>

    using namespace std;

    class Functor
    {
        array<int, 30> &d_data;
        int d_value;

        public:
            Functor(array<int, 30> &data, int value)
            :
                d_data(data),
                d_value(value)
            {}
            void operator()(ostream &out)
            {
                for (auto &value: d_data)
                {
                    value = d_value++;
                    out << value << ' ';
                }
                out << '\n';
            }
    };

    int main()
    {
        array<int, 30> data;
        Functor functor{ data, 5 };
        thread funThread{ functor, ref(cout) };
        funThread.join();
    };
