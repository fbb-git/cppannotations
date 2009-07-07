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
            return hash<std::string const &>()(str);
        }
    };
    int main()
    {
        unordered_map<char const *, int, HashCp, EqualCp> months;

        months["april"] = 30;
        months["november"] = 31;

        string apr("april");    // different pointers, same string

        cout << "april     -> " << months["april"] << endl <<
                "april     -> " << months[apr.c_str()] << endl;
    }
