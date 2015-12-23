    #include <iostream>
    #include <chrono>
    #include <iomanip>

    using namespace std;

    struct days: public chrono::hours
    {
        days(size_t count)
        :
            chrono::hours(count * 24)
        {}
    };

    int main()
    {
            // get the current time
        chrono::time_point<chrono::system_clock>
                                timePoint{chrono::system_clock::now()};

            // convert it to a std::time_t:
        time_t time = chrono::system_clock::to_time_t(timePoint);

            // show the time in seconds since the epoch:
        cout << time << '\n';

            // get a std::tm value:
        tm tmValue{*localtime(&time)};

            // display the time:
        cout << put_time(&tmValue, "current time: %c") << '\n';

            // display the time in rfc2822 format:
        cout << put_time(&tmValue, "rfs2822 format: %a, %e %b %Y %T %z")
                                                                    << '\n';

            // modifiy 'timePoint':
        timePoint += days(7);

            // convert timePoint's value to std::time_t:
        time = chrono::system_clock::to_time_t(timePoint);

            // display the gmtime, directly using gmtime's return value:
        cout << put_time(gmtime(&time),
                        "gmtime, one week from now:  %c %z") << '\n';
    }
