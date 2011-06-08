#include <iostream>
using namespace std;

// The default move acts like the default copy cons (i.e., it merely copies
// the soucce to the destination, calling the move, rather than copy
// constructors of movable data members). Declaring it allows the
// compiler to select it whenever possible, possibly avoiding a copy
// construction.  Use only if you know what you are doing. The example below
// illustrates a situation where it should NOT be used, as the memory
// allocated by the first factory() function will be deleted twice.


struct Copy
{
    Copy()
    {
        cout << "Copy default cons\n";
    }
    Copy(Copy const &other)
    {
        cout << "Copy copycons\n";
    }
    Copy(Copy &&tmp)
    {
        cout << "Copy movecons\n";
    }
    ~Copy()
    {
        cout << "Copy destr.\n";
    }
};

struct Move
{
    int *d_ptr;
    Copy d_cp;

    Move()
    :
        d_ptr(new int(4))
    {}
    Move(Move &&tmp) = default;
    Move(Move const &other)
    :
        d_ptr(new int(5)),
        d_cp(other.d_cp)
    {
        cout << "copy const\n";
    }
    ~Move()
    {
        cout << "d_ptr is " << d_ptr << '\n';
    }

};

Move factory()
{
    cout << "factory()\n";
    Move tmp;
    return tmp;
}

Move factory(Move &&tmp)
{
    cout << "factory(tmp)\n";
    return std::move(tmp);
}

int main()
{
    Move n(factory(factory()));
}
