#include <stdio.h>

class Test
{
    // datavelden:
    char *n;                    // naam-dataveld

    public:
        // constructoren:
        Test ();                    // parameter-vrije
        Test (char const *name);    // met een naam
        // destructor:
        ~Test ();
};

Test::Test ()
{
    n = "without name";
    printf ("Test object without name created\n");
}

Test::Test (char const *name)
{
    n = (char *) name;
    printf ("Test object %s created\n", n);
}

Test::~Test ()
{
    printf ("Test object %s destroyed\n", n);
}

Test
    globaltest ("global");

void func ()
{
    Test
        functest ("func");
}

int main ()
{
    Test
        maintest ("main");

    func ();
}
