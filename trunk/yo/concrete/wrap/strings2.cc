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
            void uppercase(std::ostream &out, char const *letters);

        private:
            static void xform(std::string &str, Context &context);
            static void foundToUpper(char &ch, std::string const &letters);
    };

    void Strings::uppercase(std::ostream &out, char const *letters)
    {
        Context context = {out, letters};

        for_each(d_vs.begin(), d_vs.end(),
            FnWrap1c<std::string &, Context &>(xform, context));
    }

    void Strings::xform(std::string &str, Context &context)
    {
        context.out << str << " ";

        for_each(str.begin(), str.end(),
            FnWrap1c<char &, std::string const &>(
                                        foundToUpper, context.letters));

        context.out << str << std::endl;
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
