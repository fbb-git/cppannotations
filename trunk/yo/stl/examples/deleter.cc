    #include <iostream>
    #include <string>
    #include <memory>
    using namespace std;

    struct Deleter
    {
        size_t d_size;
        Deleter(size_t size = 0)
        :
            d_size(size)
        {}
        void operator()(string **ptr) const
        {
            for (size_t idx = 0; idx < d_size; ++idx)
                delete ptr[idx];
            delete[] ptr;
        }
    };
    int main()
    {
        unique_ptr<string *, Deleter> sp2(new string *[10], Deleter(10));

        Deleter &obj = sp2.get_deleter();
    }
