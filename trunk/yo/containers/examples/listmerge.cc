    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;

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
        list<string> first;
        list<string> second;

        first.push_back(string("alpha"));
        first.push_back(string("bravo"));
        first.push_back(string("golf"));
        first.push_back(string("quebec"));

        second.push_back(string("oscar"));
        second.push_back(string("mike"));
        second.push_back(string("november"));
        second.push_back(string("zulu"));

        first.merge(second);
        showlist(first);
    }
