    #include "stringstore.h"
    #include <iostream>
    
    using namespace std;;

    void display(StringStore const &store)
    {
        for (size_t idx = 0; idx != store.size(); ++idx)
            cout << store.at(idx) << '\n';
    }

    StringStore *process(char *argv[], int argc)
    {
        StringStore store(argv, argc);
        display(store);
        return new StringStore(argv, argc);
    }

    int main(int argc, char *argv[])
    {
        StringStore *sp = process(argv, argc);
        delete sp;

        char buffer[sizeof(StringStore)];
        sp = new (buffer) StringStore(argv, argc);
        sp->~StringStore();
    }

        
