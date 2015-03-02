#include "main.ih"

template <class Vehicle>
void fun(Vehicle &vehicle)
{
    cout << vehicle.mass() << '\n';
}

int main(int argc, char **argv)
{
    Car car;
    fun(car);

    Truck truck;
    fun(truck);
}
