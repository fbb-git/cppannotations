#include <iostream>

using namespace std;

template <class Derived>
class Vehicle
{
    public:
        void mass()
        {
            static_cast<Derived *>(this)->vmass();
        }

    // no need to implement vmass here, as it should be implemented
    // by derived classes.
};

class Car: public Vehicle<Car>
{
    friend void Vehicle<Car>::mass();

    private:
        void vmass()
        {
            cout << "Car's vmass called\n";
        }
};

class Truck: public Car, public Vehicle<Truck>
{
    friend void Vehicle<Car>::mass();
    private:
        void vmass()
        {
            cout << "Car's vmass called\n";
        }
};

int main()
{
    Truck{}.mass();
}
