#include <string>
#include <iostream>
#include <memory>


class Mutable
{
    std::string d_name;
    mutable int d_count;                // uses mutable keyword

    public:
        Mutable(std::string const &name)
        :
            d_name(name),
            d_count(0)
        {}

        void called() const
        {
            std::cout << "Calling " << d_name <<
                                    " (attempt " << ++d_count << ")\n";
        }
};


int main()
{
    Mutable const x("Constant mutable object");

    for (int idx = 0; idx < 4; idx++)
        x.called();                     // modify data of const object
}

/*
    Generated output:

    Calling Constant mutable object (attempt 1)
    Calling Constant mutable object (attempt 2)
    Calling Constant mutable object (attempt 3)
    Calling Constant mutable object (attempt 4)
*/
