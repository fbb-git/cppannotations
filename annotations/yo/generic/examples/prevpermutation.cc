    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <iterator>
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
        string  saints[] = {"Oh", "when", "the", "saints"};

        cout << "All previous permutations of 'Oh when the saints':\n";
        cout << "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << '\n';
        }
        while (prev_permutation(saints, saints + 4, CaseString()));

        cout << "After first sorting the sequence:\n";
        sort(saints, saints + 4, CaseString());
        cout << "Sequences:\n";
        while (prev_permutation(saints, saints + 4, CaseString()))
        {
            copy(saints, saints + 4, ostream_iterator<string>(cout, " "));
            cout << '\n';
        }
        cout << "No (more) previous permutations\n";
    }
    /*
        Displays:
            All previous permutations of 'Oh when the saints':
            Sequences:
            Oh when the saints
            Oh when saints the
            Oh the when saints
            Oh the saints when
            Oh saints when the
            Oh saints the when
            After first sorting the sequence:
            Sequences:
            No (more) previous permutations
    */
