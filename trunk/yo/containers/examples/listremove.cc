    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;

    int main()
    {
        list<string> object;

        object.push_back(string("Hello"));
        object.push_back(string("World"));
        object.push_back(string("Hello"));
        object.push_back(string("World"));

        object.remove(string("Hello"));

        while (object.size())
        {
            cout << object.front() << '\n';
            object.pop_front();
        }
    }
    /*
            Generated output:
        World
        World
    */
