#include <iostream>

using namespace std;

class VehicleBase
{
    // original Vehicle members, not implementing the
    // redefinable interface, but used as a implementable rather than
    // instantiatable part of the corresponding class template.
    // That's why it declares its corresponding class template a friend.

    template <class Derived>
    friend class Vehicle;

    size_t d_massFactor = 1;
};

template <class Derived>
class Vehicle: public VehicleBase
{
    public:
        int mass() const
        {
            return d_massFactor *
                    static_cast<Derived const *>(this)->vmass();
        }
};

class CarBase: public VehicleBase
{
    // original Car members, not implementing the
    // redefinable interface

    int x = 1000;
    friend class Car;
};

class Car: public CarBase, public Vehicle<Car>
{
    friend class Vehicle<Car>;

    int vmass() const
    {
       return x;
    }
};

class TruckBase: public CarBase
{
    // original Truck members, not implementing the
    // redefinable interface

    friend class Truck;
};

class Truck: public TruckBase, public Vehicle<Truck>
{
    friend class Vehicle<Truck>;

    private:
        int vmass() const
        {
            return 15000;
        }
};

template <class Vehicle>
void fun(Vehicle &vehicle)
{
    cout << vehicle.mass() << '\n';
}

int main()
{
    Car car;
    fun(car);

    Truck truck;
    fun(truck);
}
