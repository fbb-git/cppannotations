    #include "strings.h"
    #include <iostream>

    using namespace std;;

    void display(Strings const &store)
    {
        for (size_t idx = 0; idx != store.size(); ++idx)
            cout << store.at(idx) << '\n';
    }

    Strings *process(char *argv[], size_t argc)
    {
        Strings store{ argv, argc };
        display(store);
        return new Strings{ argv, argc };
    }

    int main(int argc, char *argv[])
    {
        Strings *sp = process(argv, argc);
        delete sp;

        char buffer[sizeof(Strings)];
        sp = new (buffer) Strings{ argv, static_cast<size_t>(argc) };
        sp->~Strings();
    }
