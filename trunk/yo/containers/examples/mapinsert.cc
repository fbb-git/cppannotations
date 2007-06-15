    #include <iostream>
    #include <string>
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

                // {four, 40} and `true' is returned
        pair<map<string, int>::iterator, bool>
            ret = object.insert
                    (
                        map<string, int>::value_type
                        ("four", 40)
                    );

        cout << boolalpha;

        cout << ret.first->first << " " <<
            ret.first->second << " " <<
            ret.second << " " << object["four"] << endl;

                // {four, 40} and `false' is returned
        ret = object.insert
                    (
                        map<string, int>::value_type
                        ("four", 0)
                    );

        cout << ret.first->first << " " <<
            ret.first->second << " " <<
            ret.second << " " << object["four"] << endl;
    }
    /*
        Generated output:

        four 40 true 40
        four 40 false 40
    */
