#ifndef INCLUDED_CHILDPROCESS_H_
#define INCLUDED_CHILDPROCESS_H_

namespace FBB
{
    class ChildProcess
    {
        public:
            virtual ~ChildProcess()
            {}
            void run();

        protected:
                                        // implemented in derived classes
            virtual void executeChildProcess() = 0;
    };
}

#endif
