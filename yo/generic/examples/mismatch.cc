    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <utility>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) == 0;
            }
    };

    using namespace std;

    int main()
    {
        string range1[] =
            {
                "alpha", "bravo", "foxtrot", "hotel", "zulu"
            };
        string range2[] =
            {
                "alpha", "bravo", "foxtrot", "Hotel", "zulu"
            };
        pair<string *, string *> pss = mismatch(range1, range1 + 5, range2);

        cout << "The elements " << *pss.first << " and " << *pss.second <<
                " at offset " << (pss.first - range1) << " differ\n";
        if
        (
            mismatch(range1, range1 + 5, range2, CaseString()).first
            ==
            range1 + 5
        )
            cout << "When compared case-insensitively they match\n";

        return 0;
    }
    /*
        Displays:

        The elements hotel and Hotel at offset 3 differ
        When compared case-insensitively they match
    */
