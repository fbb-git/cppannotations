    #include <iostream>
    #include <memory>
    using namespace std;

    template <typename Type, size_t size>
    struct Deleter
    {
        void operator()(Type * ptr) const
        {
            for (size_t idx = 0; idx < size; ++idx)
                delete ptr[idx];
            delete ptr;
        }
    };
    int main()
    {
        unique_ptr<int *, Deleter<int *, 10>> sp2(new int *[10]);

        Deleter<int *, 10> &obj = sp2.get_deleter();
    }
