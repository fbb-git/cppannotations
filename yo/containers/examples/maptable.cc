    #include <iostream>
    #include <iomanip>
    #include <map>

    using namespace std;

    int main()
    {
        pair<string, int>
            pa[] =
            {
                pair<string,int>("one", 10),
                pair<string,int>("two", 20),
                pair<string,int>("three", 30),
            };
        map<string, int>
            object(&pa[0], &pa[3]);

        for
        (
            map<string, int>::iterator it = object.begin();
                it != object.end();
                    ++it
        )
            cout << setw(5) << it->first.c_str() <<
                    setw(5) << it->second << endl;
    }
    /*
        Generated output:
      one   10
    three   30
      two   20
    */
