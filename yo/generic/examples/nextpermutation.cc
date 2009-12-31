    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>

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

        return 0;
    }
    /*
        Displays (only partially given):

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
