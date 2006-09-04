    #include <iostream>
        // the following header file must be available in the compiler's
        // INCLUDE path:
    #include <hashclasses.h>
    using namespace std;
    using namespace FBB;

    int main()
    {
        __gnu_cxx::hash_map<string, int, HashString > months;
        // Alternatively, using the classes defined in hashclasses.h,
        // the following definitions could have been used:
        //      CharPtrHash<int> months;
        // or:
        //      StringHash<int> months;

        months["january"] = 31;
        months["february"] = 28;
        months["march"] = 31;
        months["april"] = 30;
        months["may"] = 31;
        months["june"] = 30;
        months["july"] = 31;
        months["august"] = 31;
        months["september"] = 30;
        months["october"] = 31;
        months["november"] = 30;
        months["december"] = 31;

        cout << "september -> " << months["september"] << endl <<
                "april     -> " << months["april"] << endl <<
                "june      -> " << months["june"] << endl <<
                "november  -> " << months["november"] << endl;
    }
    /*
        Generated output:
    september -> 30
    april     -> 30
    june      -> 30
    november  -> 30
    */
