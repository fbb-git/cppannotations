    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string line;

        getline(cin, line);

        string::size_type pos;

        cout << "Line: " << line << endl
            << "Starting at the first vowel:\n"
            << "'"
                << (
                    (pos = line.find_first_of("aeiouAEIOU"))
                    != string::npos ?
                        line.substr(pos)
                    :
                        "*** not found ***"
                    ) << "'\n"
            << "Starting at the last vowel:\n"
            << "'"
                << (
                    (pos = line.find_last_of("aeiouAEIOU"))
                    != string::npos ?
                        line.substr(pos)
                    :
                        "*** not found ***"
                    ) << "'\n"
            << "Starting at the first non-digit:\n"
            << "'"
                << (
                    (pos = line.find_first_not_of("1234567890"))
                    != string::npos ?
                        line.substr(pos)
                    :
                        "*** not found ***"
                    ) << "'\n";
    }
