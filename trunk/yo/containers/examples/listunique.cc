    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;
                            // see the merge() example
    void showlist(list<string> &target);
    void showlist(list<string> &target)
    {
        for
        (
            list<string>::iterator from = target.begin();
            from != target.end();
            ++from
        )
            cout << *from << " ";

        cout << endl;
    }


    int main()
    {
        string
            array[] =
            {
                "charley",
                "alpha",
                "bravo",
                "alpha"
            };

        list<string>
            target
            (
                array, array + sizeof(array)
                / sizeof(string)
            );

        cout << "Initially we have: " << endl;
        showlist(target);

        target.sort();
        cout << "After sort() we have: " << endl;
        showlist(target);

        target.unique();
        cout << "After unique() we have: " << endl;
        showlist(target);
    }
    /*
        Generated output:

        Initially we have:
        charley alpha bravo alpha
        After sort() we have:
        alpha alpha bravo charley
        After unique() we have:
        alpha bravo charley
    */
