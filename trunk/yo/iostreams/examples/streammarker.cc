    #include <iostream>
    #include <string>

    int main()
    {
        string
            line;

        getline(cin, line);

        streammarker
            mark(cin.rdbuf());

        getline(cin, line);

        streammarker
            mark2(cin.rdbuf());

        cout << "The beginning of the second line is at offset  " <<
            cin.tellg() + mark.delta() <<  '\n' <<
            "The length of the 2nd line, using 2 streammarker objects: " <<
            mark2.delta(mark) << '\n';

        cout << cin.rdbuf()->seekmark(mark) << '\n';
        getline(cin, line);
        cout << "rereading: " << line << '\n';
    }
    /*
        Using input:
    one
    two three
        Generated output:
    The beginning of the second line is at offset  4
    The length of the 2nd line, using 2 streammarker objects: 10
    0
    rereading: two three
    */
