    #include <iostream>
    #include <map>
    using namespace std;

    int main()
    {
        pair<string, int> pa[] =
        {
            pair<string,int>("alpha", 1),
            pair<string,int>("bravo", 2),
            pair<string,int>("charley", 3),
            pair<string,int>("bravo", 6),   // unordered `bravo' values
            pair<string,int>("delta", 5),
            pair<string,int>("bravo", 4),
        };
        multimap<string, int> object(&pa[0], &pa[6]);

        typedef multimap<string, int>::iterator msiIterator;

        msiIterator it = object.lower_bound("brava");

        cout << "Lower bound for `brava': " <<
                it->first << ", " << it->second << endl;

        it = object.upper_bound("bravu");

        cout << "Upper bound for `bravu': " <<
                it->first << ", " << it->second << endl;

        pair<msiIterator, msiIterator>
            itPair = object.equal_range("bravo");

        cout << "Equal range for `bravo':\n";
        for (it = itPair.first; it != itPair.second; ++it)
            cout << it->first << ", " << it->second << endl;
        cout << "Upper bound: " << it->first << ", " << it->second << endl;

        cout << "Equal range for `brav':\n";
        itPair = object.equal_range("brav");
        for (it = itPair.first; it != itPair.second; ++it)
            cout << it->first << ", " << it->second << endl;
        cout << "Upper bound: " << it->first << ", " << it->second << endl;
    }
    /*
        Generated output:

        Lower bound for `brava': bravo, 2
        Upper bound for `bravu': charley, 3
        Equal range for `bravo':
        bravo, 2
        bravo, 6
        bravo, 4
        Upper bound: charley, 3
        Equal range for `brav':
        Upper bound: bravo, 2
    */
