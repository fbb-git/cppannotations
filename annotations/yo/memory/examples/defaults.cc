#include <iostream>

using namespace std;

struct Mov
{
    Mov() = default;

    Mov(Mov const &)
    {
        cout << "   Copy cons\n\n";
    }
    Mov(Mov &&)
    {
        cout << "   Move cons\n\n";
    }
    void operator=(Mov const &)
    {
        cout << "   Copy =\n\n";
    }
    void operator=(Mov &&)
    {
        cout << "   Move =\n\n";
    }
};

class Defaults
{
    Mov d_mov;

    public:
        Defaults() = default;

        Defaults(int x);

//        Defaults(Defaults const &) { cout << "  copy cons\n\n"; }
        Defaults(Defaults &&) { cout << "  move cons\n\n"; }

        void operator=(int);

        void operator=(Defaults &&tmp) { cout << "  move op=\n\n"; }

//        void operator=(Defaults const &tmp) { cout << "  copy op=\n\n"; }
};


int main()
{                              // Mov operation:    resulting d_x:
                               // --------------------------------
  Defaults one;                // ERROR: not available

//    Defaults one(1);

//cout << "1 copy cons:\n";
//  Defaults two(one);           // Mov(Mov const &), one.d_x

cout << "2 move cons\n";    
    Defaults &&tmp = Defaults{};

  Defaults three{ move(tmp) };   // (RVO) ERROR: not available 
                               //  
//cout << "3 copy assign:\n";
//  one = two;                   // ERROR: not available

cout << "4 move assign:\n";
  one = move(tmp);             // Mov::operator=(   tmp.d_x
                               //      Mov &&tmp)
}





