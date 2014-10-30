#include <iostream>
#include <fstream>
#include <future>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

//code
mutex carDetailsMutex;
condition_variable condition;
string carDetails;
packaged_task<size_t (std::string const &)> serviceTask;

size_t volkswagen(string const &type)
{
    cout << "performing maintenance by the book for a " << type << '\n';
    return type.size() * 75;            // the size of the bill
}

size_t peugeot(string const &type)
{
    cout << "performing quick and dirty maintenance for a " << type << '\n';
    return type.size() * 50;             // the size of the bill
}

void garage()
{
    while (true)
    {
        unique_lock<mutex> lk(carDetailsMutex);
        while (carDetails.empty())
            condition.wait(lk);

        cout << "servicing a " << carDetails << '\n';
        serviceTask(carDetails);
        carDetails.clear();
    }
}

int main()
{
    thread(garage).detach();

    while (true)
    {
        string car;
        if (not getline(cin, car) || car.empty())
            break;
        {
            lock_guard<mutex> lk(carDetailsMutex);
            carDetails = car;
        }
        serviceTask =  packaged_task<size_t (string const &)>(
                    car[0] == 'v' ? volkswagen : peugeot
                );
        auto bill = serviceTask.get_future();
        condition.notify_one();
        cout << "Bill for servicing a " << car <<
                                ": EUR " << bill.get() << '\n';
    }
}
//=
