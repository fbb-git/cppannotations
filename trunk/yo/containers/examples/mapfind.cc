    #include <iostream>
    #include <map>
    using namespace std;

    int main()
    {
        map<string, int> object;

        object["one"] = 1;

        map<string, int>::iterator it = object.find("one");

        cout << "`one' " <<
                (it == object.end() ? "not " : "") << "found\n";

        it = object.find("three");

        cout << "`three' " <<
                (it == object.end() ? "not " : "") << "found\n";
    }
    /*
        Generated output:
    `one' found
    `three' not found
    */
