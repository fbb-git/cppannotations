    #include <iostream>
    #include <map>
    using namespace std;

    int main()
    {
        pair<string, int> pa[] =
        {
            pair<string,int>("one", 10),
            pair<string,int>("two", 20),
            pair<string,int>("three", 30),
        };
        map<string, int> object(&pa[0], &pa[3]);
        map<string, int>::iterator it;

        if ((it = object.lower_bound("tw")) != object.end())
            cout << "lower-bound `tw' is available, it is: " <<
                    it->first << '\n';

        if (object.lower_bound("twoo") == object.end())
            cout << "lower-bound `twoo' not available" << '\n';

        cout << "lower-bound two: " <<
                object.lower_bound("two")->first <<
                " is available\n";

        if ((it = object.upper_bound("tw")) != object.end())
            cout << "upper-bound `tw' is available, it is: " <<
                    it->first << '\n';

        if (object.upper_bound("twoo") == object.end())
            cout << "upper-bound `twoo' not available" << '\n';

        if (object.upper_bound("two") == object.end())
            cout << "upper-bound `two' not available" << '\n';

        pair
        <
            map<string, int>::iterator,
            map<string, int>::iterator
        >
            p = object.equal_range("two");

        cout << "equal range: `first' points to " <<
                    p.first->first << ", `second' is " <<
            (
                p.second == object.end() ?
                    "not available"
                :
                    p.second->first
            ) <<
            '\n';
    }
    /*
        Generated output:

            lower-bound `tw' is available, it is: two
            lower-bound `twoo' not available
            lower-bound two: two is available
            upper-bound `tw' is available, it is: two
            upper-bound `twoo' not available
            upper-bound `two' not available
            equal range: `first' points to two, `second' is not available
    */
