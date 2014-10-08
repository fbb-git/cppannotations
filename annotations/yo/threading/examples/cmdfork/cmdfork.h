#ifndef INCLUDED_CMDFORK_
#define INCLUDED_CMDFORK_

#include <bobcat/fork>
#include <bobcat/pipe>

#include <string>

class CmdFork: public FBB::Fork
{
    FBB::Pipe d_childOutput;   // child writes this
    std::string d_command;
    int d_childExit = -1;
    
    public:
        CmdFork(std::string const &command);
        int childExit() const;
        std::string const &childOutput() const;

    private:
       void childRedirections() override;
       void childProcess()      override;
       void parentProcess()     override;
};
        
inline int CmdFork::childExit() const
{
    return d_childExit;
}

inline std::string const &CmdFork::childOutput() const
{
    return d_command;
}
#endif
