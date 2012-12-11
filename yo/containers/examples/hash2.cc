    #include <unordered_map>
    #include <iostream>
    #include <string>
    #include <cstring>

    using namespace std;

    struct EqualCp
    {
        bool operator()(char const *l, char const *r) const
        {
            return strcmp(l, r) == 0;
        }
    };
    struct HashCp
    {
        size_t operator()(char const *str) const
        {
            return std::hash<std::string>()(str);
        }
    };
    int main()
    {
        unordered_map<char const *, int, HashCp, EqualCp> months;
        // or explicitly:
            unordered_map<char const *, int, HashCp, EqualCp> 
                                      monthsTwo(61, HashCp(), EqualCp());

        months["april"] = 30;
        months["november"] = 31;

        string apr("april");    // different pointers, same string

        cout << "april     -> " << months["april"] << '\n' <<
                "april     -> " << months[apr.c_str()] << '\n';
    }
