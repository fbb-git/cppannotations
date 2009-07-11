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
        public:
            Zero(int *data, size_t size)
            :
                d_data(data),
                d_size(size)
            {}
            void operator()(int arg) const
            {
                for (int *ptr = d_data + d_size; ptr-- != d_data; )
                    *ptr = 0;
            }
    };

    int main()
    {
        int data[30];
        Zero zero(data, 30);
        int value = 0;
        std::thread t1(zero, value);
        std::thread t2(hello);
    };


