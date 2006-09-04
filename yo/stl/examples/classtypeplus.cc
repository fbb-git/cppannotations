    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    #include <functional>
    #include <numeric>

    using namespace std;

    class Time
    {
        friend ostream &operator<<(ostream &str, Time const &time)
        {
            return cout << time.d_days << " days, " << time.d_hours <<
                                                        " hours, " <<
                            time.d_minutes << " minutes and " <<
                            time.d_seconds << " seconds.";
        }

        unsigned d_days;
        unsigned d_hours;
        unsigned d_minutes;
        unsigned d_seconds;

        public:
            Time(unsigned hours, unsigned minutes, unsigned seconds)
            :
                d_days(0),
                d_hours(hours),
                d_minutes(minutes),
                d_seconds(seconds)
            {}
            Time &operator+=(Time const &rValue)
            {
                d_seconds   += rValue.d_seconds;
                d_minutes   += rValue.d_minutes   + d_seconds / 60;
                d_hours     += rValue.d_hours     + d_minutes / 60;
                d_days      += rValue.d_days      + d_hours   / 24;
                d_seconds   %= 60;
                d_minutes   %= 60;
                d_hours     %= 24;

                return *this;
            }
    };
    Time const operator+(Time const &lValue, Time const &rValue)
    {
        return Time(lValue) += rValue;
    }

    int main(int argc, char **argv)
    {
        vector<Time> tvector;

        tvector.push_back(Time( 1, 10, 20));
        tvector.push_back(Time(10, 30, 40));
        tvector.push_back(Time(20, 50,  0));
        tvector.push_back(Time(30, 20, 30));

        cout <<
            accumulate
            (
                tvector.begin(), tvector.end(), Time(0, 0, 0), plus<Time>()
            ) <<
            endl;
    }
    /*
        produced output:

        2 days, 14 hours, 51 minutes and 30 seconds.
    */
