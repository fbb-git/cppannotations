#include "main.ih"

int main(int argc, char **argv)
try
{
    thread workers[] =
        {
            thread(process, 1),
            thread(process, 2),
            thread(process, 3),
            thread(process, 4)
        };

    string line;
    while (getline(cin, line) && not line.empty())
        dispatch(line);

    line = "q";
    for (size_t nr = 0; nr != 4; ++nr)
        dispatch(line);

    for (auto &worker: workers)
        worker.join();
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << '\n';
}
