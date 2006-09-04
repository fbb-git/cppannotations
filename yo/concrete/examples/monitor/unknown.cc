    #include "monitor.ih"

    void Monitor::unknown(int, string const &line)
    {
        cout << "unknown: " << line << "\n";
    }
