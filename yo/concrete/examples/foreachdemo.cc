#include <iostream>
#include <string>
#include <vector>
#include "foreach.h"

//VECTOR2
    template <typename Type>
    class Vector2: public std::vector<std::vector<Type> >
    {
        template <typename Iterator, typename Class, typename Data>
        friend Class &ForEach(Iterator begin, Iterator end, Class &object,
                    void (Class::*member)(Data &));
        public:
            void process()
            {
                ForEach(begin(), end(), *this, &Vector2<Type>::rows);
            }
        private:
            void rows(std::vector<Type> &row)
            {
                ForEach(row.begin(), row.end(), *this,
                                                &Vector2<Type>::columns);
                std::cout << std::endl;
            }
            void columns(Type &str)
            {
                std::cout << str << " ";
            }
    };

    using namespace std;

    int main()
    {
        Vector2<string> c;
        c.push_back(vector<string>(3, "Hello"));
        c.push_back(vector<string>(2, "World"));

        c.process();
    }
    /*
        Generated output:

        Hello Hello Hello
        World World
    */
//=
