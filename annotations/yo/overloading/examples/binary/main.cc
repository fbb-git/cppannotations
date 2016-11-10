#include "main.ih"

int main(int argc, char **argv)
{
//    Binary b1{1};                      // default
//    Binary b2{b1};                  // copy
//    Binary &&ref = Binary{2};        // rref construction
//    Binary b3(move(ref));           // move construction
//    Binary b4{Binary{3}};            // move-constructor copy elision
    Binary b1{1};
    Binary b2{2};
    Binary b3{3};

    cout << "\n1 ======================\n";

//    b1 + b2 + b3;

//    cout << "\n2 ======================\n";
//
//   (Binary{4} += b1) += b2;

//    b1 += b2 += b3;
    Binary{1} += b2 += b3;

    cout << "\n3 ======================\n";
}
