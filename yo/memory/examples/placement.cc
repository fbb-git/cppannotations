#include <iostream>
using namespace std;

class Object
{
    public:
        Object();
        ~Object();
};
inline Object::Object()
{
    cout << "Constructor\n";
};
inline Object::~Object()
{
    cout << "Destructor\n";
};

int main()
{
    char buffer[2 * sizeof(Object)];

    Object *obj = new(buffer) Object;       // placement new, 1st object
    new(buffer + sizeof(Object)) Object;    // placement new, 2nd object

    // delete obj;                          // DON'T DO THIS

    obj[0].~Object();                       // destroy 1st object
    obj[1].~Object();                       // destroy 2nd object
}

// Displays:
//  Constructor
//  Constructor
//  Destructor
//  Destructor
