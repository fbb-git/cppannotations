    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };

    using namespace std;

    int main()
    {
        string range1[] =
            {                                       // 5 elements
                "alpha", "bravo", "foxtrot", "hotel", "zulu"
            };
        string range2[] =
            {                                       // 4 elements
                "echo", "delta", "golf", "romeo"
            };
        string result[5 + 4];


        copy(result,
            merge(range1, range1 + 5, range2, range2 + 4, result),
            ostream_iterator<string>(cout, " "));
        cout << endl;

        string range3[] =
            {
                "ALPHA", "bravo", "foxtrot", "HOTEL", "ZULU"
            };
        string range4[] =
            {
                "delta", "ECHO", "GOLF", "romeo"
            };

        copy(result,
            merge(range3, range3 + 5, range4, range4 + 4, result,
                                                            CaseString()),
            ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        alpha bravo echo delta foxtrot golf hotel romeo zulu
        ALPHA bravo delta ECHO foxtrot GOLF HOTEL romeo ZULU
    */
