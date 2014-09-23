#include "tabber.ih"

void Tabber::run(char const *inName, char const *outName)
{
    ifstream in(inName);
    ofstream out(outName);

    d_in.rdbuf(in.rdbuf());
    d_out.rdbuf(out.rdbuf());

    run();
}
