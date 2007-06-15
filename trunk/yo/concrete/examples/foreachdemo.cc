#include <iostream>
#include <string>
#include <vector>
#include "foreach.h"

//VECTOR2
    template <typename Type>
    class Vector2: public std::vector<std::vector<Type> >
    {
        typedef typename Vector2<Type>::iterator iterator;

        template <typename Iterator, typename Class, typename Data>
        friend Class &ForEach(Iterator begin, Iterator end, Class &object,
                    void (Class::*member)(Data &));
        public:
            void process();

        private:
            void rows(std::vector<Type> &row);
            void columns(Type &str);
    };

    template <typename Type>
    void Vector2<Type>::process()
    {
        ForEach<iterator, Vector2<Type>, std::vector<Type> >
                (this->begin(), this->end(), *this, &Vector2<Type>::rows);
    }

    template <typename Type>
    void Vector2<Type>::rows(std::vector<Type> &row)
    {
        ForEach(row.begin(), row.end(), *this,
                                        &Vector2<Type>::columns);
        std::cout << std::endl;
    }

    template <typename Type>
    void Vector2<Type>::columns(Type &str)
    {
        std::cout << str << " ";
    }

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
