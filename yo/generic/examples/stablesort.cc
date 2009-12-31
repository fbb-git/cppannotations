    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>

    typedef std::pair<std::string, std::string>  pss;   // 1 (see the text)

    namespace std
    {
        ostream &operator<<(ostream &out, pss const &p)                 // 2
        {
            return out << "    " << p.first << " " << p.second << '\n';
        }
    }

    class sortby
    {
        std::string pss::*d_field;
        public:
            sortby(std::string pss::*field)                             // 3
            :
                d_field(field)
            {}

            bool operator()(pss const &p1, pss const &p2) const         // 4
            {
                return p1.*d_field < p2.*d_field;
            }
    };

    using namespace std;

    int main()
    {
        vector<pss> namecity;                                           // 5

        namecity.push_back(pss("Hampson",   "Godalming"));
        namecity.push_back(pss("Moran",     "Eugene"));
        namecity.push_back(pss("Goldberg",  "Eugene"));
        namecity.push_back(pss("Moran",     "Godalming"));
        namecity.push_back(pss("Goldberg",  "Chicago"));
        namecity.push_back(pss("Hampson",   "Eugene"));

        sort(namecity.begin(), namecity.end(), sortby(&pss::first));    // 6

        cout << "sorted by names:\n";
        copy(namecity.begin(), namecity.end(), ostream_iterator<pss>(cout));

                                                                        // 7
        stable_sort(namecity.begin(), namecity.end(), sortby(&pss::second));

        cout << "sorted by names within sorted cities:\n";
        copy(namecity.begin(), namecity.end(), ostream_iterator<pss>(cout));

        return 0;
    }
    /*
        Displays:

        sorted by names:
            Goldberg Eugene
            Goldberg Chicago
            Hampson Godalming
            Hampson Eugene
            Moran Eugene
            Moran Godalming
        sorted by names within sorted cities:
            Goldberg Chicago
            Goldberg Eugene
            Hampson Eugene
            Moran Eugene
            Hampson Godalming
            Moran Godalming
    */
