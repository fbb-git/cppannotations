    // accumulating strings from a vector to one big string, using
    // `accumulate'.
    #include <iostream>
    #include <numeric>
    #include <string>
    #include <vector>
    #include <bobcat/fnwrap2c>

    using namespace std;
    using namespace FBB;

    class Strings
    {
        vector<string> d_vs;

        public:
            Strings()
            {
                d_vs.push_back("one");
                d_vs.push_back("two");
                d_vs.push_back("three");
            }

            void display(ostream &out) const
            {
                SContext c = {1, out};

                cout << "On Exit: " <<
                    accumulate(
                        d_vs.begin(), d_vs.end(),
                        string("HI"),
                        FnWrap2c<string const &, string const &,
                                 SContext &, string>(&show, c)
                    ) <<
                    endl;
            }

        private:
            struct SContext
            {
                size_t nr;
                ostream &out;
            };

            static string show(string const &str1,
                                    string const &str2,
                                    SContext &c)
            {
                c.out << c.nr++ << " " << str1 << " " << str2 <<
                         endl;
                return str1 + " " + str2;
            }
    };

    int main()
    {
        Strings s;
        s.display(cout);
    }
