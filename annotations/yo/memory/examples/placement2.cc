#include <string>

int main()
{
//CODE
    using std::string;

    char buffer[3 * sizeof(string)];
    string *sp = new(buffer) string [3];

    for (size_t idx = 0; idx < 3; ++idx)
        sp[idx].~string();
//=
}
