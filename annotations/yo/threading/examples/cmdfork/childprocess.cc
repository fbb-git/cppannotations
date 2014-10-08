#include "cmdfork.ih"

void CmdFork::childProcess()
{
    vector<string> args;
    String::split(&args, d_command);

    char *const *argv = const_cast<char *const *>(String::argv(args));

    execv(argv[0], argv);

    throw Exception(errno) << " thrown exception " << errno;
}
