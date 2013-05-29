#ifndef INCLUDED_FORK_H_
#define INCLUDED_FORK_H_

namespace FBB
{
    class Redirector;
    class ChildProcess;
    class ParentProcess;

    class Fork
    {
        protected:
            Redirector      &d_redirector;
            ChildProcess    &d_child;
            ParentProcess   &d_parent;

        public:
            Fork(Redirector &redirector, ChildProcess &child,
                                         ParentProcess &parent)
            :
                d_redirector(redirector),
                d_child(child),
                d_parent(parent)
            {}

            void fork() const;

        private:
            Fork(Fork const &other);            // NI
            Fork &operator=(Fork const &other); // NI

    };
}

#endif
