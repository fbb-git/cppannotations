#include <string>
#include <iostream>

using namespace std;

class Strings
{
    std::string *d_memory;
    size_t d_size;
    size_t d_capacity;

    public:
        Strings();
        ~Strings();
        void reserve(size_t request);
        void append(std::string const &next);

    private:
        void reserve();
        void destroy();
};

Strings::Strings()
:
    d_memory(static_cast<string *>(operator new(sizeof(string)))),
    d_size(0),
    d_capacity(1)
{}

void Strings::reserve(size_t request)
{
    if (request <= d_capacity)
        return;
    do
        d_capacity <<= 1;
    while (d_capacity < request);
    reserve();
}

//RESERVE
void Strings::reserve()
{
    using std::string;

    string *newMemory = static_cast<string *>(                  // 1
                            operator new(d_capacity * sizeof(string)));
    for (size_t idx = 0; idx != d_size; ++idx)                  // 2
        new (newMemory + idx) string(d_memory[idx]);
    destroy();                                                  // 3
    d_memory = newMemory;
}
//=

//APPEND
void Strings::append(std::string const &next)
{
    reserve(d_size + 1);
    new (d_memory + d_size) std::string(next);
    ++d_size;
}
//=

Strings::~Strings()
{
    destroy();
}

//DESTROY
void Strings::destroy()
{
    for (std::string *sp = d_memory + d_size; sp-- != d_memory; )
        sp->~string();

    operator delete(d_memory);
}
//=
