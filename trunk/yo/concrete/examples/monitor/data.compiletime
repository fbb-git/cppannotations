    #include "monitor.ih"
//HANDLER
    void (Monitor::*Monitor::s_handler[])(int, string const &)  =
    {
        &Monitor::unknown,              // order follows enum Command's
        &Monitor::createNewChild,       // elements
        &Monitor::exiting,
        &Monitor::stopChild,
        &Monitor::sendChild,
    };
//=
