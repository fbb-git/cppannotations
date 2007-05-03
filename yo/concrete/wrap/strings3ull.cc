    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    #include "fnwrap1.h"

    class Strings
    {
        std::vector<std::string> d_vs;

        struct Context
        {
            std::ostream &out;
            std::string letters;
        };

        public:
            Strings()
            {
                d_vs.push_back("hello");
                d_vs.push_back("world");
                d_vs.push_back("");
                d_vs.push_back("not transformed");
            }
            void uppercase(std::ostream &out, char const *letters);

        private:
            static bool xform(std::string &str, Context &context);
            static void foundToUpper(char &ch, std::string const &letters);
    };

    void Strings::uppercase(std::ostream &out, char const *letters)
    {
        Context context = {out, letters};

        find_if(d_vs.begin(), d_vs.end(),
            FnWrap1c<std::string &, Context &, bool>(xform, context));
    }

    bool Strings::xform(std::string &str, Context &context)
    {
        if (str.empty())
            return true;

        context.out << str << " ";

        for_each(str.begin(), str.end(), 
            FnWrap1c<char &, std::string const &>(
                                        foundToUpper, context.letters));

        context.out << str << std::endl;

        return false;
    }

    void Strings::foundToUpper(char &ch, std::string const &letters)
    {
        if (letters.find(ch) != std::string::npos)
            ch = toupper(ch);
    }

    using namespace std;

    int main(int argc, char **argv)
    {
        Strings s;

        s.uppercase(cout, argv[1]);
    }
