#include <string>
#include <cstring>

class Strings
{
    char *d_memory;
    size_t d_size;
    size_t d_capacity;
    
    public:
        ~Strings();
        void reserve(size_t request);
        void append(std::string const &next);

    private:
        void reserve();
};

//RESERVE
void Strings::reserve()
{
    char *newMemory = 
        static_cast<char *>(memcpy(
                                operator new(d_capacity), 
                                d_memory, 
                                d_size * sizeof(std::string)
                            ));

    delete d_memory;
    d_memory = newMemory;
}
//=

//APPEND
void Strings::append(std::string const &next)
{
    reserve(d_size + 1);

    new (reinterpret_cast<std::string *>(d_memory) + d_size)
        std::string(next);

    ++d_size;
}
//=

Strings::~Strings()
{
    using std::string;

//DESTROY
    for 
    (
        string *sp = reinterpret_cast<string *>(d_memory) + d_size;
            sp-- != reinterpret_cast<string *>(d_memory);
    )
        sp->~string();

    delete d_memory;
//=
}

    

