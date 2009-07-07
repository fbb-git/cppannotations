    #include <unordered_map>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        unordered_map<string, int> months;

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
