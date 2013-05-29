#include <iostream.h>

class Object
{
    public:
        Object(char const *name);
        ~Object();
        void fun();
        void hello();
    private:
        char const
            *name;
};
/*
Object::Object(char const *n)
{
    name = n;
    cout << "Object constructor of " << name << "\n";
}

Object::~Object()
{
    cout << "Object destructor of " << name << "\n";
}

void Object::fun()
{
    cout << "Object fun() of " << name << "\n";
    throw new Object("'new object'");
}

void Object::hello()
{
    cout << "Hello by " << name << "\n";
}

*/
void emptythrow(Object *o)

{
            cout << "Caught exception\n";
            o->hello();
    throw;
}

/*
int main()
{
    Object
        out("'main object'");

    try
    {
        try
        {
            out.fun();
        }
        catch (Object *o)
        {
            emptythrow(o);
        }
    }
    catch (Object *o)
    {
        cout << "Caught exception again\n";
        o->hello();
        delete o;
    }
}

*/
