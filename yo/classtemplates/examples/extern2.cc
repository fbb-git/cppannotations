#include <vector>
#include <iostream>

extern void vectorUser();

int main()
{
    vectorUser();
}

// this part is never called. It is added to make sure all required 
// features of declared templates will also be instantiated.

namespace 
{
    void instantiator()
    {
        std::vector<int> vi;
        vi.size();
    }
}
