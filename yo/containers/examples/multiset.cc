    #include <iostream>
    #include <set>

    using namespace std;

    int main()
    {
        string
            sa[] =
            {
                "alpha",
                "echo",
                "hotel",
                "mike",
                "romeo"
            };

        multiset<string>
            object(&sa[0], &sa[5]);

        object.insert("echo");
        object.insert("echo");

        multiset<string>::iterator
            it = object.find("echo");

        for (; it != object.end(); ++it)
            cout << *it << " ";
        cout << '\n';

        cout << "Multiset::equal_range(\"ech\")\n";
        pair
        <
            multiset<string>::iterator,
            multiset<string>::iterator
        >
            itpair = object.equal_range("ech");

        if (itpair.first != object.end())
            cout << "lower_bound() points at " << *itpair.first << '\n';
        for (; itpair.first != itpair.second; ++itpair.first)
            cout << *itpair.first << " ";

        cout << '\n' <<
                object.count("ech") << " occurrences of 'ech'" << '\n';

        cout << "Multiset::equal_range(\"echo\")\n";
        itpair = object.equal_range("echo");

        for (; itpair.first != itpair.second; ++itpair.first)
            cout << *itpair.first << " ";

        cout << '\n' <<
                object.count("echo") << " occurrences of 'echo'" << '\n';

        cout << "Multiset::equal_range(\"echoo\")\n";
        itpair = object.equal_range("echoo");

        for (; itpair.first != itpair.second; ++itpair.first)
            cout << *itpair.first << " ";

        cout << '\n' <<
                object.count("echoo") << " occurrences of 'echoo'" << '\n';
    }
    /*
        Generated output:

        echo echo echo hotel mike romeo
        Multiset::equal_range("ech")
        lower_bound() points at echo

        0 occurrences of 'ech'
        Multiset::equal_range("echo")
        echo echo echo
        3 occurrences of 'echo'
        Multiset::equal_range("echoo")

        0 occurrences of 'echoo'
    */
