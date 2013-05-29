    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    class CaseString
    {
        public:
            bool operator()(string const &first, string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };
    int main()
    {
        string saints[] = {"Oh", "when", "the", "saints"};

        cout << "All permutations of 'Oh when the saints':\n";
        cout << "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << '\n';
        }
        while (next_permutation(saints, saints + 4, CaseString()));

        cout << "After first sorting the sequence:\n";
        sort(saints, saints + 4, CaseString());
        cout << "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << '\n';
        }
        while (next_permutation(saints, saints + 4, CaseString()));
    }
    /*
        Displays (partially):
            All permutations of 'Oh when the saints':
            Sequences:
            Oh when the saints
            saints Oh the when
            saints Oh when the
            saints the Oh when
            ...
            After first sorting the sequence:
            Sequences:
            Oh saints the when
            Oh saints when the
            Oh the saints when
            Oh the when saints
            ...
    */
