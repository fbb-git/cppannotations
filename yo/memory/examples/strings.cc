#include <string>
#include <cstring>

class Strings
{
    std::string *d_memory;
    size_t d_size;
    size_t d_capacity;

    public:
        Strings(Strings &&tmp);
        ~Strings();
        void reserve(size_t request);
        void append(std::string const &next);

    private:
        void reserve();
};

//RESERVE
void Strings::reserve()
{
    using std::string;

    string *newMemory =
        static_cast<string *>(memcpy(
                                 operator new(d_capacity),
                                 d_memory,
                                 d_size * sizeof(string)
                             ));

    delete d_memory;
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
    using std::string;

//DESTROY
    for (string *sp = d_memory + d_size; sp-- != d_memory; )
        sp->~string();

    operator delete(d_memory);
//=
}
