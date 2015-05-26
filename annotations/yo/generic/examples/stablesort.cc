    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>
    using namespace std;

    struct Pss: public pair<string, string>                         // 1
    {
        Pss(string const &s1, string const &s2)
        :
            pair<string, string>(s1, s2)
        {}
    };
    ostream &operator<<(ostream &out, Pss const &p)                 // 2
    {
        return out << "    " << p.first << " " << p.second << '\n';
    }
    class Sortby
    {
        string Pss::*d_field;
        public:
            Sortby(string Pss::*field)                              // 3
            :
                d_field(field)
            {}
            bool operator()(Pss const &p1, Pss const &p2) const     // 4
            {
                return p1.*d_field < p2.*d_field;
            }
    };
    int main()
    {
        vector<Pss> namecity {                                      // 5
                Pss("Hampson",   "Godalming"),
                Pss("Moran",     "Eugene"),
                Pss("Goldberg",  "Eugene"),
                Pss("Moran",     "Godalming"),
                Pss("Goldberg",  "Chicago"),
                Pss("Hampson",   "Eugene")
        };

        sort(namecity.begin(), namecity.end(), Sortby(&Pss::first));// 6

        cout << "sorted by names:\n";
        copy(namecity.begin(), namecity.end(), ostream_iterator<Pss>(cout));

                                                                    // 7
        stable_sort(namecity.begin(), namecity.end(), Sortby(&Pss::second));

        cout << "sorted by names within sorted cities:\n";
        copy(namecity.begin(), namecity.end(), ostream_iterator<Pss>(cout));
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
