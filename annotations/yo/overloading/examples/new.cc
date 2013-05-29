    #include <iostream>
    using namespace std;

    static size_t count = 0;

    class X
    {
        int x;

        public:
            X()
            {
                if (count == 2)
                    throw 1;
                cout << "Object " << ++count << '\n';
            }
            ~X()
            {
                cout << "Destroyed " << this << "\n";
            }
            void *operator new[](size_t size)
            {
                cout << "Allocating objects: " << size << " bytes\n";
                return ::operator new(size);
            }
            void operator delete[](void *mem)
            {
                cout << "Deleting memory at " << mem << ", containing: " <<
                    *static_cast<int *>(mem) << "\n";
                ::operator delete(mem);
            }
    };

    int main()
    try
    {
        X *xp = new X[5];
        cout << "Memory at " << xp << '\n';
        delete[] xp;
    }
    catch (...)
    {
        cout << "Caught exception.\n";
    }
    // Output from this program (your 0x??? addresses might differ)
    //  Allocating objects: 24 bytes
    //  Object 1
    //  Object 2
    //  Destroyed 0x8428010
    //  Destroyed 0x842800c
    //  Deleting memory at 0x8428008, containing: 5
    //  Caught exception.
