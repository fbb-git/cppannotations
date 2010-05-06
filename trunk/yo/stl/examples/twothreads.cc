    #include <iostream>
    #include <thread>
    #include <cstdlib>
    using namespace std;

    void hello()
    {
        cout << "hello world\n";
    }

    class Zero
    {
        int *d_data;
        size_t d_size;
        int d_value;
        public:
            Zero(int *data, size_t size, int value)
            :
                d_data(data),
                d_size(size),
                d_value(value)
            {}
            void operator()()
            {
                for (int *ptr = d_data + d_size; ptr-- != d_data; )
                    *ptr = d_value;
            }
    };

    int main()
    {
        int data[30];
        Zero zero(data, 30, 0);
        thread t1(zero);
        thread t2(hello);
        t1.join();
        t2.join();
    };
